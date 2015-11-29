#include "Games/Games.h"

void repeatSongSelection()
{
	AUDIO_PlayFile(VOIX_REPEAT);

	srand(time(NULL));
	int songSelect = rand()%3 + 1;

	switch (songSelect)
	{
		case 1:
			repeat(PATH_CLAIRE_FONTAINE);
			break;
		case 2:
			repeat(PATH_CLAIRE_FONTAINE);
			//repeat(PATH_HYMNE_A_LA_JOIE);
			break;
		case 3:
			repeat(PATH_CLAIRE_FONTAINE);
			//repeat(PATH_STAR_WARS);
			break;
		default:
			break;
	}
}

void repeat(char * path)
{
	SongSequenceData song = readSongFile(path);		//Song qui repr�sente le fichier du morceau

	char readValue;				//Valeur lue sur le multiplexeur
	unsigned int streamID;		//Represente le ID du stream musical jou�
	float noteStartTime;		//float repr�sentant le d�part de la programmation


	for(int i = 0; i < song.size; i++)
	{
		OpenLEDForNotes(song.noteSequences[i].note);
		noteStartTime = SYSTEM_ReadTimerMSeconds();
		while(noteStartTime + song.noteSequences[i].delay > SYSTEM_ReadTimerMSeconds())
		{
			readValue = readMux(9, 10, 15, 16);

			for(int j = 7; j >= 0; j--)
			{
				if(isNotePressed(j, readValue))
				{
					LCD_Printf("Playing note");
					//streamID = PlayNote(j);
				}
			}
		}
		//StopNote(streamID);
	}
}



