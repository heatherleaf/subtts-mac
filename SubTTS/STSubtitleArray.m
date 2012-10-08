//
//  STSubtitleArray.m
//  SubTTS
//
//  Created by peter ljunglöf on 2012-02-28.
//  Copyright (c) 2012 göteborgs universtiet. All rights reserved.
//

#import "STSubtitleArray.h"

@implementation STSubtitleArray

- (id) init {
    self = [super init];
    subtitles = [NSMutableArray array];
    initialSubtitle = [STSubtitle subtitle:[NSArray array] start:-MAXFLOAT end:-MAXFLOAT];
    finalSubtitle = [STSubtitle subtitle:[NSArray array] start:MAXFLOAT end:MAXFLOAT];
    return self;
}

- (NSUInteger) count {
    return [subtitles count];
}

- (STSubtitle*) subtitle: (NSUInteger)nr {
    if (nr >= [subtitles count]) 
        return finalSubtitle;
    else 
        return [subtitles objectAtIndex:nr];
}

- (NSUInteger) nextSubtitle: (NSTimeInterval)now {
    NSUInteger low = 0;
    NSUInteger high = [subtitles count];
    while (low < high) {
        STSubtitle* sub = [subtitles objectAtIndex:mid];
        NSUInteger mid = (low + high) / 2;
        if (now < sub.start) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

- (void) addSubtitle: (NSString*)text 
               start: (NSTimeInterval)start
                 end: (NSTimeInterval)end 
{
    [subtitles addObject: [STSubtitle subtitle:text start:start end:end]];
}

- (BOOL) loadFromURL: (NSURL*)url 
               error: (NSError**)error 
{
    NSStringEncoding encoding = [STSubtitleArray encodingOfFile: url];
    LOG(@"Trying encoding %lu for URL: %@", encoding, url);
    if ([self loadFromURL:url encoding:encoding error:error])
        return YES;
    if ([*error code] != NSFileReadInapplicableStringEncodingError)
        return NO;
    encoding = NSISOLatin1StringEncoding;
    LOG(@"Trying default encoding %lu for URL: %@", encoding, url);
    return [self loadFromURL:url encoding:encoding error:error];
}

- (BOOL) loadFromURL: (NSURL*)url
            encoding: (NSStringEncoding)encoding 
               error: (NSError**)error 
{
    NSString* string = [NSString stringWithContentsOfURL: url
                                                encoding: encoding
                                                   error: error];
    if (string) {
        NSMutableArray* subs = [self parseSubtitleString: string
                                                   error: error];
        if (subs) {
            subtitles = subs;
            return YES;
        } 
    }
    WARN(@"Error code %ld: %@", [*error code], [*error localizedFailureReason]);
    return NO;
}

+ (NSStringEncoding) encodingOfFile: (NSURL*)file {
    // We call the unix command "file" to get the file encoding:
    //   $ /usr/bin/file --brief --mime "filename.srt"
    //   text/plain; charset=utf-8
    NSTask* task = [NSTask new];
    [task setLaunchPath: @"/usr/bin/file"];
    [task setArguments: [NSArray arrayWithObjects: @"--brief", @"--mime", [file path], nil]];
    NSPipe* pipe = [NSPipe pipe];
    [task setStandardOutput: pipe];
    [task launch];
    NSData* data = [[pipe fileHandleForReading] readDataToEndOfFile];
    [task waitUntilExit];
    NSString* output = [[[NSString alloc] initWithData:data encoding:NSASCIIStringEncoding] 
                        stringByTrimmingCharactersInSet: [NSCharacterSet whitespaceAndNewlineCharacterSet]];

    LOG(@"Output from '%@': %@", [task launchPath], output);
    if ([output hasSuffix:@"=iso-8859-1"])
        return NSISOLatin1StringEncoding;
    else if ([output hasSuffix:@"=utf-8"])
        return NSUTF8StringEncoding;
    else if ([output hasSuffix:@"=us-ascii"])
        return NSASCIIStringEncoding;
    else if ([output hasSuffix:@"=iso-8859-2"])
        return NSISOLatin2StringEncoding;
    else if ([output hasSuffix:@"=utf-16be"])
        return NSUTF16BigEndianStringEncoding;
    else if ([output hasSuffix:@"=utf-16le"])
        return NSUTF16LittleEndianStringEncoding;
    WARN(@"Unrecogniezd output from '%@': %@", [task launchPath], output);
    return NO;
}


// Parsing Subtitles

#define SCANL(scanner,linenr) ([scanner scanString:@"\n" intoString:NULL] && (++linenr >= 0))
#define SCANS(scanner,str) [scanner scanString:str intoString:NULL]

- (NSMutableArray*) parseSubtitleString: (NSString*)subtitleString
                                  error: (NSError**)error
{
    subtitleString = [[subtitleString stringByReplacingOccurrencesOfString: @"\r\n" withString: @"\n"] 
                      stringByReplacingOccurrencesOfString: @"\r" withString: @"\n"];
    NSScanner *scanner = [NSScanner scannerWithString: subtitleString];
    [scanner setCharactersToBeSkipped: [NSCharacterSet whitespaceCharacterSet]];
    NSCharacterSet *decimals = [NSCharacterSet characterSetWithCharactersInString: @"0123456789.,"];
    NSMutableArray *subtits = [NSMutableArray array];
    NSMutableString *subtext;
    NSString *subtextline, *startSecond, *endSecond;
    int startHour, startMinute, endHour, endMinute, subtitleNr_, subtitleNr = 0;
    int lineNr = 1;
    while (SCANL(scanner,lineNr));
    while (! [scanner isAtEnd]) {
        subtitleNr++;
        BOOL ok = ([scanner scanInt:&subtitleNr_] && SCANL(scanner,lineNr) &&
                   [scanner scanInt:&startHour] && SCANS(scanner,@":") && 
                   [scanner scanInt:&startMinute] && SCANS(scanner,@":") &&
                   [scanner scanCharactersFromSet:decimals intoString:&startSecond] &&
                   SCANS(scanner,@"-->") &&
                   [scanner scanInt:&endHour] && SCANS(scanner,@":") && 
                   [scanner scanInt:&endMinute] && SCANS(scanner,@":") &&
                   [scanner scanCharactersFromSet:decimals intoString:&endSecond] &&
                   SCANL(scanner,lineNr) &&
                   [scanner scanUpToString:@"\n" intoString:&subtextline] && SCANL(scanner,lineNr)
                   );
        if (!ok) {
            int CONTEXT = 20;
            NSString *beforeError = [subtitleString substringToIndex: [scanner scanLocation]];
            if ([beforeError length] > CONTEXT) 
                beforeError = [beforeError substringFromIndex: [beforeError length]-CONTEXT];
            NSString *afterError = [subtitleString substringFromIndex: [scanner scanLocation]];
            if ([afterError length] > CONTEXT) 
                afterError = [afterError substringToIndex: CONTEXT];
            WARN(@"Parse error in subtitle nr %d (line %d):\n%@<HERE>%@", 
                  subtitleNr, lineNr, beforeError, afterError);
            *error = [[NSError alloc] initWithDomain: NSCocoaErrorDomain 
                                                code: NSFileReadCorruptFileError 
                                            userInfo: nil];
//            NSRunCriticalAlertPanel(@"Error in subtitle file", 
//                                    @"There was an error in subtitle nr %d (line %d):\n\n%@<HERE>%@", 
//                                    @"Dismiss", nil, nil, 
//                                    subtitleNr, lineNr, beforeError, afterError);
            return nil;
        }
        if (subtitleNr != subtitleNr_) {
            WARN(@"Subtitle nr mismatch (line %d): got %d, expected %d", lineNr, subtitleNr_, subtitleNr);
            subtitleNr = subtitleNr_;
        }
        subtext = [NSMutableString stringWithString:subtextline];
        while ([scanner scanUpToString: @"\n" intoString: &subtextline] && SCANL(scanner,lineNr)) {
            [subtext appendFormat:@" | %@", subtextline];
        }
        NSTimeInterval start = (startHour * 3600 + startMinute * 60 + 
                                [[startSecond stringByReplacingOccurrencesOfString:@"," withString:@"."] doubleValue]);
        NSTimeInterval end = (endHour * 3600 + endMinute * 60 + 
                              [[endSecond stringByReplacingOccurrencesOfString:@"," withString:@"."] doubleValue]);
        [subtits addObject: [STSubtitle subtitle:[self stripHtmlTags:subtext] start:start end:end]];
        while (SCANL(scanner,lineNr));
    }
    LOG(@"Read %d = %lu subtitles", subtitleNr, [subtits count]);
    STSubtitle* sub = [subtits objectAtIndex:0];
    LOG(@"FIRST: start=%.1f, end=%.1f, text='%@'", sub.start, sub.end, sub.text);
    sub = [subtits lastObject];
    LOG(@"LAST: start=%.1f, end=%.1f, text='%@'", sub.start, sub.end, sub.text);
    return subtits;
}

- (NSString*) stripHtmlTags: (NSString*)html {
    NSString *stripped = html;
    NSRange tag = [stripped rangeOfString:@"<"];
    while (tag.location != NSNotFound) {
        tag.length = [stripped length] - tag.location;
        NSRange end = [stripped rangeOfString:@">" options:0 range:tag];
        if (end.location != NSNotFound) {
            tag.length = 1 + end.location - tag.location;
        } else {
            tag.length = 1;
        }
        stripped = [stripped stringByReplacingCharactersInRange:tag withString:@" "];
        tag = [stripped rangeOfString:@"<"];
    }
    if (![stripped isEqualToString:html])
        LOG(@"STRIP: %@ --> %@", html, stripped);
    return stripped;
}

@end
