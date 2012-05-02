//
//  STAppDelegate.m
//  SubTTS
//
//  Created by peter ljunglöf on 2012-02-22.
//  Copyright (c) 2012 göteborgs universtiet. All rights reserved.
//

#import "STAppDelegate.h"
#import "STQuickTimePlayer.h"
#import "STQuickTime7Player.h"
#import "STVLCPlayer.h"
#import "STDVDPlayer.h"
#import "STSubtitleArray.h"

#import "QuickTimePlayer.h"
#define BundleID @"com.apple.QuickTimePlayerX"

@implementation STAppDelegate

- (void) awakeFromNib {
    statusMenu = [NSMenu new];
    [statusMenu setDelegate: self];

    statusItem = [[NSStatusBar systemStatusBar] statusItemWithLength: NSVariableStatusItemLength];
    [statusItem setMenu: statusMenu];
    [statusItem setTitle: NSLocalizedString(@"SubTTS", nil)];
    [statusItem setHighlightMode: YES];

    moviePlayers = [NSArray arrayWithObjects:
                    [STQuickTimePlayer new],
                    [STQuickTime7Player new],
                    [STVLCPlayer new],
                    [STDVDPlayer new],
                    nil];
}

- (void) openPreferences: (id)sender {
    [[NSWorkspace sharedWorkspace] openFile: @"/System/Library/PreferencePanes/Speech.prefPane"];
}

- (void) openAboutPanel: (id)sender {
    [NSApp orderFrontStandardAboutPanelWithOptions: nil];
    /*
     The following strings are keys that can occur in optionsDictionary:
     @"Credits": An NSAttributedString displayed in the info area of the panel. If not specified, this method then looks for a file named “Credits.html”, “Credits.rtf”, and “Credits.rtfd”, in that order, in the bundle returned by the NSBundle class method mainBundle. The first file found is used. If none is found, the info area is left blank.
     @"ApplicationName": An NSString object displayed as the application’s name. If not specified, this method then uses the value of CFBundleName (localizable). If neither is found, this method uses [[NSProcessInfo processInfo] processName].
     @"ApplicationIcon": An NSImage object displayed as the application’s icon. If not specified, this method then looks for an image named “NSApplicationIcon”, using [NSImage imageNamed:@"NSApplicationIcon"]. If neither is available, this method uses the generic application icon.
     @"Version": An NSString object with the build version number of the application (“58.4”), displayed as “(v58.4)”. If not specified, obtain from the CFBundleVersion key in infoDictionary; if not specified, leave blank (the “(v)” is not displayed).
     @"Copyright": An NSString object with a line of copyright information. If not specified, this method then looks for the value of NSHumanReadableCopyright in the localized version infoDictionary. If neither is available, this method leaves the space blank.
     @"ApplicationVersion": An NSString object with the application version (“Mac OS X”, “3”, “WebObjects 4.5”, “AppleWorks 6”,...). If not specified, obtain from the CFBundleShortVersionString key in infoDictionary. If neither is available, the build version, if available, is printed alone, as “Version x.x”.
     */
}

///////////////////////////////////////////////////////////////////////////////////
// Timer

#define TICK_INTERVAL 0.2
#define MIN_SUBTITLE_INTERVAL 1.0

NSTimer* ttsTimer;
STPlayer* ttsCurrentPlayer;
NSString* ttsCurrentMovieName;
STSubtitleArray* loadedSubtitles;
NSTimeInterval ttsLatestCurrentTime;
NSTimeInterval ttsNextSubtitleTime;
int ttsNextSubtitle;
int ttsLastSpokenSubtitle;

- (BOOL) timerIsActive {
    return ttsTimer ? [ttsTimer isValid] : NO;
}

- (void) startTimer: (id)sender {
    [self stopTimer: sender];
    STPlayer* player = [sender representedObject];
    STMovie movie = [player movieAtIndex:0];
    // [player setCurrentMovie:0];
    NSString* name = [player nameOfMovie:movie];
    if (! (player == ttsCurrentPlayer && name == ttsCurrentMovieName)) {
        ttsCurrentPlayer = player;
        ttsCurrentMovieName = name;
        BOOL ok = [self loadSubtitlesForCurrentMovie];
        if (!ok) {
            LOG(@"Resetting timer: SRT not found");
            [self resetTTS];
            return;
        }
        [self calculateNextSubtitle: [player currentTimeOfMovie:movie]];
    }
    LOG(@"Starting timer");
    ttsTimer = [NSTimer scheduledTimerWithTimeInterval: TICK_INTERVAL
                                                target: self 
                                              selector: @selector(tickTimer:) 
                                              userInfo: nil 
                                               repeats: YES];
    [player playMovie:movie];
}

- (void) stopTimer: (id)sender {
    if (ttsTimer) {
        LOG(@"Stopping timer");
        [ttsTimer invalidate];
        STMovie movie = [ttsCurrentPlayer movieWithName: ttsCurrentMovieName];
        // [ttsCurrentPlayer setCurrentMovieName: ttsCurrentMovieName];
        [ttsCurrentPlayer pauseMovie: movie];
    }
}

- (void) resetTTS {
    LOG(@"Resetting timer");
    loadedSubtitles = nil;
    ttsCurrentPlayer = nil;
    ttsCurrentMovieName = nil;
    [self stopTimer: nil];    
}

- (void) tickTimer: (id)sender {
    if (![ttsCurrentPlayer isLaunched]) {
        WARN(@"Player %@ has quit: stopping", [ttsCurrentPlayer title]);
        [self resetTTS];
        return;
    }
    STMovie movie = [ttsCurrentPlayer movieWithName: ttsCurrentMovieName];
    BOOL ok = movie && [ttsCurrentMovieName isEqualToString: [ttsCurrentPlayer nameOfMovie: movie]];
    if (!ok) {
        WARN(@"Couldn't find movie %@: stopping!", ttsCurrentMovieName);
        [self resetTTS];
        return;
    } 
    if ([ttsCurrentPlayer isPlayingMovie: movie]) {
        NSTimeInterval currentTime = [ttsCurrentPlayer currentTimeOfMovie: movie];
        if (currentTime < ttsLatestCurrentTime - MIN_SUBTITLE_INTERVAL || 
            currentTime > ttsNextSubtitleTime + MIN_SUBTITLE_INTERVAL) {
            [self calculateNextSubtitle: currentTime];
        } else if (ttsNextSubtitle != ttsLastSpokenSubtitle && 
                   currentTime > ttsNextSubtitleTime - TICK_INTERVAL) {
            ttsLastSpokenSubtitle = ttsNextSubtitle;
            NSTimeInterval diff = ttsNextSubtitleTime - currentTime;
            if (diff > 0) usleep(diff * 1000000 / 2);
            [[loadedSubtitles subtitle:ttsNextSubtitle] speak];
        }
        ttsLatestCurrentTime = currentTime;
    }
}

- (void) calculateNextSubtitle: (NSTimeInterval)currentTime {
    int newSubtitle = [loadedSubtitles nextSubtitle:currentTime];
    ttsNextSubtitleTime = [[loadedSubtitles subtitle:newSubtitle] start];
    LOG(@"Next sub #%d in %.1fs (%.1fs): %@", newSubtitle, ttsNextSubtitleTime - currentTime, ttsNextSubtitleTime, 
        [[loadedSubtitles subtitle:newSubtitle] text]);
    ttsNextSubtitle = newSubtitle;
}

- (BOOL) loadSubtitlesForCurrentMovie {
    STMovie movie = [ttsCurrentPlayer movieWithName: ttsCurrentMovieName];
    if (!movie) {
        WARN(@"Couldn't find movie %@: stopping!", ttsCurrentMovieName);
        return NO;
    }
    LOG(@"Loading SRT for: %@", ttsCurrentMovieName);
    if (!loadedSubtitles)
        loadedSubtitles = [STSubtitleArray new];
    NSURL* movieURL = [ttsCurrentPlayer urlOfMovie: movie];
    NSError* error;
    NSURL* movieBaseURL = [movieURL URLByDeletingPathExtension];
    NSURL* movieDirectory = [movieURL URLByDeletingLastPathComponent];
    NSArray* urlsToTry = [NSArray arrayWithObjects:
                          [movieBaseURL URLByAppendingPathExtension:@"srt"],
                          [movieBaseURL URLByAppendingPathExtension:@"SRT"],
                          nil];
    for (NSURL* subtitleURL in urlsToTry) {
        LOG(@"Trying: %@", subtitleURL);
        BOOL ok = [loadedSubtitles loadFromURL: subtitleURL
                                         error: &error];
        if (ok) 
            return YES;
        WARN(@"Error code %ld: %@", [error code], [error localizedFailureReason]);
        if ([error code] == NSFileReadCorruptFileError ||
            [error code] == NSFileReadInapplicableStringEncodingError) {
            NSRunCriticalAlertPanel(@"Error loading subtitles", 
                                    @"Sorry, I could not read the subtitles", 
                                    @"Dismiss", nil, nil);
            return NO;
        }
    }
    NSOpenPanel* panel = [NSOpenPanel openPanel];
    [panel setDirectoryURL: movieDirectory];
    [panel setTitle: @"Locate subtitle file"];
    [panel setMessage: [NSString stringWithFormat:@"Locate subtitle file for the movie %@", ttsCurrentMovieName]];
    [panel setAllowedFileTypes: [NSArray arrayWithObjects: @"srt", @"SRT", nil]];
    [panel setAllowsMultipleSelection: NO];
    BOOL isPlaying = [ttsCurrentPlayer isPlayingMovie: movie];
    if (isPlaying) [ttsCurrentPlayer pauseMovie: movie];
    NSInteger button = [panel runModal];
    if (button == NSFileHandlingPanelOKButton) {
        BOOL ok = [loadedSubtitles loadFromURL: [panel URL]
                                         error: &error];
        if (ok) {
            if (isPlaying) [ttsCurrentPlayer playMovie: movie];
            return YES;
        }
        WARN(@"Error code %ld: %@", [error code], [error localizedFailureReason]);
        NSRunCriticalAlertPanel(@"Error loading subtitles", 
                                @"Sorry, I could not read the subtitles", 
                                @"Dismiss", nil, nil);
    }
    if (isPlaying) [ttsCurrentPlayer playMovie: movie];
    return NO;
}

///////////////////////////////////////////////////////////////////////////////////
// Menu 

- (void) addMenu: (NSMenu*)menu 
       forPlayer: (STPlayer*)player 
         atIndex: (int)ix 
{
    NSMenuItem* playerItem = [NSMenuItem new];
    [playerItem setState: ([player isFrontmost] ? NSOnState : NSOffState)];
    [playerItem setTitle: [player title]];
    [playerItem setTarget: player];
    [playerItem setAction: @selector(bringToFront:)];
    [menu insertItem: playerItem atIndex: ix++];
    for (STMovie movie in [player movies]) {
        NSMenuItem* item = [NSMenuItem new];
        [item setIndentationLevel:1];
        [item setOnStateImage: [NSImage imageNamed: NSImageNameRightFacingTriangleTemplate]];
        [item setState: ([player isPlayingMovie:movie] ? NSOnState : NSOffState)];
        [item setTitle: [player nameOfMovie:movie]];
        [item setTarget: player];
        [item setAction: @selector(bringToFront:)];
        [menu insertItem: item atIndex: ix++];
    }
    [menu insertItem: [NSMenuItem separatorItem] atIndex: ix++];
}

- (void) menuNeedsUpdate: (NSMenu*)menu {
    LOG(@"");
    [menu removeAllItems];
    NSMenuItem* startSpeaking = [menu addItemWithTitle: NSLocalizedString(@"Start speaking",nil)
                                                action: NULL
                                         keyEquivalent: @""];
    NSMenuItem* stopSpeaking = [menu addItemWithTitle: NSLocalizedString(@"Stop speaking",nil)
                                               action: NULL 
                                        keyEquivalent: @""];
    [menu addItem: [NSMenuItem separatorItem]];

    BOOL isSpeaking = [self timerIsActive];
    if (isSpeaking) {
        [stopSpeaking setTitle: [NSString stringWithFormat: NSLocalizedString(@"Stop speaking %@",nil), ttsCurrentMovieName]];
        [stopSpeaking setAction: @selector(stopTimer:)];
    }
    
    int initial_items = [menu numberOfItems];
    int nr;
    for (STPlayer* player in moviePlayers) {
        if ([player isLaunched]) {
            if ([player isFrontmost]) {
                nr = initial_items; 
                if ([player numberOfMovies] > 0) {
                    STMovie movie = [player movieAtIndex: 0];
                    NSString* movieName = [player nameOfMovie: movie];
                    [startSpeaking setTitle: [NSString stringWithFormat: NSLocalizedString(@"Start speaking %@",nil), movieName]];
                    [startSpeaking setAction: @selector(startTimer:)];
                    [startSpeaking setRepresentedObject: player];
                }
            } else {
                nr = [menu numberOfItems];
            }
            [self addMenu:menu forPlayer:player atIndex:nr];
        }
    }

    [menu addItemWithTitle: NSLocalizedString(@"About SubTTS", nil)
                    action: @selector(openAboutPanel:) 
             keyEquivalent: @""];
    [menu addItemWithTitle: NSLocalizedString(@"Preferences", nil)
                    action: @selector(openPreferences:) 
             keyEquivalent: @""];
    [menu addItem: [NSMenuItem separatorItem]];
    [menu addItemWithTitle: NSLocalizedString(@"Quit", nil)
                    action: @selector(terminate:) 
             keyEquivalent: @""];
}

@end
