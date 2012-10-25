//
//  STMoviePlayer.h
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-02-26.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef id STMovie;

@interface STPlayer : NSObject 

- (NSString*) title;
- (NSString*) bundleID;
- (BOOL) isLaunched;
- (BOOL) isFrontmost;
- (void) bringToFront: (id)sender;

- (NSUInteger) numberOfMovies;
- (NSArray*) movies;
- (STMovie) movieAtIndex: (NSUInteger)nr;
- (STMovie) movieWithName: (NSString*)name;

- (NSString*) nameOfMovie: (STMovie)movie;
- (NSURL*) urlOfMovie: (STMovie)movie;
- (NSString*) pathOfMovie: (STMovie)movie;
- (NSTimeInterval) durationOfMovie: (STMovie)movie;
- (NSTimeInterval) currentTimeOfMovie: (STMovie)movie;
- (BOOL) isPlayingMovie: (STMovie)movie;
- (BOOL) isNormalSpeedMovie: (STMovie)movie;

- (void) pauseMovie: (STMovie)movie;
- (void) playMovie: (STMovie)movie;
- (void) bringMovieToFront: (STMovie)movie;

// TODO: method for finding matching SRT files

@end

// Protected method
@interface STPlayer ()

- (NSTimeInterval) extrapolateCurrentTime: (NSUInteger)currentSeconds 
                                isPlaying: (BOOL)isPlaying;

@end
