//
//  STMoviePlayer.h
//  SubTTS
//
//  Created by peter ljunglöf on 2012-02-26.
//  Copyright (c) 2012 göteborgs universtiet. All rights reserved.
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
