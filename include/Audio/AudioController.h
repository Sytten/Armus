/*
============================================================================
 Name : AudioController
 Author : M.A.G.I.E Team
 Modified on: 2015-11-29
 Description : Audio controller allows us to manage the multiple inputs of the
 	 	 	   piano and play/stop the corresponding sounds.
============================================================================
*/

#ifndef AUDIOCONTROLLER_H_
#define AUDIOCONTROLLER_H_

#include "Audio/AudioPlayer.h"
#include "Audio/Notes.h"

struct Note
{
	bool keyPressed;
	bool firstTime;
	int note;
};

struct PianoStream
{
	Note *notes;
	int size;

	int streamID;
	int currentNote;
};

int PlayAndStopNotes(PianoStream * piano);

#endif /*AUDIOCONTROLLER_H_*/
