SubTTS for Mac
==============

SubTTS reads a movie subtitles file, and uses the built-in speech synthesiser 
to read the subtitles aloud while you are watching the movie. 

The program is a standalone "Menulet", a program that sits in the menu bar 
and talks to your favourite video player. 
Currently it supports Quicktime Player X, Quicktime Player 7, VLC Player, and DVD Player.
It should work for Mac OSX 10.6 and above.

Download and install
--------------------

The latest release can be downloaded from 
[Googlecode](http://code.google.com/p/subtts/downloads).

To install, just move the program to your Applications directory.

To use, just double-click on the program icon, as you normally do.

Install from source
-------------------

If you want the latest development snapshot, you have to install from the source code.
Open a Terminal window and do the following:

	cd ... (someplace where you want the source code to be)
	git clone git://github.com/... (URL to the repo, or use the free GitHub.app)
	cd subtts-mac
	git submodule update --init --recursive
	open SubTTS.xcodeproj

Hit `Command-R` to build and run the project in Xcode. 
You need to download and install Xcode from the Mac App store. 

License
-------

SubTTS is open-source and released under a dual GPL/BSD license:
- GNU General Public License, version 3.0 or above. See COPYING.GNU for details.
- The Simplified BSD License. See COPYING.BSD for details.

Windows/Linux version
---------------------

There is a completely different version (based on the same concept) for Windows/Linux, which can be downloaded from 
http://code.google.com/p/subtts/

More information
----------------

The program was developed during the research project "Pratmakaren", 
hosted by [DART](http://www.dart-gbg.org/english) at Sahlgrenska University Hospital,
and [CLT](http://clt.gu.se) at the University of Gothenburg.
The project was financed by the Swedish Post and Telecom Authority.

The underlying idea is described in the following publication:

Peter Ljunglöf, Sandra Derbring and Maria Olsson (2012). 
A free and open-source tool that reads movie subtitles aloud. 
In proceedings of *SLPAT'12: 3rd Workshop on Speech and Language Processing for Assistive Technologies*, 
Montréal, Canada, June 2012.
Can be downloaded from http://www.cse.chalmers.se/~peb/bibliography.html
