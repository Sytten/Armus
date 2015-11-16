#include "PianoControl.h"
#include "Notes.h"

bool updatePianoStreams()
{
	Stream temp_notes[8] = {{false, false, VAL_DO1, 0},
							{false, false, VAL_RE, 0},
							{false, false, VAL_MI, 0},
							{false, false, VAL_FA, 0},
							{false, false, VAL_SOL, 0},
							{false, false, VAL_LA, 0},
							{false, false, VAL_SI, 0},
							{false, false, VAL_DO2, 0}};

	PianoStreams temps_streams;

	temps_streams.size = 8;
	temps_streams.streams = temp_notes;

	return true;
}


