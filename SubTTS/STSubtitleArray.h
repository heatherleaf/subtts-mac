//
//  STSubtitleArray.h
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-02-28.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "STSubtitle.h"

@interface STSubtitleArray : NSObject {
    NSMutableArray* subtitles;
    STSubtitle* initialSubtitle;
    STSubtitle* finalSubtitle;
}

- (NSInteger) count;
- (STSubtitle*) subtitle: (NSInteger)nr;
- (NSInteger) nextSubtitle: (NSTimeInterval)now;

- (void) addSubtitle: (NSString*)text 
               start: (NSTimeInterval)start
                 end: (NSTimeInterval)end;

- (BOOL) loadFromURL: (NSURL*)url 
               error: (NSError**)error;

- (BOOL) loadFromURL: (NSURL*)url
            encoding: (NSStringEncoding)encoding 
               error: (NSError**)error;

+ (NSStringEncoding) encodingOfFile: (NSURL*)file;

@end
