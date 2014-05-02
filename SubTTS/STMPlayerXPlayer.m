//
//  STMPlayerXPlayer.m
//  SubTTS
//
//  Created by Boris Dušek on 5/2/14.
//
//

#import "STMPlayerXPlayer.h"
#import "MPlayerX.h"

#define BundleID @"org.niltsh.MPlayerX"

@interface STMPlayerXPlayer ()
@property (nonatomic, readonly) MPlayerXApplication* player;
@end

@implementation STMPlayerXPlayer

- (NSString*) title {
    return @"MPlayerX";
}

- (NSString*) bundleID {
    return BundleID;
}

#define HASMOVIE (self.player.playstatus != MPlayerXPlayerStatusStopped)

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
            unitArray = [NSArray arrayWithObject: self.player];
        return unitArray;
    } else {
        if (!emptyArray)
            emptyArray = [NSArray array];
        return emptyArray;
    }
}

- (MPlayerXApplication*) movieAtIndex: (NSUInteger)nr {
    if (nr == 0 && HASMOVIE)
        return self.player;
    else
        return nil;
}

- (MPlayerXApplication*) movieWithName: (NSString*)name {
    if ([[self nameOfMovie:self.player] isEqualToString:name])
        return self.player;
    else
        return nil;
}

- (NSString*) nameOfMovie: (MPlayerXApplication*)movie {
    return @"Some Movie"; //TODO
}

- (NSURL*) urlOfMovie: (MPlayerXApplication*)movie {
    return nil;
}

- (NSString*) pathOfMovie: (MPlayerXApplication*)movie {
    return nil;
}

- (NSTimeInterval) durationOfMovie: (MPlayerXApplication*)movie {
    return (NSTimeInterval) movie.duration;
}

// VLC only gives currentTime as integers
// We guess the fraction by extrapolation from the previous invocation
- (NSTimeInterval) currentTimeOfMovie: (MPlayerXApplication*)movie {
    return movie.currentTime;
}

- (BOOL) isPlayingMovie: (MPlayerXApplication*)movie {
    return movie.playstatus == MPlayerXPlayerStatusPlaying;
}

- (BOOL) isNormalSpeedMovie: (MPlayerXApplication*)movie {
    return YES;
}

- (void) pauseMovie: (MPlayerXApplication*)movie {
    [movie pause];
}

- (void) playMovie: (MPlayerXApplication*)movie {
    [movie play];
}

////////////////////////////////////////////////
// Private methods

- (MPlayerXApplication*) player {
    static MPlayerXApplication* player;
    if (!player)
        player = [SBApplication applicationWithBundleIdentifier:BundleID];
    return player;
}

@end
