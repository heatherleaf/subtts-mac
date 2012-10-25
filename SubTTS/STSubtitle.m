//
//  STSubtitle.m
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Peter Ljunglöf on 2012-02-28.
//  Copyright (C) 2012 Peter Ljunglöf. All rights reserved.
//

#import "STSubtitle.h"

@implementation STSubtitle

@synthesize start, end, text, tts;

+ (STSubtitle*) subtitle: (NSString*)subtext
                   start: (NSTimeInterval)substart
                     end: (NSTimeInterval)subend 
{
    STSubtitle* sub = [STSubtitle new];
    sub.text = subtext;
    sub.start = substart;
    sub.end = subend;
    return sub;
}

- (void) speak {
    if (!tts) {
        tts = [NSSpeechSynthesizer new];
        // [tts setDelegate: self];
    }
    LOG(@"Starting speaking: %@", text);
    [tts startSpeakingString: text];
}

////////////////////////////////////////////////////////////////
// NSSpeechSynthesizer delegate methods

// - (void)speechSynthesizer: (NSSpeechSynthesizer*)sender
//             willSpeakWord: (NSRange)wordToSpeak
//                  ofString: (NSString*)text 

// - (void)speechSynthesizer: (NSSpeechSynthesizer*)sender
//         didFinishSpeaking: (BOOL)success
// {
//     if (success)
//         LOG(@"Finished speaking: %@", ttsText);
//     else 
//         WARN(@"TTS did not finish speaking: %@", ttsText);
// }

@end
