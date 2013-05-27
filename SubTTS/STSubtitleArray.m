//
//  STSubtitleArray.m
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-02-28.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import "STSubtitleArray.h"

#import <UniversalDetector/UniversalDetector.h>

@implementation STSubtitleArray

- (instancetype)initWithURL:(NSURL *)url
                      error:(NSError **)error
{
    NSStringEncoding encoding;
    
    NSData *data = [NSData dataWithContentsOfURL:url];
    
    // Guess encoding
	UniversalDetector *detector = [UniversalDetector new];
    [detector analyzeData:data];
    encoding = [detector encoding];
    
#if 1 && DEBUG
    CFStringEncoding cfStringEncoding = CFStringConvertNSStringEncodingToEncoding(encoding);
    CFStringRef cfStringEncodingName =  CFStringGetNameOfEncoding(cfStringEncoding);
    NSString *encodingName = (__bridge NSString *)cfStringEncodingName;
    float confidence = [detector confidence] * 100.0f;
    LOG(@"Used encoding %@ with confidence: %.1f%% for URL: %@", encodingName, confidence, url);
#endif

    self = [self initWithURL:url
             encoding:encoding
                error:error];
    
    [self parseTags];
    
    return self;
}

@end
