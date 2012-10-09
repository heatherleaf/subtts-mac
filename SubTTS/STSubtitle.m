//
//  STSubtitle.m
//  SubTTS
//
//  Created by peter ljunglöf on 2012-02-28.
//  Copyright (c) 2012 göteborgs universtiet. All rights reserved.
//

#import "STSubtitle.h"

@implementation STSubtitle

@synthesize start, end, text;

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
	NSSpeechSynthesizer* tts = [NSSpeechSynthesizer new];
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
