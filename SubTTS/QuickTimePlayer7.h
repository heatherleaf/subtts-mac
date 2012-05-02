/*
 * QuickTimePlayer7.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class QuickTimePlayer7Item, QuickTimePlayer7Application, QuickTimePlayer7Color, QuickTimePlayer7Document, QuickTimePlayer7Window, QuickTimePlayer7Annotation, QuickTimePlayer7Favorite, QuickTimePlayer7Frame, QuickTimePlayer7Hotspot, QuickTimePlayer7InternetLocation, QuickTimePlayer7Recording, QuickTimePlayer7Node, QuickTimePlayer7Palette, QuickTimePlayer7RecentItem, QuickTimePlayer7RgbColor, QuickTimePlayer7Stream, QuickTimePlayer7TextFrame, QuickTimePlayer7Chapter, QuickTimePlayer7Track, QuickTimePlayer7IntegerOrString;

enum QuickTimePlayer7Savo {
	QuickTimePlayer7SavoYes = 'yes ' /* Save the file. */,
	QuickTimePlayer7SavoNo = 'no  ' /* Do not save the file. */,
	QuickTimePlayer7SavoAsk = 'ask ' /* Ask the user whether or not to save the file. */
};
typedef enum QuickTimePlayer7Savo QuickTimePlayer7Savo;

enum QuickTimePlayer7Mvsz {
	QuickTimePlayer7MvszHalf = 'half' /* half size */,
	QuickTimePlayer7MvszNormal = 'norm' /* normal size */,
	QuickTimePlayer7MvszDouble = 'doub' /* double size */,
	QuickTimePlayer7MvszScreen = 'fits' /* fit to screen */,
	QuickTimePlayer7MvszCurrent = 'cust' /* current size */
};
typedef enum QuickTimePlayer7Mvsz QuickTimePlayer7Mvsz;

enum QuickTimePlayer7Prmd {
	QuickTimePlayer7PrmdNormal = 'norm' /* present as a movie */,
	QuickTimePlayer7PrmdSlideShow = 'pmss' /* present as a slide show */
};
typedef enum QuickTimePlayer7Prmd QuickTimePlayer7Prmd;

enum QuickTimePlayer7Bkmt {
	QuickTimePlayer7BkmtInternetLocation = 'url ' /* an internet location */,
	QuickTimePlayer7BkmtUnknown = 'unkn' /* unknown */
};
typedef enum QuickTimePlayer7Bkmt QuickTimePlayer7Bkmt;

enum QuickTimePlayer7Medk {
	QuickTimePlayer7MedkVideo = 'vide' /* video media */,
	QuickTimePlayer7MedkSound = 'soun' /* sound media */,
	QuickTimePlayer7MedkText = 'text' /* text media */,
	QuickTimePlayer7MedkBase = 'gnrc' /* base media */,
	QuickTimePlayer7MedkStreaming = 'strm' /* stream media */,
	QuickTimePlayer7MedkMPEG = 'MPEG' /* MPEG media */,
	QuickTimePlayer7MedkMPEGAudio = 'm1a ' /* MPEG audio media */,
	QuickTimePlayer7MedkMPEGVideo = 'm1v ' /* MPEG video media */,
	QuickTimePlayer7MedkMusic = 'musi' /* music media */,
	QuickTimePlayer7MedkTimecode = 'tmcd' /* timecode media */,
	QuickTimePlayer7MedkSprite = 'sprt' /* sprite media */,
	QuickTimePlayer7MedkFlash = 'flsh' /* Flash media */,
	QuickTimePlayer7MedkTween = 'twen' /* tween media */,
	QuickTimePlayer7Medk3D = 'qd3d' /* QuickDraw 3D media */,
	QuickTimePlayer7MedkQuickTimeVR = 'qtvr' /* QuickTime VR media */,
	QuickTimePlayer7MedkVRPanorama = 'pano' /* QuickTime VR panorama media */,
	QuickTimePlayer7MedkVRObject = 'obje' /* QuickTime VR object media */
};
typedef enum QuickTimePlayer7Medk QuickTimePlayer7Medk;

enum QuickTimePlayer7Expk {
	QuickTimePlayer7ExpkAIFF = 'AIFF' /* AIFF file */,
	QuickTimePlayer7ExpkAppleTV = 'M4VH' /* Apple TV file */,
	QuickTimePlayer7ExpkAVI = 'VfW ' /* AVI file */,
	QuickTimePlayer7ExpkBMP = 'BMPf' /* BMP file */,
	QuickTimePlayer7ExpkDVStream = 'dvc!' /* DV stream file */,
	QuickTimePlayer7ExpkFastStartQTVRMovie = 'vrwe' /* Fast Start QuickTime VR movie */,
	QuickTimePlayer7ExpkFLC = 'FLC ' /* FLC file */,
	QuickTimePlayer7ExpkHintedMovie = 'hint' /* Hinted movie */,
	QuickTimePlayer7ExpkImageSequence = 'grex' /* image sequence */,
	QuickTimePlayer7ExpkInterframeCompressedVRObjectMovie = 'vrob' /* interframe compressed VR object movie */,
	QuickTimePlayer7ExpkIPhone = 'M4VP' /* iPhone file */,
	QuickTimePlayer7ExpkIPhoneCellular = 'iphE' /* iPhone file for cellular network */,
	QuickTimePlayer7ExpkITunes = 'M4V ' /* iTunes file */,
	QuickTimePlayer7ExpkMuLaw = 'ULAW' /* MuLaw file */,
	QuickTimePlayer7ExpkMPEG2 = 'MPEG' /* MPEG2 */,
	QuickTimePlayer7ExpkMPEG4 = 'mpg4' /* MPEG-4 */,
	QuickTimePlayer7ExpkPicture = 'PICT' /* picture */,
	QuickTimePlayer7ExpkQuickTimeMediaLink = 'embd' /* QuickTime media link */,
	QuickTimePlayer7ExpkQuickTimeMovie = 'MooV' /* QuickTime movie file */,
	QuickTimePlayer7ExpkQuickTimeTeXML = 'tx3g' /* QuickTime TeXML file */,
	QuickTimePlayer7ExpkStandardMIDI = 'Midi' /* Standard MIDI file */,
	QuickTimePlayer7ExpkSystem7Sound = 'sfil' /* System 7 Sound file */,
	QuickTimePlayer7ExpkTextFile = 'TEXT' /* Text file */,
	QuickTimePlayer7ExpkThreeGPP = '3gpp' /* 3GPP file */,
	QuickTimePlayer7ExpkWave = 'WAVE' /* Wave file */
};
typedef enum QuickTimePlayer7Expk QuickTimePlayer7Expk;

enum QuickTimePlayer7Savk {
	QuickTimePlayer7SavkSelfContained = 'flat' /* a self contained movie file */
};
typedef enum QuickTimePlayer7Savk QuickTimePlayer7Savk;

enum QuickTimePlayer7Schd {
	QuickTimePlayer7SchdForward = 'tsfo' /* search forward */,
	QuickTimePlayer7SchdBackward = 'tsbw' /* search backward */
};
typedef enum QuickTimePlayer7Schd QuickTimePlayer7Schd;

enum QuickTimePlayer7Exps {
	QuickTimePlayer7ExpsDefaultSettings = 'expd' /* export with default settings */,
	QuickTimePlayer7ExpsMostRecentSettings = 'expr' /* export with most recent settings */
};
typedef enum QuickTimePlayer7Exps QuickTimePlayer7Exps;

enum QuickTimePlayer7Qtcs {
	QuickTimePlayer7Qtcs144Modem = '144 ' /* play media for 14.4 Kbps modem connection (obsolete) */,
	QuickTimePlayer7Qtcs288336Modem = '288 ' /* play media for 28.8/33.6 Kbps modem connection */,
	QuickTimePlayer7Qtcs56KModemISDN = '56K ' /* play media for 56 Kbps/ISDN connection */,
	QuickTimePlayer7Qtcs112KDualISDN = '112K' /* play media for 112 Kbps dual ISDN/DSL connection */,
	QuickTimePlayer7Qtcs256Kbps = 'DSL1' /* play media for 256 Kbps DSL/cable connection */,
	QuickTimePlayer7Qtcs384Kbps = 'DSL2' /* play media for 384 Kbps DSL/cable connection */,
	QuickTimePlayer7Qtcs512Kbps = 'DSL3' /* play media for 512 Kbps DSL/cable connection */,
	QuickTimePlayer7Qtcs768Kbps = 'DSL4' /* play media for 768 Kbps DSL/cable connection */,
	QuickTimePlayer7Qtcs1Mbps = 'Cabl' /* play media for 1 Mbps cable connection */,
	QuickTimePlayer7QtcsT1 = 'T1  ' /* play media for 1.5 Mbps T1/Intranet/LAN connection */,
	QuickTimePlayer7QtcsIntranetLAN = 'LAN ' /* play media for Intranet/LAN connection */
};
typedef enum QuickTimePlayer7Qtcs QuickTimePlayer7Qtcs;

enum QuickTimePlayer7Play {
	QuickTimePlayer7PlayStandard = 'stan' /* standard movie controller */,
	QuickTimePlayer7PlayQtvr = 'qtvr' /* QTVR movie controller */,
	QuickTimePlayer7PlayQtvrPanorama = 'STpn' /* QTVR 1.0 panorama controller */,
	QuickTimePlayer7PlayQtvrObject = 'obje' /* QTVR 1.0 object controller */,
	QuickTimePlayer7PlayNone = 'none' /* none movie controller */
};
typedef enum QuickTimePlayer7Play QuickTimePlayer7Play;

enum QuickTimePlayer7Tran {
	QuickTimePlayer7TranTransferModeUnknown = 'tmuk' /* transfer mode is unknown or not applicable */,
	QuickTimePlayer7TranDitherCopy = 'tmdc' /* draw image using dither copy mode */,
	QuickTimePlayer7TranNoDitherCopy = 'tmcp' /* draw image using copy mode */,
	QuickTimePlayer7TranBlend = 'tmbl' /* draw image using blend mode */,
	QuickTimePlayer7TranTransparent = 'tmtr' /* draw image using transparent mode */,
	QuickTimePlayer7TranStraightAlpha = 'tmsa' /* draw image using straight alpha mode */,
	QuickTimePlayer7TranPremulWhiteAlpha = 'tmwa' /* draw image using premul white alpha mode */,
	QuickTimePlayer7TranPremulBlackAlpha = 'tmba' /* draw image using premul black alpha mode */,
	QuickTimePlayer7TranStraightAlphaBlend = 'tmab' /* draw image using straight alpha blend mode */,
	QuickTimePlayer7TranComposition = 'tmcm' /* draw image using composition (dither copy) mode */
};
typedef enum QuickTimePlayer7Tran QuickTimePlayer7Tran;

enum QuickTimePlayer7Just {
	QuickTimePlayer7JustLeft = 'left' /* draw text left justified */,
	QuickTimePlayer7JustRight = 'rght' /* draw text right justified */,
	QuickTimePlayer7JustCenter = 'cent' /* draw text centered */
};
typedef enum QuickTimePlayer7Just QuickTimePlayer7Just;

enum QuickTimePlayer7Styl {
	QuickTimePlayer7StylPlain = 'plan' /* draw text plain */,
	QuickTimePlayer7StylBold = 'bold' /* draw text bold */,
	QuickTimePlayer7StylItalic = 'ital' /* draw text italic */,
	QuickTimePlayer7StylOutline = 'outl' /* draw text outlined */,
	QuickTimePlayer7StylShadow = 'shad' /* draw text with shadow */,
	QuickTimePlayer7StylUnderline = 'undl' /* draw text with underline */,
	QuickTimePlayer7StylCondense = 'cond' /* draw text condensed */,
	QuickTimePlayer7StylExtend = 'pexp' /* draw text extended */
};
typedef enum QuickTimePlayer7Styl QuickTimePlayer7Styl;

enum QuickTimePlayer7Load {
	QuickTimePlayer7LoadLoadStateUnknown = 'lduk' /* the load state of the movie cannot be determined */,
	QuickTimePlayer7LoadLoadError = 'lder' /* an error occurred which prevents the movie from loading */,
	QuickTimePlayer7LoadLoading = 'ldng' /* the movie is loading, but is unusable in its current state */,
	QuickTimePlayer7LoadLoaded = 'lded' /* the movie has loaded, but some media is still loading */,
	QuickTimePlayer7LoadPlayable = 'ldpl' /* the movie has loaded and sufficient media is available to begin playing */,
	QuickTimePlayer7LoadPlaythroughOkay = 'ldpt' /* the movie has loaded and remaining media should be avaiable when needed */,
	QuickTimePlayer7LoadComplete = 'ldcm' /* the movie has loaded and all media is available */
};
typedef enum QuickTimePlayer7Load QuickTimePlayer7Load;

enum QuickTimePlayer7Txop {
	QuickTimePlayer7TxopScrollIn = 'tfsi' /* scroll text in until all text is visible */,
	QuickTimePlayer7TxopScrollOut = 'tfso' /* scroll text out until all text is gone */,
	QuickTimePlayer7TxopScrollHorizontal = 'tfsh' /* scroll text horizontally (default is vertically) */,
	QuickTimePlayer7TxopScrollReverse = 'tfsr' /* scroll text down or backwards (depending on current scroll direction) */,
	QuickTimePlayer7TxopScrollContinuous = 'tfsc' /* scroll text out in response to next text scrolling in */,
	QuickTimePlayer7TxopFlowHorizontal = 'tffh' /* flow text in textbox */
};
typedef enum QuickTimePlayer7Txop QuickTimePlayer7Txop;

enum QuickTimePlayer7Prst {
	QuickTimePlayer7PrstNormal = 'norm' /* movie is not being presented */,
	QuickTimePlayer7PrstPresentation = 'prsf' /* movie is being presented */
};
typedef enum QuickTimePlayer7Prst QuickTimePlayer7Prst;

enum QuickTimePlayer7Eidn {
	QuickTimePlayer7EidnIdentityMatrix = 'iden' /* the identity matrix */
};
typedef enum QuickTimePlayer7Eidn QuickTimePlayer7Eidn;

enum QuickTimePlayer7Nudg {
	QuickTimePlayer7NudgLeft = 'left' /* nudge left */,
	QuickTimePlayer7NudgRight = 'rght' /* nudge right */,
	QuickTimePlayer7NudgUp = 'up  ' /* nudge up */,
	QuickTimePlayer7NudgDown = 'down' /* nudge down */,
	QuickTimePlayer7NudgUpRight = 'upri' /* nudge up right */,
	QuickTimePlayer7NudgUpLeft = 'uple' /* nudge up left */,
	QuickTimePlayer7NudgDownRight = 'dori' /* nudge down right */,
	QuickTimePlayer7NudgDownLeft = 'dole' /* nudge down left */
};
typedef enum QuickTimePlayer7Nudg QuickTimePlayer7Nudg;

enum QuickTimePlayer7Vrty {
	QuickTimePlayer7VrtyPanorama = 'pano' /* panorama movie type */,
	QuickTimePlayer7VrtyObject = 'obje' /* object movie type */
};
typedef enum QuickTimePlayer7Vrty QuickTimePlayer7Vrty;

enum QuickTimePlayer7Hslt {
	QuickTimePlayer7HsltLink = 'link' /* link to another node in the VR movie */,
	QuickTimePlayer7HsltURL = 'url ' /* link to an external destination described by URL */,
	QuickTimePlayer7HsltUnknown = 'undf' /* unknown link type */
};
typedef enum QuickTimePlayer7Hslt QuickTimePlayer7Hslt;

enum QuickTimePlayer7Zdir {
	QuickTimePlayer7ZdirInward = 'inwa' /* zoom inward */,
	QuickTimePlayer7ZdirOutward = 'otwa' /* zoom outward */
};
typedef enum QuickTimePlayer7Zdir QuickTimePlayer7Zdir;

enum QuickTimePlayer7Navm {
	QuickTimePlayer7NavmAbsolute = 'abso' /* absolute value */,
	QuickTimePlayer7NavmRelative = 'rela' /* relative value */
};
typedef enum QuickTimePlayer7Navm QuickTimePlayer7Navm;

enum QuickTimePlayer7Rcst {
	QuickTimePlayer7RcstPreviewing = 'prvw' /* previewing and ready to record */,
	QuickTimePlayer7RcstRecording = 'recd' /* recording in progress */,
	QuickTimePlayer7RcstPaused = 'pasd' /* recording paused */
};
typedef enum QuickTimePlayer7Rcst QuickTimePlayer7Rcst;

enum QuickTimePlayer7Aper {
	QuickTimePlayer7AperUnconformed = 'uncn' /* unconformed */,
	QuickTimePlayer7AperClassic = 'clas' /* classic */,
	QuickTimePlayer7AperClean = 'clea' /* clean */,
	QuickTimePlayer7AperEncodedPixels = 'enco' /* encoded pixels */,
	QuickTimePlayer7AperProduction = 'prod' /* production */
};
typedef enum QuickTimePlayer7Aper QuickTimePlayer7Aper;



/*
 * Standard Suite
 */

// A scriptable object.
@interface QuickTimePlayer7Item : SBObject

@property (copy) QuickTimePlayer7Recording *properties;  // All of the object's properties.

- (void) closeSaving:(QuickTimePlayer7Savo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(QuickTimePlayer7Recording *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save an object.
- (void) addScaled:(BOOL)scaled;  // Add an object from the clipboard in parallel to the current selection
- (void) clear;  // Clear the current selection
- (void) copy;  // Copy an object to the clipboard
- (void) cut;  // Cut an object to the clipboard
- (BOOL) canExportAs:(QuickTimePlayer7Expk)as;  // Determine if a movie or track can be exported to the desired type
- (void) exportTo:(NSURL *)to as:(QuickTimePlayer7Expk)as using:(QuickTimePlayer7Exps)using_ usingSettingsPreset:(NSString *)usingSettingsPreset usingSettings:(NSURL *)usingSettings replacing:(BOOL)replacing;  // Export a movie or track to a file
- (NSInteger) findText:(NSString *)text backwards:(BOOL)backwards;  // Find text in a movie
- (void) flipHorizontal;  // Flip an object along the horizontal axis
- (void) flipVertical;  // Flip an object along the vertical axis
- (void) getURL;  // Play a movie from a URL
- (void) invert;  // Invert an object
- (QuickTimePlayer7Document *) openLocationPosition:(NSPoint)position;  // Play the specified internet location(s)
- (void) paste;  // Paste an object from the clipboard
- (void) presentScale:(QuickTimePlayer7Mvsz)scale mode:(QuickTimePlayer7Prmd)mode display:(NSInteger)display backgroundColor:(QuickTimePlayer7RgbColor *)backgroundColor;  // Present a movie
- (void) redo;  // Redo the action of the previous event or user interaction
- (void) replace;  // Replace the current selection with an object from the clipboard
- (void) resizeBy:(double)by around:(NSPoint)around;  // Scale an object
- (void) rewind;  // Rewind a movie to the beginning
- (void) rotateBy:(double)by around:(NSPoint)around;  // Rotate an object by an arbitrary amount
- (void) rotateLeft;  // Rotate an object 90¡ left
- (void) rotateRight;  // Rotate an object 90¡ right
- (void) selectAt:(NSInteger)at to:(NSInteger)to;  // Select a range of time
- (void) selectAll;  // Select the entire movie
- (void) selectNone;  // Set the selection of the movie to nothing
- (void) skewBy:(NSPoint)by around:(NSPoint)around;  // Skew an object by an arbitrary amount
- (void) stepBackwardBy:(NSInteger)by;  // Move the current time backward
- (void) stepForwardBy:(NSInteger)by;  // Move the current time forward
- (void) stop;  // Stop playing or recording a movie.
- (void) translateBy:(NSPoint)by;  // Translate the object some distance
- (void) trim;  // Remove all content before and after the current selection
- (void) start;  // Start playing or recording a movie.
- (void) pause;  // Pause a movie or recording.
- (void) newAudioRecording;  // Create a new audio recording.
- (void) newMovieRecording;  // Create a new movie recording.

@end

// An application's top level scripting object.
@interface QuickTimePlayer7Application : SBApplication

- (SBElementArray *) documents;
- (SBElementArray *) windows;

@property (copy, readonly) NSString *name;  // The name of the application.
@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *version;  // The version of the application.

- (void) open:(NSURL *)x;  // Open an object.
- (void) print:(NSURL *)x;  // Print an object.
- (void) quitSaving:(QuickTimePlayer7Savo)saving;  // Quit an application.
- (QuickTimePlayer7Document *) openImageSequence:(NSURL *)x framesPerSecond:(double)framesPerSecond secondsPerFrame:(double)secondsPerFrame;  // Open image sequence starting with the file.
- (void) undo;  // Undo the action of the previous event or user interaction
- (void) saveReferenceMovieTo:(NSURL *)to usingDescriptors:(id)usingDescriptors replacing:(BOOL)replacing;  // Save a movie that references multiple versions of another movie to a file

@end

// A color.
@interface QuickTimePlayer7Color : SBObject

- (void) closeSaving:(QuickTimePlayer7Savo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(QuickTimePlayer7Recording *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save an object.
- (void) addScaled:(BOOL)scaled;  // Add an object from the clipboard in parallel to the current selection
- (void) clear;  // Clear the current selection
- (void) copy;  // Copy an object to the clipboard
- (void) cut;  // Cut an object to the clipboard
- (BOOL) canExportAs:(QuickTimePlayer7Expk)as;  // Determine if a movie or track can be exported to the desired type
- (void) exportTo:(NSURL *)to as:(QuickTimePlayer7Expk)as using:(QuickTimePlayer7Exps)using_ usingSettingsPreset:(NSString *)usingSettingsPreset usingSettings:(NSURL *)usingSettings replacing:(BOOL)replacing;  // Export a movie or track to a file
- (NSInteger) findText:(NSString *)text backwards:(BOOL)backwards;  // Find text in a movie
- (void) flipHorizontal;  // Flip an object along the horizontal axis
- (void) flipVertical;  // Flip an object along the vertical axis
- (void) getURL;  // Play a movie from a URL
- (void) invert;  // Invert an object
- (QuickTimePlayer7Document *) openLocationPosition:(NSPoint)position;  // Play the specified internet location(s)
- (void) paste;  // Paste an object from the clipboard
- (void) presentScale:(QuickTimePlayer7Mvsz)scale mode:(QuickTimePlayer7Prmd)mode display:(NSInteger)display backgroundColor:(QuickTimePlayer7RgbColor *)backgroundColor;  // Present a movie
- (void) redo;  // Redo the action of the previous event or user interaction
- (void) replace;  // Replace the current selection with an object from the clipboard
- (void) resizeBy:(double)by around:(NSPoint)around;  // Scale an object
- (void) rewind;  // Rewind a movie to the beginning
- (void) rotateBy:(double)by around:(NSPoint)around;  // Rotate an object by an arbitrary amount
- (void) rotateLeft;  // Rotate an object 90¡ left
- (void) rotateRight;  // Rotate an object 90¡ right
- (void) selectAt:(NSInteger)at to:(NSInteger)to;  // Select a range of time
- (void) selectAll;  // Select the entire movie
- (void) selectNone;  // Set the selection of the movie to nothing
- (void) skewBy:(NSPoint)by around:(NSPoint)around;  // Skew an object by an arbitrary amount
- (void) stepBackwardBy:(NSInteger)by;  // Move the current time backward
- (void) stepForwardBy:(NSInteger)by;  // Move the current time forward
- (void) stop;  // Stop playing or recording a movie.
- (void) translateBy:(NSPoint)by;  // Translate the object some distance
- (void) trim;  // Remove all content before and after the current selection
- (void) start;  // Start playing or recording a movie.
- (void) pause;  // Pause a movie or recording.
- (void) newAudioRecording;  // Create a new audio recording.
- (void) newMovieRecording;  // Create a new movie recording.

@end

// Synonym for document
@interface QuickTimePlayer7Document : SBObject

@property (copy) NSString *path;  // The document's path.
@property (readonly) BOOL modified;  // Has the document been modified since the last save?
@property (copy) NSString *name;  // The document's name.

- (void) closeSaving:(QuickTimePlayer7Savo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(QuickTimePlayer7Recording *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save an object.
- (void) addScaled:(BOOL)scaled;  // Add an object from the clipboard in parallel to the current selection
- (void) clear;  // Clear the current selection
- (void) copy;  // Copy an object to the clipboard
- (void) cut;  // Cut an object to the clipboard
- (BOOL) canExportAs:(QuickTimePlayer7Expk)as;  // Determine if a movie or track can be exported to the desired type
- (void) exportTo:(NSURL *)to as:(QuickTimePlayer7Expk)as using:(QuickTimePlayer7Exps)using_ usingSettingsPreset:(NSString *)usingSettingsPreset usingSettings:(NSURL *)usingSettings replacing:(BOOL)replacing;  // Export a movie or track to a file
- (NSInteger) findText:(NSString *)text backwards:(BOOL)backwards;  // Find text in a movie
- (void) flipHorizontal;  // Flip an object along the horizontal axis
- (void) flipVertical;  // Flip an object along the vertical axis
- (void) getURL;  // Play a movie from a URL
- (void) invert;  // Invert an object
- (QuickTimePlayer7Document *) openLocationPosition:(NSPoint)position;  // Play the specified internet location(s)
- (void) paste;  // Paste an object from the clipboard
- (void) play;  // Play the movie.
- (void) presentScale:(QuickTimePlayer7Mvsz)scale mode:(QuickTimePlayer7Prmd)mode display:(NSInteger)display backgroundColor:(QuickTimePlayer7RgbColor *)backgroundColor;  // Present a movie
- (void) redo;  // Redo the action of the previous event or user interaction
- (void) replace;  // Replace the current selection with an object from the clipboard
- (void) resizeBy:(double)by around:(NSPoint)around;  // Scale an object
- (void) rewind;  // Rewind a movie to the beginning
- (void) rotateBy:(double)by around:(NSPoint)around;  // Rotate an object by an arbitrary amount
- (void) rotateLeft;  // Rotate an object 90¡ left
- (void) rotateRight;  // Rotate an object 90¡ right
- (void) saveExportSettingsFor:(QuickTimePlayer7Expk)for_ to:(NSURL *)to replacing:(BOOL)replacing;  // Save an exporters settings
- (void) saveSelfContainedIn:(NSURL *)in_;  // Save a self-contained movie.
- (void) selectAt:(NSInteger)at to:(NSInteger)to;  // Select a range of time
- (void) selectAll;  // Select the entire movie
- (void) selectNone;  // Set the selection of the movie to nothing
- (void) skewBy:(NSPoint)by around:(NSPoint)around;  // Skew an object by an arbitrary amount
- (void) stepBackwardBy:(NSInteger)by;  // Move the current time backward
- (void) stepForwardBy:(NSInteger)by;  // Move the current time forward
- (void) stop;  // Stop playing or recording a movie.
- (void) translateBy:(NSPoint)by;  // Translate the object some distance
- (void) trim;  // Remove all content before and after the current selection
- (void) zoomDirection:(QuickTimePlayer7Zdir)direction;  // Zoom a QuickTime VR movie
- (void) nudgeDirection:(QuickTimePlayer7Nudg)direction;  // Nudge a QuickTime VR movie
- (void) start;  // Start playing or recording a movie.
- (void) pause;  // Pause a movie or recording.
- (void) newAudioRecording;  // Create a new audio recording.
- (void) newMovieRecording;  // Create a new movie recording.

@end

// A window.
@interface QuickTimePlayer7Window : SBObject

@property (copy) NSString *name;  // The full title of the window.
- (NSNumber *) id;  // The unique identifier of the window.
@property NSRect bounds;  // The bounding rectangle of the window.
@property (copy, readonly) QuickTimePlayer7Document *document;  // The document whose contents are being displayed in the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (readonly) BOOL titled;  // Whether the window has a title bar.
@property (copy) NSNumber *index;  // The index of the window in the back-to-front window ordering.
@property (readonly) BOOL floating;  // Whether the window floats.
@property (readonly) BOOL miniaturizable;  // Whether the window can be miniaturized.
@property BOOL miniaturized;  // Whether the window is currently miniaturized.
@property (readonly) BOOL modal;  // Whether the window is the application's current modal window.
@property (readonly) BOOL resizable;  // Whether the window can be resized.
@property BOOL visible;  // Whether the window is currently visible.
@property (readonly) BOOL zoomable;  // Whether the window can be zoomed.
@property BOOL zoomed;  // Whether the window is currently zoomed.

- (void) closeSaving:(QuickTimePlayer7Savo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(QuickTimePlayer7Recording *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save an object.
- (void) addScaled:(BOOL)scaled;  // Add an object from the clipboard in parallel to the current selection
- (void) clear;  // Clear the current selection
- (void) copy;  // Copy an object to the clipboard
- (void) cut;  // Cut an object to the clipboard
- (BOOL) canExportAs:(QuickTimePlayer7Expk)as;  // Determine if a movie or track can be exported to the desired type
- (void) exportTo:(NSURL *)to as:(QuickTimePlayer7Expk)as using:(QuickTimePlayer7Exps)using_ usingSettingsPreset:(NSString *)usingSettingsPreset usingSettings:(NSURL *)usingSettings replacing:(BOOL)replacing;  // Export a movie or track to a file
- (NSInteger) findText:(NSString *)text backwards:(BOOL)backwards;  // Find text in a movie
- (void) flipHorizontal;  // Flip an object along the horizontal axis
- (void) flipVertical;  // Flip an object along the vertical axis
- (void) getURL;  // Play a movie from a URL
- (void) invert;  // Invert an object
- (QuickTimePlayer7Document *) openLocationPosition:(NSPoint)position;  // Play the specified internet location(s)
- (void) paste;  // Paste an object from the clipboard
- (void) presentScale:(QuickTimePlayer7Mvsz)scale mode:(QuickTimePlayer7Prmd)mode display:(NSInteger)display backgroundColor:(QuickTimePlayer7RgbColor *)backgroundColor;  // Present a movie
- (void) redo;  // Redo the action of the previous event or user interaction
- (void) replace;  // Replace the current selection with an object from the clipboard
- (void) resizeBy:(double)by around:(NSPoint)around;  // Scale an object
- (void) rewind;  // Rewind a movie to the beginning
- (void) rotateBy:(double)by around:(NSPoint)around;  // Rotate an object by an arbitrary amount
- (void) rotateLeft;  // Rotate an object 90¡ left
- (void) rotateRight;  // Rotate an object 90¡ right
- (void) selectAt:(NSInteger)at to:(NSInteger)to;  // Select a range of time
- (void) selectAll;  // Select the entire movie
- (void) selectNone;  // Set the selection of the movie to nothing
- (void) skewBy:(NSPoint)by around:(NSPoint)around;  // Skew an object by an arbitrary amount
- (void) stepBackwardBy:(NSInteger)by;  // Move the current time backward
- (void) stepForwardBy:(NSInteger)by;  // Move the current time forward
- (void) stop;  // Stop playing or recording a movie.
- (void) translateBy:(NSPoint)by;  // Translate the object some distance
- (void) trim;  // Remove all content before and after the current selection
- (void) start;  // Start playing or recording a movie.
- (void) pause;  // Pause a movie or recording.
- (void) newAudioRecording;  // Create a new audio recording.
- (void) newMovieRecording;  // Create a new movie recording.

@end



/*
 * QuickTime Player Suite
 */

// An annotation in a QuickTime movie
@interface QuickTimePlayer7Annotation : QuickTimePlayer7Item

@property (copy) NSString *fullText;  // the text of the annotation
- (NSString *) id;  // the ID of the annotation
@property (copy, readonly) NSString *name;  // the name of the annotation


@end

// The QuickTime Player application program
@interface QuickTimePlayer7Application (QuickTimePlayerSuite)

- (SBElementArray *) favorites;
- (SBElementArray *) documents;
- (SBElementArray *) recentItems;
- (SBElementArray *) recordings;
- (SBElementArray *) windows;

@property BOOL ignoreAutoPlay;  // ignore requests to auto-play movies upon opening?
@property BOOL ignoreAutoPresent;  // ignore requests to auto-present movies upon opening?
@property BOOL onlyFrontMoviePlaysSound;  // should only sound of front movie be played?
@property BOOL openMovieInNewPlayer;  // should movies be opened in separate windows?
@property BOOL playMovieFromBeginningWhenOpened;  // should movies auto-play when opened?
@property BOOL playSoundInBackground;  // should sound of background movies be played?
@property (readonly) BOOL QuickTimeProInstalled;  // is the pro version of QuickTime installed?
@property (readonly) double QuickTimeVersion;  // the version of the installed QuickTime
@property BOOL showAvControlsWindow;  // show/hide the a/v controls window
@property BOOL showClosedCaptioningWhenAvailable;  // show closed captioning (when supported by content)
@property BOOL showEqualizer;  // should equalizer be displayed for audio content
@property BOOL suspendPlayingMoviesOnUserSwitch;  // should playing movies be suspended when switching to a different user
@property BOOL showFavoritesWindow;  // show the favorites window
@property BOOL showMovieInfoWindow;  // show the movie info window
@property BOOL showTimecodeWhenAvailable;  // show timecode (when supported by content)
@property BOOL showWelcomeMovieAutomatically;  // always show the Content Guide when application launches
@property BOOL useHighQualityVideoSettingWhenAvailable;  // use high-quality video playback when available

@end

// A reference to a QuickTime movie
@interface QuickTimePlayer7Favorite : SBObject

- (SBElementArray *) internetLocations;

@property (copy, readonly) NSString *category;  // the category of the favorite
@property (readonly) QuickTimePlayer7Bkmt kind;  // the kind of the favorite
@property (copy, readonly) NSString *name;  // the name of the favorite

- (void) closeSaving:(QuickTimePlayer7Savo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(QuickTimePlayer7Recording *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save an object.
- (void) addScaled:(BOOL)scaled;  // Add an object from the clipboard in parallel to the current selection
- (void) clear;  // Clear the current selection
- (void) copy;  // Copy an object to the clipboard
- (void) cut;  // Cut an object to the clipboard
- (BOOL) canExportAs:(QuickTimePlayer7Expk)as;  // Determine if a movie or track can be exported to the desired type
- (void) exportTo:(NSURL *)to as:(QuickTimePlayer7Expk)as using:(QuickTimePlayer7Exps)using_ usingSettingsPreset:(NSString *)usingSettingsPreset usingSettings:(NSURL *)usingSettings replacing:(BOOL)replacing;  // Export a movie or track to a file
- (NSInteger) findText:(NSString *)text backwards:(BOOL)backwards;  // Find text in a movie
- (void) flipHorizontal;  // Flip an object along the horizontal axis
- (void) flipVertical;  // Flip an object along the vertical axis
- (void) getURL;  // Play a movie from a URL
- (void) invert;  // Invert an object
- (QuickTimePlayer7Document *) openLocationPosition:(NSPoint)position;  // Play the specified internet location(s)
- (void) paste;  // Paste an object from the clipboard
- (void) presentScale:(QuickTimePlayer7Mvsz)scale mode:(QuickTimePlayer7Prmd)mode display:(NSInteger)display backgroundColor:(QuickTimePlayer7RgbColor *)backgroundColor;  // Present a movie
- (void) redo;  // Redo the action of the previous event or user interaction
- (void) replace;  // Replace the current selection with an object from the clipboard
- (void) resizeBy:(double)by around:(NSPoint)around;  // Scale an object
- (void) rewind;  // Rewind a movie to the beginning
- (void) rotateBy:(double)by around:(NSPoint)around;  // Rotate an object by an arbitrary amount
- (void) rotateLeft;  // Rotate an object 90¡ left
- (void) rotateRight;  // Rotate an object 90¡ right
- (void) selectAt:(NSInteger)at to:(NSInteger)to;  // Select a range of time
- (void) selectAll;  // Select the entire movie
- (void) selectNone;  // Set the selection of the movie to nothing
- (void) skewBy:(NSPoint)by around:(NSPoint)around;  // Skew an object by an arbitrary amount
- (void) stepBackwardBy:(NSInteger)by;  // Move the current time backward
- (void) stepForwardBy:(NSInteger)by;  // Move the current time forward
- (void) stop;  // Stop playing or recording a movie.
- (void) translateBy:(NSPoint)by;  // Translate the object some distance
- (void) trim;  // Remove all content before and after the current selection
- (void) start;  // Start playing or recording a movie.
- (void) pause;  // Pause a movie or recording.
- (void) newAudioRecording;  // Create a new audio recording.
- (void) newMovieRecording;  // Create a new movie recording.

@end

// A reference to a frame (sample) in a QuickTime movie track.
@interface QuickTimePlayer7Frame : SBObject

@property (copy) id contents;  // the contents of the frame (deprecated - use 'sample data' instead)
@property NSInteger duration;  // the duration of the frame
@property (readonly) NSInteger index;  // the index of the frame
@property NSInteger time;  // the time at which the frame starts

- (void) closeSaving:(QuickTimePlayer7Savo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(QuickTimePlayer7Recording *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save an object.
- (void) addScaled:(BOOL)scaled;  // Add an object from the clipboard in parallel to the current selection
- (void) clear;  // Clear the current selection
- (void) copy;  // Copy an object to the clipboard
- (void) cut;  // Cut an object to the clipboard
- (BOOL) canExportAs:(QuickTimePlayer7Expk)as;  // Determine if a movie or track can be exported to the desired type
- (void) exportTo:(NSURL *)to as:(QuickTimePlayer7Expk)as using:(QuickTimePlayer7Exps)using_ usingSettingsPreset:(NSString *)usingSettingsPreset usingSettings:(NSURL *)usingSettings replacing:(BOOL)replacing;  // Export a movie or track to a file
- (NSInteger) findText:(NSString *)text backwards:(BOOL)backwards;  // Find text in a movie
- (void) flipHorizontal;  // Flip an object along the horizontal axis
- (void) flipVertical;  // Flip an object along the vertical axis
- (void) getURL;  // Play a movie from a URL
- (void) invert;  // Invert an object
- (QuickTimePlayer7Document *) openLocationPosition:(NSPoint)position;  // Play the specified internet location(s)
- (void) paste;  // Paste an object from the clipboard
- (void) presentScale:(QuickTimePlayer7Mvsz)scale mode:(QuickTimePlayer7Prmd)mode display:(NSInteger)display backgroundColor:(QuickTimePlayer7RgbColor *)backgroundColor;  // Present a movie
- (void) redo;  // Redo the action of the previous event or user interaction
- (void) replace;  // Replace the current selection with an object from the clipboard
- (void) resizeBy:(double)by around:(NSPoint)around;  // Scale an object
- (void) rewind;  // Rewind a movie to the beginning
- (void) rotateBy:(double)by around:(NSPoint)around;  // Rotate an object by an arbitrary amount
- (void) rotateLeft;  // Rotate an object 90¡ left
- (void) rotateRight;  // Rotate an object 90¡ right
- (void) selectAt:(NSInteger)at to:(NSInteger)to;  // Select a range of time
- (void) selectAll;  // Select the entire movie
- (void) selectNone;  // Set the selection of the movie to nothing
- (void) skewBy:(NSPoint)by around:(NSPoint)around;  // Skew an object by an arbitrary amount
- (void) stepBackwardBy:(NSInteger)by;  // Move the current time backward
- (void) stepForwardBy:(NSInteger)by;  // Move the current time forward
- (void) stop;  // Stop playing or recording a movie.
- (void) translateBy:(NSPoint)by;  // Translate the object some distance
- (void) trim;  // Remove all content before and after the current selection
- (void) start;  // Start playing or recording a movie.
- (void) pause;  // Pause a movie or recording.
- (void) newAudioRecording;  // Create a new audio recording.
- (void) newMovieRecording;  // Create a new movie recording.

@end

// A hotspot in a QuickTime VR movie
@interface QuickTimePlayer7Hotspot : QuickTimePlayer7Item

@property BOOL enabled;  // is the hotspot enabled?
- (NSString *) id;  // the unique id of the hotspot
@property (readonly) NSInteger index;  // the index of the hotspot
@property (copy, readonly) NSString *link;  // the link of the hotspot
@property (copy, readonly) NSString *name;  // the name of the hotspot
@property (readonly) QuickTimePlayer7Hslt kind;  // the kind of hotspot

- (void) trigger;  // Trigger a QuickTime VR hotspot

@end

// A movie internet location
@interface QuickTimePlayer7InternetLocation : QuickTimePlayer7Item

@property (copy, readonly) NSString *location;  // the internet location
@property (copy) NSString *name;  // the name of the chapter


@end

// A recording document
@interface QuickTimePlayer7Recording : QuickTimePlayer7Document

- (SBElementArray *) windows;

@property (readonly) QuickTimePlayer7Rcst state;  // state of the recording


@end

// A movie document
@interface QuickTimePlayer7Document (QuickTimePlayerSuite)

- (SBElementArray *) annotations;
- (SBElementArray *) chapters;
- (SBElementArray *) internetLocations;
- (SBElementArray *) nodes;
- (SBElementArray *) tracks;
- (SBElementArray *) windows;

@property QuickTimePlayer7Aper aperture;  // the aperture mode of the movie
@property BOOL autoCloseWhenDone;  // will the movie automatically close when done playing? (saved with movie)
@property BOOL autoPlay;  // will the movie automatically start playing? (saved with movie)
@property BOOL autoPresent;  // will the movie automatically start presenting? (saved with movie)
@property BOOL autoQuitWhenDone;  // will the player automatically quit when done playing? (saved with movie)
@property NSInteger bassGain;  // the bass setting for the track (-256..256) (not saved with movie)
@property BOOL closeWhenDone;  // close the movie when it is done playing? (not saved with movie)
@property QuickTimePlayer7Play controllerType;  // the type of controller associated with the movie
@property (copy, readonly) QuickTimePlayer7Chapter *currentChapter;  // the chapter containing the current time
@property (copy, readonly) QuickTimePlayer7Track *currentChapterTrack;  // the currently active chapter track (may differ by language)
@property (copy) NSArray *currentMatrix;  // the matrix of the movie
@property (copy) QuickTimePlayer7Node *currentNode;  // the current node of the VR movie
@property NSInteger currentTime;  // the current time (can be set by name as well as number)
@property (readonly) NSInteger dataRate;  // the data rate (bytes/sec) of the movie
@property (readonly) NSInteger dataSize;  // the data size (in bytes) of the movie
@property (copy, readonly) QuickTimePlayer7Node *defaultNode;  // the default node of the VR movie
@property NSPoint dimensions;  // the current dimensions of the movie, not including the controller
@property (readonly) QuickTimePlayer7Prst displayState;  // the display state of the movie
@property (readonly) BOOL done;  // is the movie done playing?
@property (readonly) NSInteger duration;  // the duration of the movie
@property (readonly) BOOL fastStart;  // is this a fast-start movie?
@property double fieldOfView;  // the field of view of the current node
@property (copy) NSString *href;  // the internet location to open when clicking on the movie (overrides track hrefs)
- (NSInteger) id;  // the ID of the movie
@property (readonly) NSInteger index;  // the index of the movie
@property (readonly) BOOL liveStream;  // is this a live streaming movie?
@property (readonly) QuickTimePlayer7Load loadState;  // the current state of an asynchronously loading movie
@property (readonly) BOOL localPlayback;  // is this a local movie?
@property BOOL looping;  // keep playing the movie in a loop?
@property (readonly) NSInteger maxTimeLoaded;  // the amount of time loaded in a fast start movie
@property (readonly) BOOL modified;  // has the document been modified since the last save?
@property BOOL muted;  // is the movie muted?
@property (copy, readonly) NSString *name;  // the movie's name.
@property (readonly) NSPoint naturalDimensions;  // the dimensions the movie has when it is not scaled
@property (copy, readonly) NSURL *originalFile;  // the file containing the movie
@property BOOL palindrome;  // loop back and forth?
@property double panAngle;  // the pan angle of the current node
@property double panTiltSpeed;  // the rate at which panning will occur
@property BOOL playAllFrames;  // play every frame? (no audio will play)
@property BOOL playSelectionOnly;  // play the selection only?
@property (readonly) BOOL playing;  // is the movie playing?
@property (copy) NSArray *pluginSettings;  // the QuickTime Plugin settings stored in the movie
@property NSInteger posterFrameTime;  // the time of the poster frame for the movie
@property double preferredRate;  // the preferred rate of the movie
@property (copy) QuickTimePlayer7RgbColor *presentationBackgroundColor;  // the background color (default is black)
@property QuickTimePlayer7Prmd presentationMode;  // mode in which the movie will be presented
@property QuickTimePlayer7Mvsz presentationSize;  // size at which the movie will be presented
@property (copy) NSArray *preview;  // start time and end time of the movie preview. Example: {0, 1200}
@property BOOL quitWhenDone;  // quit the application when this movie is done playing? (not saved with movie)
@property double rate;  // the rate at which the movie is currently playing
@property BOOL savable;  // can the movie be saved?
@property QuickTimePlayer7Mvsz scale;  // the current scale of the movie
@property NSInteger selectionDuration;  // the duration of the movie selection
@property NSInteger selectionEnd;  // the end of the movie selection
@property NSInteger selectionStart;  // the start of the movie selection
@property BOOL showDetailedMovieInfoWindow;  // show the movie property window
@property BOOL showHotSpots;  // should hotspots be shown?
@property BOOL showMovieInfoWindow;  // show the movie info window
@property NSInteger soundBalance;  // the balance of the movie (-128..128), where negative is left, 0 is center, and positive is right
@property NSInteger soundVolume;  // the sound volume of the movie (0..384), where 256 is 100%
@property (readonly) BOOL storedStream;  // is this a stored streaming movie?
@property (readonly) NSInteger streamingStatusCode;  // the streaming status code of the movie
@property (copy, readonly) NSString *streamingStatusMessage;  // the streaming status message of the movie
@property double tiltAngle;  // the tilt angle of the current node
@property (readonly) NSInteger timeScale;  // the time scale of the movie
@property NSInteger trebleGain;  // the treble setting for the movie (-256..256) (not saved with movie)
@property double videoBrightnessAdjustment;  // the adjustment to the video brightness (range is -1.0 to 1.0)
@property double videoContrastAdjustment;  // the adjustment to the video contrast (range is -1.0 to 1.0)
@property double videoTintAdjustment;  // the adjustment to the video tint (range is -0.25 to 0.25)
@property double videoColorAdjustment;  // the adjustment to the video color
@property double zoomRate;  // the rate at which zooming will occur
@property (copy, readonly) NSArray *panRange;  // minimum and maximum values for pan value: given as { min, max }
@property (copy, readonly) NSArray *tiltRange;  // minimum and maximum values for tilt value: given as { min, max }
@property (copy, readonly) NSArray *fieldOfViewRange;  // minimum and maximum values for field of view value: given as { min, max }

@end

// A node in a QuickTime VR movie
@interface QuickTimePlayer7Node : QuickTimePlayer7Item

- (SBElementArray *) hotspots;

- (NSString *) id;  // the unique identifier of the node
@property (readonly) NSInteger index;  // the index of the node
@property (copy, readonly) NSString *name;  // the name of the node
@property (readonly) QuickTimePlayer7Vrty kind;  // the kind of node


@end

// A palette
@interface QuickTimePlayer7Palette : SBObject

- (SBElementArray *) rgbColors;

@property (copy) NSArray *contents;  // the contents of the matrix

- (void) closeSaving:(QuickTimePlayer7Savo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(QuickTimePlayer7Recording *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save an object.
- (void) addScaled:(BOOL)scaled;  // Add an object from the clipboard in parallel to the current selection
- (void) clear;  // Clear the current selection
- (void) copy;  // Copy an object to the clipboard
- (void) cut;  // Cut an object to the clipboard
- (BOOL) canExportAs:(QuickTimePlayer7Expk)as;  // Determine if a movie or track can be exported to the desired type
- (void) exportTo:(NSURL *)to as:(QuickTimePlayer7Expk)as using:(QuickTimePlayer7Exps)using_ usingSettingsPreset:(NSString *)usingSettingsPreset usingSettings:(NSURL *)usingSettings replacing:(BOOL)replacing;  // Export a movie or track to a file
- (NSInteger) findText:(NSString *)text backwards:(BOOL)backwards;  // Find text in a movie
- (void) flipHorizontal;  // Flip an object along the horizontal axis
- (void) flipVertical;  // Flip an object along the vertical axis
- (void) getURL;  // Play a movie from a URL
- (void) invert;  // Invert an object
- (QuickTimePlayer7Document *) openLocationPosition:(NSPoint)position;  // Play the specified internet location(s)
- (void) paste;  // Paste an object from the clipboard
- (void) presentScale:(QuickTimePlayer7Mvsz)scale mode:(QuickTimePlayer7Prmd)mode display:(NSInteger)display backgroundColor:(QuickTimePlayer7RgbColor *)backgroundColor;  // Present a movie
- (void) redo;  // Redo the action of the previous event or user interaction
- (void) replace;  // Replace the current selection with an object from the clipboard
- (void) resizeBy:(double)by around:(NSPoint)around;  // Scale an object
- (void) rewind;  // Rewind a movie to the beginning
- (void) rotateBy:(double)by around:(NSPoint)around;  // Rotate an object by an arbitrary amount
- (void) rotateLeft;  // Rotate an object 90¡ left
- (void) rotateRight;  // Rotate an object 90¡ right
- (void) selectAt:(NSInteger)at to:(NSInteger)to;  // Select a range of time
- (void) selectAll;  // Select the entire movie
- (void) selectNone;  // Set the selection of the movie to nothing
- (void) skewBy:(NSPoint)by around:(NSPoint)around;  // Skew an object by an arbitrary amount
- (void) stepBackwardBy:(NSInteger)by;  // Move the current time backward
- (void) stepForwardBy:(NSInteger)by;  // Move the current time forward
- (void) stop;  // Stop playing or recording a movie.
- (void) translateBy:(NSPoint)by;  // Translate the object some distance
- (void) trim;  // Remove all content before and after the current selection
- (void) start;  // Start playing or recording a movie.
- (void) pause;  // Pause a movie or recording.
- (void) newAudioRecording;  // Create a new audio recording.
- (void) newMovieRecording;  // Create a new movie recording.

@end

// A reference to recently viewed QuickTime content
@interface QuickTimePlayer7RecentItem : SBObject

@property (readonly) QuickTimePlayer7Bkmt kind;  // the kind of the recent item
@property (copy, readonly) NSString *name;  // the name of the recent item

- (void) closeSaving:(QuickTimePlayer7Savo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(QuickTimePlayer7Recording *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save an object.
- (void) addScaled:(BOOL)scaled;  // Add an object from the clipboard in parallel to the current selection
- (void) clear;  // Clear the current selection
- (void) copy;  // Copy an object to the clipboard
- (void) cut;  // Cut an object to the clipboard
- (BOOL) canExportAs:(QuickTimePlayer7Expk)as;  // Determine if a movie or track can be exported to the desired type
- (void) exportTo:(NSURL *)to as:(QuickTimePlayer7Expk)as using:(QuickTimePlayer7Exps)using_ usingSettingsPreset:(NSString *)usingSettingsPreset usingSettings:(NSURL *)usingSettings replacing:(BOOL)replacing;  // Export a movie or track to a file
- (NSInteger) findText:(NSString *)text backwards:(BOOL)backwards;  // Find text in a movie
- (void) flipHorizontal;  // Flip an object along the horizontal axis
- (void) flipVertical;  // Flip an object along the vertical axis
- (void) getURL;  // Play a movie from a URL
- (void) invert;  // Invert an object
- (QuickTimePlayer7Document *) openLocationPosition:(NSPoint)position;  // Play the specified internet location(s)
- (void) paste;  // Paste an object from the clipboard
- (void) presentScale:(QuickTimePlayer7Mvsz)scale mode:(QuickTimePlayer7Prmd)mode display:(NSInteger)display backgroundColor:(QuickTimePlayer7RgbColor *)backgroundColor;  // Present a movie
- (void) redo;  // Redo the action of the previous event or user interaction
- (void) replace;  // Replace the current selection with an object from the clipboard
- (void) resizeBy:(double)by around:(NSPoint)around;  // Scale an object
- (void) rewind;  // Rewind a movie to the beginning
- (void) rotateBy:(double)by around:(NSPoint)around;  // Rotate an object by an arbitrary amount
- (void) rotateLeft;  // Rotate an object 90¡ left
- (void) rotateRight;  // Rotate an object 90¡ right
- (void) selectAt:(NSInteger)at to:(NSInteger)to;  // Select a range of time
- (void) selectAll;  // Select the entire movie
- (void) selectNone;  // Set the selection of the movie to nothing
- (void) skewBy:(NSPoint)by around:(NSPoint)around;  // Skew an object by an arbitrary amount
- (void) stepBackwardBy:(NSInteger)by;  // Move the current time backward
- (void) stepForwardBy:(NSInteger)by;  // Move the current time forward
- (void) stop;  // Stop playing or recording a movie.
- (void) translateBy:(NSPoint)by;  // Translate the object some distance
- (void) trim;  // Remove all content before and after the current selection
- (void) start;  // Start playing or recording a movie.
- (void) pause;  // Pause a movie or recording.
- (void) newAudioRecording;  // Create a new audio recording.
- (void) newMovieRecording;  // Create a new movie recording.

@end

// An RGB color
@interface QuickTimePlayer7RgbColor : SBObject

@property (copy) NSArray *contents;  // the contents of the rgb color
@property NSInteger red;  // the magnitude of the red component (0..65535)
@property NSInteger green;  // the magnitude of the green component (0..65535)
@property NSInteger blue;  // the magnitude of the blue component (0..65535)

- (void) closeSaving:(QuickTimePlayer7Savo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(QuickTimePlayer7Recording *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save an object.
- (void) addScaled:(BOOL)scaled;  // Add an object from the clipboard in parallel to the current selection
- (void) clear;  // Clear the current selection
- (void) copy;  // Copy an object to the clipboard
- (void) cut;  // Cut an object to the clipboard
- (BOOL) canExportAs:(QuickTimePlayer7Expk)as;  // Determine if a movie or track can be exported to the desired type
- (void) exportTo:(NSURL *)to as:(QuickTimePlayer7Expk)as using:(QuickTimePlayer7Exps)using_ usingSettingsPreset:(NSString *)usingSettingsPreset usingSettings:(NSURL *)usingSettings replacing:(BOOL)replacing;  // Export a movie or track to a file
- (NSInteger) findText:(NSString *)text backwards:(BOOL)backwards;  // Find text in a movie
- (void) flipHorizontal;  // Flip an object along the horizontal axis
- (void) flipVertical;  // Flip an object along the vertical axis
- (void) getURL;  // Play a movie from a URL
- (void) invert;  // Invert an object
- (QuickTimePlayer7Document *) openLocationPosition:(NSPoint)position;  // Play the specified internet location(s)
- (void) paste;  // Paste an object from the clipboard
- (void) presentScale:(QuickTimePlayer7Mvsz)scale mode:(QuickTimePlayer7Prmd)mode display:(NSInteger)display backgroundColor:(QuickTimePlayer7RgbColor *)backgroundColor;  // Present a movie
- (void) redo;  // Redo the action of the previous event or user interaction
- (void) replace;  // Replace the current selection with an object from the clipboard
- (void) resizeBy:(double)by around:(NSPoint)around;  // Scale an object
- (void) rewind;  // Rewind a movie to the beginning
- (void) rotateBy:(double)by around:(NSPoint)around;  // Rotate an object by an arbitrary amount
- (void) rotateLeft;  // Rotate an object 90¡ left
- (void) rotateRight;  // Rotate an object 90¡ right
- (void) selectAt:(NSInteger)at to:(NSInteger)to;  // Select a range of time
- (void) selectAll;  // Select the entire movie
- (void) selectNone;  // Set the selection of the movie to nothing
- (void) skewBy:(NSPoint)by around:(NSPoint)around;  // Skew an object by an arbitrary amount
- (void) stepBackwardBy:(NSInteger)by;  // Move the current time backward
- (void) stepForwardBy:(NSInteger)by;  // Move the current time forward
- (void) stop;  // Stop playing or recording a movie.
- (void) translateBy:(NSPoint)by;  // Translate the object some distance
- (void) trim;  // Remove all content before and after the current selection
- (void) start;  // Start playing or recording a movie.
- (void) pause;  // Pause a movie or recording.
- (void) newAudioRecording;  // Create a new audio recording.
- (void) newMovieRecording;  // Create a new movie recording.

@end

// a stream within a streaming track
@interface QuickTimePlayer7Stream : SBObject

@property (readonly) NSInteger audioChannelCount;  // the number of channels in the audio
@property (readonly) double audioSampleRate;  // the sample rate of the audio
@property (readonly) NSInteger audioSampleSize;  // the size of decompressed audio samples
@property (copy, readonly) NSString *dataFormat;  // the data format
@property (readonly) BOOL isVideoGrayScale;  // is the video gray scale?
@property (copy, readonly) NSString *kind;  // the name of the media in the stream, in the current language (e.g., 'Sound', 'Video', 'Text', ...)
@property (copy, readonly) NSString *type;  // the type of media in the stream (e.g., 'soun', 'vide', 'text', ...)
@property (readonly) NSInteger videoDepth;  // the color depth of the video

- (void) closeSaving:(QuickTimePlayer7Savo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(QuickTimePlayer7Recording *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveIn:(NSURL *)in_ as:(NSString *)as;  // Save an object.
- (void) addScaled:(BOOL)scaled;  // Add an object from the clipboard in parallel to the current selection
- (void) clear;  // Clear the current selection
- (void) copy;  // Copy an object to the clipboard
- (void) cut;  // Cut an object to the clipboard
- (BOOL) canExportAs:(QuickTimePlayer7Expk)as;  // Determine if a movie or track can be exported to the desired type
- (void) exportTo:(NSURL *)to as:(QuickTimePlayer7Expk)as using:(QuickTimePlayer7Exps)using_ usingSettingsPreset:(NSString *)usingSettingsPreset usingSettings:(NSURL *)usingSettings replacing:(BOOL)replacing;  // Export a movie or track to a file
- (NSInteger) findText:(NSString *)text backwards:(BOOL)backwards;  // Find text in a movie
- (void) flipHorizontal;  // Flip an object along the horizontal axis
- (void) flipVertical;  // Flip an object along the vertical axis
- (void) getURL;  // Play a movie from a URL
- (void) invert;  // Invert an object
- (QuickTimePlayer7Document *) openLocationPosition:(NSPoint)position;  // Play the specified internet location(s)
- (void) paste;  // Paste an object from the clipboard
- (void) presentScale:(QuickTimePlayer7Mvsz)scale mode:(QuickTimePlayer7Prmd)mode display:(NSInteger)display backgroundColor:(QuickTimePlayer7RgbColor *)backgroundColor;  // Present a movie
- (void) redo;  // Redo the action of the previous event or user interaction
- (void) replace;  // Replace the current selection with an object from the clipboard
- (void) resizeBy:(double)by around:(NSPoint)around;  // Scale an object
- (void) rewind;  // Rewind a movie to the beginning
- (void) rotateBy:(double)by around:(NSPoint)around;  // Rotate an object by an arbitrary amount
- (void) rotateLeft;  // Rotate an object 90¡ left
- (void) rotateRight;  // Rotate an object 90¡ right
- (void) selectAt:(NSInteger)at to:(NSInteger)to;  // Select a range of time
- (void) selectAll;  // Select the entire movie
- (void) selectNone;  // Set the selection of the movie to nothing
- (void) skewBy:(NSPoint)by around:(NSPoint)around;  // Skew an object by an arbitrary amount
- (void) stepBackwardBy:(NSInteger)by;  // Move the current time backward
- (void) stepForwardBy:(NSInteger)by;  // Move the current time forward
- (void) stop;  // Stop playing or recording a movie.
- (void) translateBy:(NSPoint)by;  // Translate the object some distance
- (void) trim;  // Remove all content before and after the current selection
- (void) start;  // Start playing or recording a movie.
- (void) pause;  // Pause a movie or recording.
- (void) newAudioRecording;  // Create a new audio recording.
- (void) newMovieRecording;  // Create a new movie recording.

@end

// A reference to a text frame in a QuickTime text track.
@interface QuickTimePlayer7TextFrame : QuickTimePlayer7Frame

@property BOOL antialias;  // anti-alias text against background
@property BOOL autoScale;  // should text auto scale with track dimensions
@property (copy) QuickTimePlayer7RgbColor *backgroundColor;  // the background color of the text frame, e.g. {0, 0, 65535}, the rgb value for blue
@property BOOL clipToTextBox;  // draw only the text box
@property (copy) NSString *defaultFont;  // the name of the default font
@property NSInteger defaultFontSize;  // the default font size of the text frame
@property QuickTimePlayer7Styl defaultFontStyles;  // the default font styles of the text frame
@property NSPoint dimensions;  // the dimensions of the text frame
@property BOOL dropShadow;  // should text be drawn with a drop shadow?
@property NSPoint dropShadowOffset;  // the drop shadow offset of the text frame
@property NSInteger dropShadowTransparency;  // the drop shadow transparency of the text frame (0..255), where 255 is 100% opaque
@property (copy) QuickTimePlayer7RgbColor *foregroundColor;  // the foreground color of the text frame
@property NSPoint highlight;  // the highlight of the text frame
@property (copy) QuickTimePlayer7RgbColor *highlightColor;  // the highlight color of the text frame
@property BOOL inverseHighlighting;  // invert colors to indicate highlighting
@property QuickTimePlayer7Just justification;  // the justification of the text frame
@property BOOL keyed;  // render text over background
@property (copy, readonly) NSString *kind;  // the kind of text in the text track
@property NSPoint position;  // the position of the text frame
@property (copy) NSString *sampleData;  // the text contents of the text frame
@property QuickTimePlayer7Txop scroll;  // a list of scroll settings for the text frame
@property NSInteger scrollDelay;  // the scroll delay of the text frame
@property BOOL shrinkTextBox;  // calculate minimum text box
@property BOOL textColorHighlighting;  // change text color to indicate highlighting


@end

// A reference to a chapter in a QuickTime movie.
@interface QuickTimePlayer7Chapter : QuickTimePlayer7TextFrame

@property (copy) NSString *name;  // the name of the chapter


@end

// A track in a QuickTime movie
@interface QuickTimePlayer7Track : QuickTimePlayer7Item

- (SBElementArray *) annotations;
- (SBElementArray *) frames;
- (SBElementArray *) streams;
- (SBElementArray *) textFrames;
- (SBElementArray *) chapters;

@property (copy, readonly) NSArray *alternate;  // the alternate for this track
@property (readonly) NSInteger audioChannelCount;  // the number of channels in the audio
@property (readonly) BOOL audioCharacteristic;  // can the track be heard?
@property (readonly) double audioSampleRate;  // the sample rate of the audio in kHz
@property (readonly) NSInteger audioSampleSize;  // the size of uncompressed audio samples in bits
@property NSInteger bassGain;  // the bass setting for the track (-256..256) (not saved with movie)
@property (copy) NSArray *chapterlist;  // text track to use as chapter list for this track
@property (copy) id contents;  // the contents of the track
@property (copy) NSArray *currentMatrix;  // the matrix of the track
@property (copy, readonly) NSString *dataFormat;  // the data format
@property (readonly) NSInteger dataRate;  // the data rate (bytes/sec) of the track
@property (readonly) NSInteger dataSize;  // the data size (in bytes) of the track
@property BOOL deinterlaceFields;  // is the visual track deinterlaced?
@property NSPoint dimensions;  // the current dimensions of the track
@property (readonly) NSInteger duration;  // the duration of the track
@property BOOL enabled;  // should this track be used when the movie is playing?
@property BOOL highQuality;  // is the track high quality?
@property (copy) NSString *href;  // the internet location to open when clicking on the track
- (NSInteger) id;  // the unique identifier for this track
@property (readonly) NSInteger index;  // the index of the track
@property (readonly) BOOL isVideoGrayScale;  // is the video gray scale?
@property (copy, readonly) NSString *kind;  // the name of the media in the track, in the current language (e.g., 'Sound', 'Video', 'Text', ...)
@property (copy) NSURL *mask;  // the mask of the track
@property NSInteger layer;  // the layer of the track
@property (copy) NSString *name;  // the name of the track
@property (readonly) NSPoint naturalDimensions;  // the dimensions the track has when it is not scaled
@property BOOL neverPurge;  // never purge the track?
@property (copy) QuickTimePlayer7RgbColor *operationColor;  // the operation color of the track - not all transfer modes use this value
@property NSPoint position;  // the position of the track
@property BOOL preload;  // should the track be preloaded?
@property BOOL singleField;  // is the visual track single field?
@property NSInteger soundBalance;  // the balance of the track (-128..128), where negative is left, 0 is center, and positive is right
@property NSInteger soundVolume;  // the volume of the track (0..512), where 256 is 100%
@property NSInteger startTime;  // the time delay before this track starts playing
@property (readonly) double streamingBitRate;  // bit rate in bits/second for all streams in track
@property (readonly) double streamingQuality;  // percent of packets received for all streams in track
@property QuickTimePlayer7Tran transferMode;  // the transfer mode of the track
@property NSInteger transparency;  // the transparency setting for the track (0..100 percent), where 0 is totally opaque
@property NSInteger trebleGain;  // the treble setting for the track (-256..256) (not saved with movie)
@property (copy, readonly) NSString *type;  // the type of media in the track (e.g., 'soun', 'vide', 'text', ...)
@property (readonly) NSInteger videoDepth;  // the color depth of the video
@property (readonly) BOOL visualCharacteristic;  // can the track be seen?


@end

