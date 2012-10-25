//
//  STVLCPlayer.m
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-02-26.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import "STVLCPlayer.h"
#import "VLC.h"

#define BundleID @"org.videolan.vlc"

@implementation STVLCPlayer

- (NSString*) title { 
    return @"VLC Player"; 
}

- (NSString*) bundleID { 
    return BundleID; 
}

#define HASMOVIE ([[self getPlayer] durationOfCurrentItem] > 0)

- (NSUInteger) numberOfMovies {
    if (HASMOVIE)
        return 1;
    else
        return 0;
}

- (NSArray*) movies { 
    static NSArray* emptyArray;
    static NSArray* unitArray;
    if (HASMOVIE) {
        if (!unitArray)
            unitArray = [NSArray arrayWithObject: [self getPlayer]];
        return unitArray;
    } else {
        if (!emptyArray)
            emptyArray = [NSArray array];
        return emptyArray;
    }
}

- (VLCApplication*) movieAtIndex: (NSUInteger)nr { 
    if (nr == 0 && HASMOVIE)
        return [self getPlayer];
    else 
        return nil;
}

- (VLCApplication*) movieWithName: (NSString*)name { 
    if ([name isEqualToString: [[self getPlayer] nameOfCurrentItem]])
        return [self getPlayer];
    else 
        return nil;
}

- (NSString*) nameOfMovie: (VLCApplication*)movie { 
    return [movie nameOfCurrentItem];
}

- (NSURL*) urlOfMovie: (VLCApplication*)movie {
    NSString* path = [movie pathOfCurrentItem]; 
    return path ? [NSURL fileURLWithPath:path] : nil;
}

- (NSString*) pathOfMovie: (VLCApplication*)movie {
    return [movie pathOfCurrentItem]; 
}

- (NSTimeInterval) durationOfMovie: (VLCApplication*)movie {
    return (NSTimeInterval) [movie durationOfCurrentItem];
}

// VLC only gives currentTime as integers
// We guess the fraction by extrapolation from the previous invocation
- (NSTimeInterval) currentTimeOfMovie: (VLCApplication*)movie {
    return [self extrapolateCurrentTime:[movie currentTime] isPlaying:[movie playing]];
}

- (BOOL) isPlayingMovie: (VLCApplication*)movie {
    return [movie playing];
}

- (BOOL) isNormalSpeedMovie: (VLCApplication*)movie {
    return YES;
}

- (void) pauseMovie: (VLCApplication*)movie {
    if ([movie playing])
        [self togglePlay];
}

- (void) playMovie: (VLCApplication*)movie {
    if (![movie playing]) 
        [self togglePlay];
}

////////////////////////////////////////////////
// Private methods

- (void) togglePlay {
    NSString* src = @"tell application \"VLC\" to play";
    NSAppleScript* script = [[NSAppleScript alloc] initWithSource:src];
    [script executeAndReturnError:nil];
}

- (VLCApplication*) getPlayer {
    static VLCApplication* player;
    if (!player)
        player = [SBApplication applicationWithBundleIdentifier:BundleID];
    return player;
}

@end
