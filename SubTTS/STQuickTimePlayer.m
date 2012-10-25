//
//  STQuickTimePlayer.m
//  SubTTS
//
//  Created by peter ljunglöf on 2012-02-26.
//  Copyright (c) 2012 göteborgs universtiet. All rights reserved.
//

#import "STQuickTimePlayer.h"
#import "QuickTimePlayer.h"

#define BundleID @"com.apple.QuickTimePlayerX"

@implementation STQuickTimePlayer

- (NSString*) title { 
    return @"QuickTime Player"; 
}

- (NSString*) bundleID { 
    return BundleID; 
}

- (int) numberOfMovies {
    return [[self getMovies] count];
}

- (NSArray*) movies { 
    return [self getMovies];
}

- (QuickTimePlayerDocument*) movieAtIndex: (int)nr { 
    return [[self getMovies] objectAtIndex:nr];
}

- (QuickTimePlayerDocument*) movieWithName: (NSString*)name { 
    return [[self getMovies] objectWithName: name];    
}

- (NSString*) nameOfMovie: (QuickTimePlayerDocument*)movie { 
    return [movie name];
}

- (NSURL*) urlOfMovie: (QuickTimePlayerDocument*)movie { 
    return [movie file];
}

- (NSString*) pathOfMovie: (QuickTimePlayerDocument*)movie { 
    return [[movie file] path];
}

- (NSTimeInterval) durationOfMovie: (QuickTimePlayerDocument*)movie { 
    return [movie duration];
}

- (NSTimeInterval) currentTimeOfMovie: (QuickTimePlayerDocument*)movie { 
    return [movie currentTime];
}

- (BOOL) isPlayingMovie: (QuickTimePlayerDocument*)movie { 
    return [movie playing];
}

#define EPSILON_RATE 0.01

- (BOOL) isNormalSpeedMovie: (QuickTimePlayerDocument*)movie { 
    double rate = [movie rate];
    return fabs(rate - 1.0) < EPSILON_RATE; 
}

- (void) pauseMovie: (QuickTimePlayerDocument*)movie {
    [movie pause];
}

- (void) playMovie: (QuickTimePlayerDocument*)movie {
    [movie play];
}

- (void) bringMovieToFront: (QuickTimePlayerDocument*)movie {
    NSString* name = [movie name];
    QuickTimePlayerWindow* win = [[self getWindows] objectWithName: name];
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

- (QuickTimePlayerApplication*) getPlayer {
    static QuickTimePlayerApplication* player;
    if (!player) player = [SBApplication applicationWithBundleIdentifier:BundleID];
    return player;
}

@end
