//
//  STAppDelegate.h
//  SubTTS
//
//  Created by peter ljunglöf on 2012-02-22.
//  Copyright (c) 2012 göteborgs universtiet. All rights reserved.
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
