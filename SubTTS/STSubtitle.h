//
//  STSubtitle.h
//  SubTTS
//
//  Created by peter ljunglöf on 2012-02-28.
//  Copyright (c) 2012 göteborgs universtiet. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface STSubtitle : NSObject <NSSpeechSynthesizerDelegate> {
    NSTimeInterval start;
    NSTimeInterval end;
    NSString* text;
}

+ (STSubtitle*) subtitle: (NSString*)subtext 
                   start: (NSTimeInterval)substart 
                     end: (NSTimeInterval)subend;

@property NSTimeInterval start;
@property NSTimeInterval end;
@property NSString* text;

- (void) speak;

////////////////////////////////////////////////////////////////
// NSSpeechSynthesizer delegate methods

// - (void) speechSynthesizer: (NSSpeechSynthesizer*)sender
//              willSpeakWord: (NSRange)wordToSpeak
//                   ofString: (NSString*)text;

// - (void)speechSynthesizer: (NSSpeechSynthesizer*)sender
//         didFinishSpeaking: (BOOL)success;

@end
