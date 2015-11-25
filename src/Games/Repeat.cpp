#include "Games/Games.h"

void repeatSongSelection()
{
	srand(time(NULL));
	int songSelect = rand()%3 + 1;

	switch (songSelect) {
		case 1:
			repeat(PATH_CLAIRE_FONTAINE);
			break;
		case 2:
			repeat(PATH_HYMNE_A_LA_JOIE);
			break;
		case 3:
			repeat(PATH_STAR_WARS);
			break;
		default:
			break;
	}
}

void repeat(char * path)
{
	SongSequenceData song = readSongFile(path);		//Song qui représente le fichier du morceau

	char readValue;				//Valeur lue sur le multiplexeur
	unsigned int streamID;		//Represente le ID du stream musical joué
	float noteStartTime;		//float représentant le départ de la programmation


	for(int i = 0; i < song.size; i++)
	{
		noteStartTime = SYSTEM_ReadTimerMSeconds();
		OpenLEDForNotes(song.noteSequences[i].note);
		while(noteStartTime + song.noteSequences[i].delay > SYSTEM_ReadTimerMSeconds())
		{
			readValue = readMux(9, 10, 15, 16);

			for(int j = 7; j >= 0; j--)
			{
				if(isNotePressed(j, readValue))
				{
					streamID = PlayNote(j);
				}
			}
		}
		StopNote(streamID);
	}
}



