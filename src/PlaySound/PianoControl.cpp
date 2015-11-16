#include "PlaySound/PianoControl.h"
#include "PlaySound/PianoStreams.h"
#include "PlaySound/PlaySounds.h"
#include "Sensors/PianoNotes.h"
#include "PlaySound/Notes.h"

#define PIANO_SIZE 8

bool updatePianoStreams()
{


	PianoStreams pianoStreams;

	pianoStreams.size = PIANO_SIZE;

	Stream pianoNotes[PIANO_SIZE] = {{false, false, VAL_DO1, 0},
								{false, false, VAL_RE, 0},
								{false, false, VAL_MI, 0},
								{false, false, VAL_FA, 0},
								{false, false, VAL_SOL, 0},
								{false, false, VAL_LA, 0},
								{false, false, VAL_SI, 0},
								{false, false, VAL_DO2, 0}};

	pianoStreams.streams = pianoNotes;

	AUDIO_SetVolume(100);

	CheckPressedKeys(&pianoStreams);
	PlayNotes(&pianoStreams);

	while(1)
	{
		CheckPressedKeys(&pianoStreams);
		CheckStreamIsPlaying(&pianoStreams);
		StopNotes(&pianoStreams);
		PlayNotes(&pianoStreams);
	}

	return true;
}


