//
//  STAppDelegate.h
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-02-22.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@class STPlayer, STSubtitleArray, SubRipItem;

@interface STAppDelegate : NSObject <NSApplicationDelegate, NSMenuDelegate> {
    NSMenu* _statusMenu;
    NSStatusItem* _statusItem;
    NSArray* _moviePlayers;
    
    NSTimer* _ttsTimer;
    STPlayer* _ttsCurrentPlayer;
    NSString* _ttsCurrentMovieName;
    STSubtitleArray* _loadedSubtitles;
    NSTimeInterval _ttsLatestCurrentTime;
    NSTimeInterval _ttsNextSubtitleTime;
    SubRipItem* _ttsNextSubtitle;
    SubRipItem* _ttsLastSpokenSubtitle;
}

- (void) openPreferences: (id)sender;
- (void) openAboutPanel: (id)sender;

- (BOOL) timerIsActive;
- (void) startTimer: (id)sender;
- (void) stopTimer: (id)sender;

- (void) menuNeedsUpdate: (NSMenu*)menu;


@end
