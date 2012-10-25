//
//  STMoviePlayer.m
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-02-26.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import "STPlayer.h"

@implementation STPlayer

- (NSString*) title { return nil; }
- (NSString*) bundleID { return nil; }

- (NSInteger) numberOfMovies { return 0; }
- (NSArray*) movies { return nil; }
- (id) movieAtIndex: (NSInteger)nr { return nil; }
- (id) movieWithName: (NSString*)name { return nil; }

- (NSString*) nameOfMovie: (id)movie { return nil; }
- (NSURL*) urlOfMovie: (id)movie { return nil; }
- (NSString*) pathOfMovie: (id)movie { return nil; }
- (NSTimeInterval) durationOfMovie: (id)movie { return 0; }
- (NSTimeInterval) currentTimeOfMovie: (id)movie { return 0; }
- (BOOL) isPlayingMovie: (id)movie { return NO; }
- (BOOL) isNormalSpeedMovie: (id)movie { return NO; }

- (void) pauseMovie: (id)movie {}
- (void) playMovie: (id)movie {}
- (void) bringMovieToFront: (id)movie {}

- (BOOL) isLaunched {
    NSArray *apps = [NSRunningApplication runningApplicationsWithBundleIdentifier: [self bundleID]];
    return [apps count] > 0;
}

- (BOOL) isFrontmost {
    NSArray *apps = [NSRunningApplication runningApplicationsWithBundleIdentifier: [self bundleID]];
    if ([apps count]) {
        NSRunningApplication *app = [apps objectAtIndex:0];
        return app.active;
    }
    return NO;
}

- (void) bringToFront: (id)sender {
    LOG(@"sender: %@", [sender title]);
    NSArray *apps = [NSRunningApplication runningApplicationsWithBundleIdentifier: [self bundleID]];
    if ([apps count]) {
        NSRunningApplication *app = [apps objectAtIndex:0];
        [app activateWithOptions: NSApplicationActivateIgnoringOtherApps];
        id movie = [self movieWithName: [sender title]];
        if (movie)
            [self bringMovieToFront:movie];
    }
}


// Private helper

// Some players only give currentTime as integers
// We guess the fraction by extrapolation from the previous invocation
- (NSTimeInterval) extrapolateCurrentTime: (NSInteger)currentSeconds
                                isPlaying: (BOOL)isPlaying 
{
    static NSTimeInterval lastTime = -1;
    static NSInteger lastSeconds = -1;
    static NSDate* lastInvocation;
    if (!lastInvocation) 
        lastInvocation = [NSDate dateWithTimeIntervalSinceReferenceDate:0];
    NSDate* currentInvocation = [NSDate date];
    NSTimeInterval timeSinceLastInvocation = [currentInvocation timeIntervalSinceDate: lastInvocation];
    NSTimeInterval currentTime = currentSeconds + 0.5;
    if (timeSinceLastInvocation < 0.5) {
        if (currentSeconds == lastSeconds) {
            if (isPlaying) 
                currentTime = fmin(lastTime + timeSinceLastInvocation, currentSeconds + 0.99);
            else 
                currentTime = lastTime;
        } else if (currentSeconds == lastSeconds + 1) {
            if (isPlaying) 
                currentTime = fmax(lastTime + timeSinceLastInvocation, currentSeconds);
            else 
                currentTime = currentSeconds;
        }
        // if (isPlaying) LOG(@"%2d..%2d: (%5.2f) %5.2f = %5.2f", lastSeconds, currentSeconds, 
        //                    timeSinceLastInvocation, lastTime + timeSinceLastInvocation, currentTime);
    }
    lastTime = currentTime;
    lastSeconds = currentSeconds;
    lastInvocation = currentInvocation;
    return currentTime;
}


@end
