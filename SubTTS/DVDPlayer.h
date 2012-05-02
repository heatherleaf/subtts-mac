/*
 * DVDPlayer.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class DVDPlayerApplication;

enum DVDPlayerEgto {
	DVDPlayerEgtoToMainMenu = 'egmm',
	DVDPlayerEgtoToTitleMenu = 'egtm',
	DVDPlayerEgtoToSubpictureMenu = 'egsb',
	DVDPlayerEgtoToAudioMenu = 'egau',
	DVDPlayerEgtoToAngleMenu = 'egan',
	DVDPlayerEgtoToPttMenu = 'egpt',
	DVDPlayerEgtoReturnToDvd = 'egrt',
	DVDPlayerEgtoToBeginningOfDisc = 'egbd',
	DVDPlayerEgtoToDefaultBookmark = 'egdb',
	DVDPlayerEgtoToLastPlayBookmark = 'eglb'
};
typedef enum DVDPlayerEgto DVDPlayerEgto;

enum DVDPlayerEprs {
	DVDPlayerEprsUpArrowKey = 'eupk',
	DVDPlayerEprsDownArrowKey = 'ednk',
	DVDPlayerEprsLeftArrowKey = 'elfk',
	DVDPlayerEprsRightArrowKey = 'ertk',
	DVDPlayerEprsEnterKey = 'eenk'
};
typedef enum DVDPlayerEprs DVDPlayerEprs;

enum DVDPlayerEmnu {
	DVDPlayerEmnuNone = 'enon' /* not on a menu */,
	DVDPlayerEmnuMain = 'eman' /* main (root) menu */,
	DVDPlayerEmnuTitle = 'etit' /* title menu */,
	DVDPlayerEmnuSubpicture = 'esub' /* subpicture menu */,
	DVDPlayerEmnuAudio = 'eaud' /* audio menu */,
	DVDPlayerEmnuAngle = 'eang' /* angle menu */,
	DVDPlayerEmnuPtt = 'eptt' /* ptt menu */
};
typedef enum DVDPlayerEmnu DVDPlayerEmnu;

enum DVDPlayerEori {
	DVDPlayerEoriVertical = 'ever' /* vertical version of the controller */,
	DVDPlayerEoriHorizontal = 'ehor' /* horizontal version of the controller */
};
typedef enum DVDPlayerEori DVDPlayerEori;

enum DVDPlayerEdrw {
	DVDPlayerEdrwOpen = 'eopn' /* drawer open */,
	DVDPlayerEdrwClosed = 'ecls' /* drawer closed */
};
typedef enum DVDPlayerEdrw DVDPlayerEdrw;

enum DVDPlayerEsiz {
	DVDPlayerEsizHalf = 'ehfs',
	DVDPlayerEsizNormal = 'enms',
	DVDPlayerEsizDouble = 'edbs',
	DVDPlayerEsizMax = 'emxs'
};
typedef enum DVDPlayerEsiz DVDPlayerEsiz;

enum DVDPlayerEwnt {
	DVDPlayerEwntStandard = 'estd' /* standard type */,
	DVDPlayerEwntWide = 'ewid' /* wide type */
};
typedef enum DVDPlayerEwnt DVDPlayerEwnt;

enum DVDPlayerEsta {
	DVDPlayerEstaPlaying = 'espl' /* playing at 1x or lower */,
	DVDPlayerEstaPlayingStill = 'esps' /* playing still frame */,
	DVDPlayerEstaPaused = 'espa',
	DVDPlayerEstaStopped = 'esst' /* stopped */,
	DVDPlayerEstaScanning = 'essc' /* playing greater than 1x */,
	DVDPlayerEstaIdle = 'esid' /* idle */
};
typedef enum DVDPlayerEsta DVDPlayerEsta;

enum DVDPlayerEccd {
	DVDPlayerEccdOverVideo = 'eccv' /* Display closed captioning over the video */,
	DVDPlayerEccdSeparateWindow = 'eccw' /* Display closed captioning in a separate window */
};
typedef enum DVDPlayerEccd DVDPlayerEccd;

enum DVDPlayerEscn {
	DVDPlayerEscnX2 = 'es2x' /* 2x scan rate */,
	DVDPlayerEscnX4 = 'es4x' /* 4x scan rate */,
	DVDPlayerEscnX8 = 'es8x' /* 8x scan rate */,
	DVDPlayerEscnX16 = 'es16' /* 16x scan rate */,
	DVDPlayerEscnX32 = 'es32' /* 32x scan rate */
};
typedef enum DVDPlayerEscn DVDPlayerEscn;



/*
 * DVD Suite
 */

// DVD Player
@interface DVDPlayerApplication : SBApplication

@property (copy, readonly) NSString *version;  // The version of the DVD Player
@property (readonly) BOOL appInitializing;  // Is the app starting up?
@property (readonly) BOOL hasMultiplePlaybackChoice;  // Does user have multiple choices to start playback from?
@property BOOL interactionOverride;  // Turn off interaction with user for last play sheet, etc
@property BOOL viewerFullScreenMenuOverride;  // Turn off display of menu bar when mouse moves to menu bar area in full screen mode
@property (readonly) BOOL hasMedia;  // Is there media in the drive?
@property (readonly) BOOL dvdMenuActive;  // Is playback currently on a dvd menu?
@property (readonly) DVDPlayerEmnu activeDvdMenu;  // The current dvd menu
@property (readonly) DVDPlayerEsta dvdState;  // The state of playback 
@property DVDPlayerEscn dvdScanRate;  // The scan rate for fast forwarding and rewinding
@property BOOL controllerVisibility;  // To hide or show the controller window
@property NSPoint controllerPosition;  // The position of the controller window in screen coordinates
@property (readonly) NSRect controllerBounds;  // The window bounds in screen coordinates
@property (readonly) NSRect controllerScreenBounds;  // The screen bounds the window is on
@property DVDPlayerEori controllerOrientation;  // The controller orientation - (Not supported in 5.0 and greater)
@property DVDPlayerEdrw controllerDrawer;  // The state of the controller drawer 
@property BOOL infoVisibility;  // To hide or show the info window - (Not supported in 5.0 and greater)
@property NSPoint infoPosition;  // The position of the info window in screen coordinates - (Not supported in 5.0 and greater)
@property NSRect infoBounds;  // The window bounds in screen coordinates - (Not supported in 5.0 and greater)
@property (readonly) NSRect infoScreenBounds;  // The screen bounds the window is on - (Not supported in 5.0 and greater)
@property DVDPlayerEwnt infoType;  // Sets the type of info window being displayed - (Not supported in 5.0 and greater)
@property (copy) NSColor *infoTextColor;  // The info text color - (Not supported in 5.0 and greater) 
@property BOOL viewerVisibility;  // To hide or show the viewer window
@property NSPoint viewerPosition;  // To set the position of the viewer window in screen coordinates
@property (readonly) NSRect viewerBounds;  // The window bounds in screen coordinates
@property (readonly) NSRect viewerScreenBounds;  // The screen bounds the window is on
@property DVDPlayerEsiz viewerSize;  // To set the the viewer size
@property BOOL viewerFullScreen;  // Set to true to enter presentation mode 
@property BOOL audioMuted;  // To turn the audio on or off
@property NSInteger audioVolume;  // The DVD audio volume, 0 is silent, 255 is full on 
@property NSInteger elapsedTime;  // The elapsed time, in seconds, of the current title
@property NSPoint elapsedExtendedTime;  // The elapsed time, in seconds and frames, of the current title
@property NSInteger remainingTime;  // The remaining time, in seconds, of the current title
@property NSPoint remainingExtendedTime;  // The remaining time, in seconds and frames, of the current title
@property (readonly) NSInteger titleLength;  // The length of the title in seconds 
@property (readonly) NSPoint titleExtendedLength;  // The length of the title in seconds and frames 
@property (readonly) NSInteger availableAngles;  // The number of angles available at the current time position
@property (readonly) NSInteger availableAudioTracks;  // The number of audio tracks available at the current time position
@property (readonly) NSInteger availableChapters;  // The number of chapters available at the current time position
@property (readonly) NSInteger availableSubtitles;  // The number of subtitles available at the current time position
@property (readonly) NSInteger availableTitles;  // The number of titles available at the current time position 
@property NSInteger angle;  // The current camera angle at the current time position
@property NSInteger audioTrack;  // The current audio track at the current time position
@property NSInteger chapter;  // The current chapter at the current time position
@property BOOL displayingSubtitle;  // Are we currently displaying subtitles?
@property NSInteger subtitle;  // The current subtitle (caption) at the current time position
@property NSInteger title;  // The current title at the current time position
@property BOOL closedCaptioning;  // Turn closed captioning on or off
@property DVDPlayerEccd closedCaptioningDisplay;  // The display type for closed captioning
@property (readonly) BOOL extendedBookmarks;  // Supports extended bookmark functionality
@property (readonly) NSInteger availableBookmarks;  // The number of bookmarks available for the current media
@property (copy, readonly) NSArray *bookmarkList;  // The names of the bookmarks for the current media
@property (readonly) BOOL hasDefaultBookmark;  // Has a default bookmark been set?
@property (copy, readonly) id hasLastPlayBookmark;  // Does the media have a last play bookmark from being previously viewed?
@property (readonly) BOOL extendedVideoClips;  // Supports extended video clip functionality
@property (readonly) NSInteger availableVideoClips;  // The number of video clips available for the current media
@property (copy, readonly) NSArray *videoClipList;  // The names of the video clips for the current media
@property BOOL loopVideoClip;  // To turn the loop state for video clips on or off
@property (readonly) BOOL clipMode;  // Is video clip being played?
@property BOOL disableStatusWindow;  // Disable displaying the status message?

- (NSInteger) fastForwardDvd;  // Start fast forwarding a DVD disc
- (NSInteger) playDvd;  // Start playback of a DVD disc
- (NSInteger) pauseDvd;  // Pause the playback of a DVD disc
- (NSInteger) rewindDvd;  // Start rewinding a DVD disc
- (NSInteger) stopDvd;  // Stop the playback  of a DVD disc
- (NSInteger) stepDvd;  // Step the dvd movie to the next frame
- (NSInteger) go:(DVDPlayerEgto)x;  // Go to the specified place
- (NSInteger) press:(DVDPlayerEprs)x;  // Press a key in a menu
- (NSInteger) openVIDEO_TS:(NSURL *)x;  // open a VIDEO_TS folder for playing dvd from file
- (NSInteger) openDvdVideoFolder:(NSURL *)x;  // open a dvd video folder (VIDEO_TS or HVDVD_TS) folder for playing dvd from file
- (NSInteger) playPreviousChapter;  // Play the previous chapter of the current title
- (NSInteger) playNextChapter;  // Play the next chapter of the current title
- (NSInteger) playBookmark:(NSInteger)x;  // Specify the bookmark to play by index
- (NSInteger) playNamedBookmark:(NSString *)x;  // Specify the bookmark to play by name
- (NSInteger) playVideoClip:(NSInteger)x;  // Specify the video clip to play by index
- (NSInteger) playNamedVideoClip:(NSString *)x;  // Specify the video clip to play by name
- (NSInteger) exitClipMode;  // Exit video clip mode if currently playing a video clip
- (NSInteger) obscureCursor;  // obscure the mouse cursor
- (NSInteger) ejectDvd;  // eject the dvd we are using

@end

