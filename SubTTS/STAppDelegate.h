//
//  STAppDelegate.h
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-02-22.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface STAppDelegate : NSObject <NSApplicationDelegate, NSMenuDelegate> {
    NSMenu* statusMenu;
    NSStatusItem* statusItem;
    NSArray* moviePlayers;
}

- (void) openPreferences: (id)sender;
- (void) openAboutPanel: (id)sender;

- (BOOL) timerIsActive;
- (void) startTimer: (id)sender;
- (void) stopTimer: (id)sender;

- (void) menuNeedsUpdate: (NSMenu*)menu;


@end
