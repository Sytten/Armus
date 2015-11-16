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

#include "PlaySound/Notes.h"

struct Stream
{
	bool keyPressed = false;
	bool streamPlaying = false;
	int note = 0;
	int streamID = 0;
};

struct PianoStreams
{
	Stream streams[8] = {{false, false, VAL_DO1, 0},
						 {false, false, VAL_RE, 0},
						 {false, false, VAL_MI, 0},
						 {false, false, VAL_FA, 0},
						 {false, false, VAL_SOL, 0},
						 {false, false, VAL_LA, 0},
						 {false, false, VAL_SI, 0},
						 {false, false, VAL_DO2, 0}};
	int size = 8;
};

#endif
