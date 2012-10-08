//
//  STSubtitleArray.h
//  SubTTS
//
//  Created by peter ljunglöf on 2012-02-28.
//  Copyright (c) 2012 göteborgs universtiet. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "STSubtitle.h"

@interface STSubtitleArray : NSObject {
    NSMutableArray* subtitles;
    STSubtitle* initialSubtitle;
    STSubtitle* finalSubtitle;
}

- (NSUInteger) count;
- (STSubtitle*) subtitleAtIndex: (NSUInteger)nr;
- (NSUInteger) nextSubtitle: (NSTimeInterval)now;

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
