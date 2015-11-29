#include "Games/Games.h"

bool freePlay()
{
	AUDIO_PlayFile(VOIX_FREE);
	LCD_ClearAndPrint("Amuse toi bien!");

    AllLED(VERT);

	PianoStream stream;

	stream.size = PIANO_SIZE;
	stream.streamID = -1;
	stream.currentNote = -1;

	Note notes[PIANO_SIZE] = {{false, true, VAL_DO1},
							  {false, true, VAL_RE},
							  {false, true, VAL_MI},
							  {false, true, VAL_FA},
							  {false, true, VAL_SOL},
							  {false, true, VAL_LA},
							  {false, true, VAL_SI},
							  {false, true, VAL_DO2}};
	stream.notes = notes;

	AUDIO_SetVolume(50);

	while(1)
	{
		CheckPressedKeys(&stream);
		PlayAndStopNotes(&stream);

		THREAD_MSleep(10);
		if(ButtonStatus(1) == 1 || ButtonStatus(2) == 1 || ButtonStatus(3) == 1)
			break;
	}

	return true;
}

