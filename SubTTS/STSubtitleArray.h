//
//  STSubtitleArray.h
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-02-28.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <SubRip/SubRip.h>

@interface STSubtitleArray : SubRip 

- (instancetype)initWithURL:(NSURL*)url
                      error:(NSError**)error;

@end
