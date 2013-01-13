//
//  STAppDelegate.m
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-02-22.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import "STAppDelegate.h"
#import "STQuickTimePlayer.h"
#import "STQuickTime7Player.h"
#import "STVLCPlayer.h"
#import "STDVDPlayer.h"

#import "STSubtitleArray.h"
#import "SubRipItem+SpeakText.h"

#import "QuickTimePlayer.h"
#define BundleID @"com.apple.QuickTimePlayerX"

@implementation STAppDelegate

- (void) awakeFromNib {
    _statusMenu = [NSMenu new];
    [_statusMenu setDelegate:self];

    _statusItem = [[NSStatusBar systemStatusBar] statusItemWithLength: NSVariableStatusItemLength];
    [_statusItem setMenu:_statusMenu];
    [_statusItem setTitle:NSLocalizedString(@"SubTTS", nil)];
    [_statusItem setHighlightMode:YES];

    _moviePlayers = [NSArray arrayWithObjects:
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

- (BOOL) timerIsActive {
    return _ttsTimer ? [_ttsTimer isValid] : NO;
}

- (void) startTimer: (id)sender {
    [self stopTimer: sender];
    STPlayer* player = [sender representedObject];
    STMovie movie = [player movieAtIndex:0];
    // [player setCurrentMovie:0];
    NSString* name = [player nameOfMovie:movie];
    if (! (player == _ttsCurrentPlayer && name == _ttsCurrentMovieName)) {
        _ttsCurrentPlayer = player;
        _ttsCurrentMovieName = name;
        BOOL ok = [self loadSubtitlesForCurrentMovie];
        if (!ok) {
            LOG(@"Resetting timer: SRT not found");
            [self resetTTS];
            return;
        }
        [self calculateNextSubtitle: [player currentTimeOfMovie:movie]];
    }
    LOG(@"Starting timer");
    _ttsTimer = [NSTimer scheduledTimerWithTimeInterval: TICK_INTERVAL
                                                target: self 
                                              selector: @selector(tickTimer:) 
                                              userInfo: nil 
                                               repeats: YES];
    [player playMovie:movie];
}

- (void) stopTimer: (id)sender {
    if (_ttsTimer) {
        LOG(@"Stopping timer");
        [_ttsTimer invalidate];
        STMovie movie = [_ttsCurrentPlayer movieWithName:_ttsCurrentMovieName];
        // [ttsCurrentPlayer setCurrentMovieName: _ttsCurrentMovieName];
        [_ttsCurrentPlayer pauseMovie: movie];
    }
}

- (void) resetTTS {
    LOG(@"Resetting timer");
    _loadedSubtitles = nil;
    _ttsCurrentPlayer = nil;
    _ttsCurrentMovieName = nil;
    [self stopTimer: nil];    
}

- (void) tickTimer: (id)sender {
    if (![_ttsCurrentPlayer isLaunched]) {
        WARN(@"Player %@ has quit: stopping", [_ttsCurrentPlayer title]);
        [self resetTTS];
        return;
    }
    STMovie movie = [_ttsCurrentPlayer movieWithName:_ttsCurrentMovieName];
    BOOL ok = movie && [_ttsCurrentMovieName isEqualToString:[_ttsCurrentPlayer nameOfMovie:movie]];
    if (!ok) {
        WARN(@"Couldn't find movie %@: stopping!", _ttsCurrentMovieName);
        [self resetTTS];
        return;
    } 
    if ([_ttsCurrentPlayer isPlayingMovie: movie]) {
        NSTimeInterval currentTime = [_ttsCurrentPlayer currentTimeOfMovie: movie];
        if (currentTime < _ttsLatestCurrentTime - MIN_SUBTITLE_INTERVAL ||
            currentTime > _ttsNextSubtitleTime + MIN_SUBTITLE_INTERVAL) {
            [self calculateNextSubtitle: currentTime];
        } else if (_ttsNextSubtitleIndex != _ttsLastSpokenSubtitle &&
                   currentTime > _ttsNextSubtitleTime - TICK_INTERVAL) {
            _ttsLastSpokenSubtitle = _ttsNextSubtitleIndex;
            NSTimeInterval diff = _ttsNextSubtitleTime - currentTime;
            if (diff > 0) usleep(diff * 1000000 / 2);
            [[_loadedSubtitles subRipItemAtIndex:_ttsNextSubtitleIndex] speak];
        }
        _ttsLatestCurrentTime = currentTime;
    }
}

- (void) calculateNextSubtitle: (NSTimeInterval)currentTime {
    NSUInteger newSubtitleIndex;
    SubRipItem *nextSub = [_loadedSubtitles nextSubRipItemForPointInTime:CMTimeMakeWithSeconds(currentTime, 1000) index:&newSubtitleIndex];
    _ttsNextSubtitleTime = nextSub.startTimeDouble;
    if (nextSub)  LOG(@"Next sub #%ld in %.1fs (%.1fs): %@", (unsigned long)newSubtitleIndex, _ttsNextSubtitleTime - currentTime, _ttsNextSubtitleTime,
        nextSub.text);
    _ttsNextSubtitleIndex = newSubtitleIndex;
}

- (BOOL) loadSubtitlesForCurrentMovie {
    STMovie movie = [_ttsCurrentPlayer movieWithName:_ttsCurrentMovieName];
    if (!movie) {
        WARN(@"Couldn't find movie %@: stopping!", _ttsCurrentMovieName);
        return NO;
    }
    LOG(@"Loading SRT for: %@", _ttsCurrentMovieName);
    NSURL* movieURL = [_ttsCurrentPlayer urlOfMovie: movie];
    NSError* error;
    NSURL* movieBaseURL = [movieURL URLByDeletingPathExtension];
    NSURL* movieDirectory = [movieURL URLByDeletingLastPathComponent];
    NSArray* urlsToTry = [NSArray arrayWithObjects:
                          [movieBaseURL URLByAppendingPathExtension:@"srt"],
                          [movieBaseURL URLByAppendingPathExtension:@"SRT"],
                          nil];
    for (NSURL* subtitleURL in urlsToTry) {
        LOG(@"Trying: %@", subtitleURL);
        _loadedSubtitles = [[STSubtitleArray alloc] initWithURL: subtitleURL
                                                         error: &error];
        if (_loadedSubtitles != nil) {
            return YES;
        }
        else {
            WARN(@"Error code %ld: %@", [error code], [error localizedFailureReason]);
            if ([error code] == NSFileReadCorruptFileError ||
                [error code] == NSFileReadInapplicableStringEncodingError) {
                NSRunCriticalAlertPanel(@"Error loading subtitles",
                                        @"Sorry, the subtitles could not be read",
                                        @"Dismiss", nil, nil);
                return NO;
            }
        }
    }
    NSOpenPanel* panel = [NSOpenPanel openPanel];
    [panel setDirectoryURL: movieDirectory];
    [panel setTitle: @"Locate subtitle file"];
    [panel setMessage:[NSString stringWithFormat:@"Locate subtitle file for the movie %@", _ttsCurrentMovieName]];
    [panel setAllowedFileTypes: [NSArray arrayWithObjects: @"srt", @"SRT", nil]];
    [panel setAllowsMultipleSelection: NO];
    BOOL isPlaying = [_ttsCurrentPlayer isPlayingMovie: movie];
    if (isPlaying) [_ttsCurrentPlayer pauseMovie: movie];
    NSInteger button = [panel runModal];
    if (button == NSFileHandlingPanelOKButton) {
        _loadedSubtitles = [[STSubtitleArray alloc] initWithURL: [panel URL]
                                                 error: &error];
        if (_loadedSubtitles != nil) {
            if (isPlaying) [_ttsCurrentPlayer playMovie: movie];
            return YES;
        }
        else {
            WARN(@"Error code %ld: %@", [error code], [error localizedFailureReason]);
            NSRunCriticalAlertPanel(@"Error loading subtitles",
                                    @"Sorry, I could not read the subtitles",
                                    @"Dismiss", nil, nil);
        }
    }
    if (isPlaying) [_ttsCurrentPlayer playMovie: movie];
    return NO;
}

///////////////////////////////////////////////////////////////////////////////////
// Menu 

- (void) addMenu: (NSMenu*)menu 
       forPlayer: (STPlayer*)player 
         atIndex: (NSUInteger)ix
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
        [startSpeaking setEnabled:NO];
        [stopSpeaking setEnabled:YES];
        [stopSpeaking setTitle:[NSString stringWithFormat:NSLocalizedString(@"Stop speaking %@", nil), _ttsCurrentMovieName]];
        [stopSpeaking setAction: @selector(stopTimer:)];
    }
    else {
        [startSpeaking setEnabled:YES];
        [stopSpeaking setEnabled:NO];
    }
    
    NSUInteger initial_items = [menu numberOfItems];
    NSUInteger nr;
    for (STPlayer* player in _moviePlayers) {
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
