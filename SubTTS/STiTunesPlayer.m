//
//  STiTunesPlayer.m
//  SubTTS
//
//  Created by Boris Dušek on 5/1/14.
//
//

#import "STiTunesPlayer.h"
#import "iTunes.h"

#define BundleID @"com.apple.iTunes"

@interface STiTunesPlayer ()
@property (nonatomic, readonly) iTunesApplication* player;
@end

@implementation STiTunesPlayer

- (NSString*) title {
    return @"iTunes";
}

- (NSString*) bundleID {
    return BundleID;
}

#define HASMOVIE (self.player.currentTrack.databaseID != 0)

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
            unitArray = [NSArray arrayWithObject: self.player.currentTrack];
        return unitArray;
    } else {
        if (!emptyArray)
            emptyArray = [NSArray array];
        return emptyArray;
    }
}

- (iTunesTrack*) movieAtIndex: (NSUInteger)nr {
    if (nr == 0 && HASMOVIE)
        return self.player.currentTrack;
    else
        return nil;
}

- (iTunesTrack*) movieWithName: (NSString*)name {
    iTunesTrack *movie = self.player.currentTrack;
    if ([name isEqualToString:movie.name])
        return movie;
    else
        return nil;
}

- (NSString*) nameOfMovie: (iTunesTrack*)movie {
    return movie.name;
}

- (NSURL*) urlOfMovie: (iTunesTrack*)movie {
    return nil;
}

- (NSString*) pathOfMovie: (iTunesTrack*)movie {
    return nil;
}

- (NSTimeInterval) durationOfMovie: (iTunesTrack*)movie {
    return (NSTimeInterval) movie.duration;
}

// VLC only gives currentTime as integers
// We guess the fraction by extrapolation from the previous invocation
- (NSTimeInterval) currentTimeOfMovie: (iTunesTrack*)movie {
    if (movie.databaseID != self.player.currentTrack.databaseID)
        return 0;
    return [self extrapolateCurrentTime:self.player.playerPosition isPlaying:self.player.playerState == iTunesEPlSPlaying];
}

- (BOOL) isPlayingMovie: (iTunesTrack*)movie {
    return movie.databaseID == self.player.currentTrack.databaseID && self.player.playerState == iTunesEPlSPlaying;
}

- (BOOL) isNormalSpeedMovie: (iTunesTrack*)movie {
    if (movie.databaseID != self.player.currentTrack.databaseID)
        return YES;
    return self.player.playerState != iTunesEPlSFastForwarding && self.player.playerState != iTunesEPlSRewinding;
}

- (void) pauseMovie: (iTunesTrack*)movie {
    if (movie.databaseID == self.player.currentTrack.databaseID)
        [self.player pause];
}

- (void) playMovie: (iTunesTrack*)movie {
    if (movie.databaseID == self.player.currentTrack.databaseID)
        [self.player playOnce:YES];
}

////////////////////////////////////////////////
// Private methods

- (iTunesApplication*) player {
    static iTunesApplication* player;
    if (!player)
        player = [SBApplication applicationWithBundleIdentifier:BundleID];
    return player;
}

@end
