//
//  STDVDPlayer.m
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-03-04.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import "STDVDPlayer.h"
#import "DVDPlayer.h"

#define BundleID @"com.apple.DVDPlayer"

@implementation STDVDPlayer

- (NSString*) title { 
    return @"DVD Player"; 
}

- (NSString*) bundleID { 
    return BundleID; 
}

#define HASMOVIE ([[self getPlayer] hasMedia])

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

- (DVDPlayerApplication*) movieAtIndex: (NSUInteger)nr { 
    if (nr == 0 && HASMOVIE)
        return [self getPlayer];
    else 
        return nil;
}

- (DVDPlayerApplication*) movieWithName: (NSString*)name { 
    if ([name isEqualToString: [self nameOfMovie:[self getPlayer]]])
        return [self getPlayer];
    else 
        return nil;
}

- (NSString*) nameOfMovie: (DVDPlayerApplication*)movie { 
    NSString* path = [self dvdVolumeForMovie:movie];
    return path ? [self nameFromPath:path] : @"Unknown DVD Movie";
}

- (NSString*) nameFromPath: (NSString*)path {
    return [[[path lastPathComponent] stringByReplacingOccurrencesOfString:@"_" withString:@" "] capitalizedString];
}

- (NSURL*) urlOfMovie: (DVDPlayerApplication*)movie {
    NSString* path = [self pathOfMovie:movie]; 
    return path ? [NSURL fileURLWithPath:path] : nil;
}

- (NSString*) pathOfMovie: (DVDPlayerApplication*)movie {
    NSString* path = [self dvdVolumeForMovie:movie];
    if (path) 
        return path;
    NSFileManager* fileManager = [NSFileManager defaultManager];
    NSURL* url = [fileManager URLForDirectory:NSUserDirectory inDomain:NSUserDomainMask appropriateForURL:nil create:NO error:nil];
    return [url path];
}

- (NSString*) dvdVolumeForMovie: (DVDPlayerApplication*)movie {
    static NSString* dvdVolume;
    BOOL isDir;
    NSFileManager* fileManager = [NSFileManager defaultManager];
    if (dvdVolume && [fileManager fileExistsAtPath:dvdVolume isDirectory:&isDir] && isDir) {
        return dvdVolume;
    } else {
        NSArray *volumes = [[NSWorkspace sharedWorkspace] mountedRemovableMedia];
        for (NSString* path in volumes) {
            NSString* video_ts = [path stringByAppendingPathComponent: @"VIDEO_TS"];
            if ([fileManager fileExistsAtPath:video_ts isDirectory:&isDir] && isDir) {
                dvdVolume = path;
                return dvdVolume;
            }
        }
        dvdVolume = nil;
        return dvdVolume;
    }
}

- (NSTimeInterval) durationOfMovie: (DVDPlayerApplication*)movie {
    return (NSTimeInterval) [movie titleLength];
}

#define FRAMES_PER_SECOND 25

- (NSTimeInterval) currentTimeOfMovie: (DVDPlayerApplication*)movie {
    NSPoint extime = [movie elapsedExtendedTime];
    return extime.x + extime.y / FRAMES_PER_SECOND;
}

- (BOOL) isPlayingMovie: (DVDPlayerApplication*)movie {
    return [movie dvdState] == DVDPlayerEstaPlaying;
}

- (BOOL) isNormalSpeedMovie: (DVDPlayerApplication*)movie {
    return [movie dvdState] == DVDPlayerEstaPlaying;
}

- (void) pauseMovie: (DVDPlayerApplication*)movie {
    [movie pauseDvd];
}

- (void) playMovie: (DVDPlayerApplication*)movie {
    [movie playDvd];
}

////////////////////////////////////////////////
// Private methods

- (DVDPlayerApplication*) getPlayer {
    static DVDPlayerApplication* player;
    if (!player)
        player = [SBApplication applicationWithBundleIdentifier:BundleID];
    return player;
}

@end
