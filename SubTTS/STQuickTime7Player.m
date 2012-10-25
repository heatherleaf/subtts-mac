//
//  STQuickTime7Player.m
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-03-04.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import "STQuickTime7Player.h"
#import "QuickTimePlayer7.h"

#define BundleID @"com.apple.quicktimeplayer"

@implementation STQuickTime7Player

- (NSString*) title { 
    return @"QuickTime Player 7"; 
}

- (NSString*) bundleID { 
    return BundleID; 
}

- (NSUInteger) numberOfMovies {
    return [[self getMovies] count];
}

- (NSArray*) movies { 
    return [self getMovies];
}

- (QuickTimePlayer7Document*) movieAtIndex: (NSUInteger)nr { 
    return [[self getMovies] objectAtIndex:nr];
}

- (QuickTimePlayer7Document*) movieWithName: (NSString*)name { 
    return [[self getMovies] objectWithName: name];    
}

- (NSString*) nameOfMovie: (QuickTimePlayer7Document*)movie { 
    return [movie name];
}

- (NSURL*) urlOfMovie: (QuickTimePlayer7Document*)movie { 
    return [movie originalFile];
}

- (NSString*) pathOfMovie: (QuickTimePlayer7Document*)movie { 
    return [[movie originalFile] path];
}

- (NSTimeInterval) durationOfMovie: (QuickTimePlayer7Document*)movie { 
    return [movie duration];
}

- (NSTimeInterval) currentTimeOfMovie: (QuickTimePlayer7Document*)movie {
    NSInteger currentTime = [movie currentTime];
    NSInteger timeScale = [movie timeScale];
    return ((NSTimeInterval)currentTime/timeScale);
}

- (BOOL) isPlayingMovie: (QuickTimePlayer7Document*)movie { 
    return [movie playing];
}

#define EPSILON_RATE 0.01

- (BOOL) isNormalSpeedMovie: (QuickTimePlayer7Document*)movie { 
    double rate = [movie rate];
    return fabs(rate - 1.0) < EPSILON_RATE; 
}

- (void) pauseMovie: (QuickTimePlayer7Document*)movie {
    [movie pause];
}

- (void) playMovie: (QuickTimePlayer7Document*)movie {
    [movie play];
}

- (void) bringMovieToFront: (QuickTimePlayer7Document*)movie {
    NSString* name = [movie name];
    QuickTimePlayer7Window* win = [[self getWindows] objectWithName: name];
    [win setIndex:0];
}

////////////////////////////////////////////////
// Private methods & variables

- (SBElementArray*) getMovies {
    static SBElementArray* movies;
    if (!movies) movies = [[self getPlayer] documents];
    return movies;
}

- (SBElementArray*) getWindows {
    static SBElementArray* windows;
    if (!windows) windows = [[self getPlayer] windows];
    return windows;
}

- (QuickTimePlayer7Application*) getPlayer {
    static QuickTimePlayer7Application* player;
    if (!player) player = [SBApplication applicationWithBundleIdentifier:BundleID];
    return player;
}

@end
