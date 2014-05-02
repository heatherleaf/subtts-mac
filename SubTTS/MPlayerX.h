/*
 * MPlayerX.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class MPlayerXApplication;

enum MPlayerXPlayerStatus {
	MPlayerXPlayerStatusPlaying = 'plin' /* Playing. */,
	MPlayerXPlayerStatusPaused = 'paus' /* Paused. */,
	MPlayerXPlayerStatusStopped = 'stpd' /* Stopped. */
};
typedef enum MPlayerXPlayerStatus MPlayerXPlayerStatus;



/*
 * Standard Suite
 */

@interface MPlayerXApplication : SBApplication

- (void) pause;  // Pause playback if it is playing, no affect if already paused.
- (void) play;  // Resume playback if it is paused, no affect if already playing.
- (void) playpause;  // Toggle between Play and Pause.
- (void) stop;  // Stop playback.
- (void) gotoNextEpisode;  // Try to jump to next episode.
- (void) gotoPreviousEpisode;  // Try to jump to previous episode.
- (void) mute;  // Toggle mute ON/OFF.
- (void) seekto:(double)x;  // Seek to given time position.
- (double) currentTime;  // Get current time position.
- (double) duration;  // Get the duration of the current media.
- (MPlayerXPlayerStatus) playstatus;  // .

@end

