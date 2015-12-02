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

//Represents à piano note
struct Note
{
	bool keyPressed;
	bool firstTime;

	int note;
};

//Represents the whole piano and keeps in memory the played note sound stream ID
struct PianoStream
{
	Note *notes;

	int size;
	int streamID;
	int currentNote;
};

/**
 * Plays and stop note sounds. Trys to assure no notes are played and stopped to fast and cause segfaults
 * @param stream PianoStream to manage
 */
void PlayAndStopNotes(PianoStream * stream);

/**
 * Reset all stream values to 0. Used to reinitialise the piano to 0 for game mode changing
 * @param stream PianoStream to init back to 0
 */
void ResetStream(PianoStream * stream);

#endif /*AUDIOCONTROLLER_H_*/
