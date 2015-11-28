#include "Games/Games.h"


bool freePlay()
{
	AUDIO_PlayFile(VOIX_FREE);

	PianoStreams pianoStreams;

	pianoStreams.size = PIANO_SIZE;

	Stream pianoNotes[PIANO_SIZE] = {{false, false, true, -1, VAL_DO1, 0},
									 {false, false, true, -1, VAL_RE, 0},
									 {false, false, true, -1, VAL_MI, 0},
									 {false, false, true, -1, VAL_FA, 0},
									 {false, false, true, -1, VAL_SOL, 0},
									 {false, false, true, -1, VAL_LA, 0},
									 {false, false, true, -1, VAL_SI, 0},
									 {false, false, true, -1, VAL_DO2, 0}};

	pianoStreams.streams = pianoNotes;

	AUDIO_SetVolume(20);

	while(1)
	{
		CheckPressedKeys(&pianoStreams);
		CheckStreamIsPlaying(&pianoStreams);
		StopNotes(&pianoStreams);
		PlayNotes(&pianoStreams);

		THREAD_MSleep(50);
		if(DIGITALIO_Read(BMP_REAR))
			break;
		//Ajouter check bouton pour quitter mode de jeu // j'avais mis BMP_LEFT. (spino)
	}

	return true;
}

