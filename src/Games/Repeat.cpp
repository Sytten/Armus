#include "Games/Games.h"

void repeatSongSelection()
{
	AUDIO_PlayFile(VOIX_REPEAT);
	LCD_ClearAndPrint("Bonne chance!\n");
	LCD_Printf("1\n");
	THREAD_MSleep(1000);
	LCD_Printf("2\n");
	THREAD_MSleep(1000);
	LCD_Printf("3\n");
	THREAD_MSleep(1000);
	LCD_Printf("GO!!!\n");

	int songSelect = rand()%4 + 1;

	switch (songSelect)
	{
		case 1:
			repeat(PATH_CLAIRE_FONTAINE);
			break;
		case 2:
			repeat(PATH_HYMNE_A_LA_JOIE);
			break;
		case 3:
			repeat(PATH_STAR_WARS);
			break;
		case 4:
			repeat(PATH_RENNE_NEZ_ROUGE);
			break;
		default:
			break;
	}
}

void repeat(const char * path)
{
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

	SongSequenceData song = readSongFile(path);		//Song qui represente le fichier du morceau

	char readValue;				//Valeur lue sur le multiplexeur
	float noteStartTime;		//float representant le depart de la programmation

	for(int i = 0; i < song.size; i++)
	{
		OpenLEDForNotes(song.noteSequences[i].note);
		noteStartTime = SYSTEM_ReadTimerMSeconds();

		while(noteStartTime + song.noteSequences[i].delay > SYSTEM_ReadTimerMSeconds())
		{
			CheckPressedKeys(&stream);
			PlayAndStopNotes(&stream);
		}
	}

	ResetStream(&stream);
	PlayAndStopNotes(&stream);
}


