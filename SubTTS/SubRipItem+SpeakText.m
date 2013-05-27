//
//  SubRipItem+SpeakText.m
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Jan on 13.01.13.
//  Copyright (c) 2013 geheimwerk.de. All rights reserved.
//

#import "SubRipItem+SpeakText.h"

@implementation SubRipItem (SpeakText)

- (void)speak {
	NSSpeechSynthesizer* tts = [NSSpeechSynthesizer new];
    NSString *text = _attributedText.string;
    LOG(@"Starting speaking: \n%@", text);
    [tts startSpeakingString: text];
}

@end
