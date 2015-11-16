/*
============================================================================
 Name : PianoStreams
 Author : M.A.G.I.E Team
 Modified on: 2015-11-16
 Description : Helper structure to store information about the status of the inputs (piano)
			   and the outputs (speaker).
============================================================================
*/

#ifndef PIANOSTREAMS_H
#define PIANOSTREAMS_H

#include "Notes.h"

struct Stream
{
	bool keyPressed;
	bool streamPlaying;
	int note;
	int streamID;
};

struct PianoStreams
{
	Stream *streams;
	int size;
};

#endif


