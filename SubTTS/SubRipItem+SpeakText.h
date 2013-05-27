//
//  SubRipItem+SpeakText.h
//  Part of SubTTS: Subtitles-to-speech
//
//  Created by Jan on 13.01.13.
//  Copyright (c) 2013 geheimwerk.de. All rights reserved.
//

#import <SubRip/SubRip.h>

@interface SubRipItem (SpeakText) <NSSpeechSynthesizerDelegate>

- (void) speak;

@end
