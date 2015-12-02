#include "Games/Games.h"

#define NOTES_TO_SKIP 3
#define WAIT_DELAY 100
#define WAIT_TRYS 5

bool sequence()
{
	int songSelect = rand()%4 + 1;
	SongSequenceData song;
	switch (songSelect)
	{
		case 1:
			song = readSongFile(PATH_KOKIRI);
			break;
		case 2:
			song = readSongFile(PATH_FLINSTONES);
			break;
		case 3:
			song = readSongFile(PATH_STAR_WARS);
			break;
		case 4:
			song = readSongFile(PATH_CONTEMPORAIN);
			break;
		default:
			break;
	}

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

	int streamID = -1;
	int currentNote = 1;
	bool wasCorrect = false;
	char readValue;

	LCD_ClearAndPrint("Rejoue la suite de notes!\n");
	LCD_ClearAndPrint("Appuie sur un des trois boutons pour revenir au menu.\n");
	AUDIO_PlayFile(VOIX_SEQUENCE);

	LCD_Printf("1\n");
	THREAD_MSleep(1000);
	LCD_Printf("2\n");
	THREAD_MSleep(1000);
	LCD_Printf("3\n");
	THREAD_MSleep(1000);
	LCD_Printf("GO!!!\n");
	THREAD_MSleep(1000);

	while(currentNote < song.size)
	{
		for(int i = 0; i < song.size && i < currentNote; i++)
		{
			for(int j = 7; j >= 0; j--)
			{
				if(isNotePressed(j, song.noteSequences[i].note))
				{
					streamID = PlayNote(j);
				}
			}
			OpenLEDForNotes(song.noteSequences[i].note);
			THREAD_MSleep(song.noteSequences[i].delay);
			THREAD_MSleep(50);
			if(streamID != -1)
			{
				StopNote(streamID);
				streamID = -1;
			}

		}
		AllLED(ETEINDRE);

		for(int i = 0; i < song.size && i < currentNote; i++)
		{
			wasCorrect = false;
			while(!wasCorrect)
			{
				CheckPressedKeys(&stream);

				if(StreamToValue(&stream) == song.noteSequences[i].note)
				{
					wasCorrect = true;
					for(int j = 7; j >= 0; j--)
					{
						if(isNotePressed(j, song.noteSequences[i].note))
						{
							stream.notes[j].firstTime = false;
							stream.streamID = PlayNote(j);
							stream.currentNote = j;
						}
					}
					OpenLEDForNotes(song.noteSequences[i].note);
				}
				else if(StreamToValue(&stream) != 255)
				{
						AllLED(ROUGE);
						LCD_ClearAndPrint("Meilleure chance la prochaine fois!");
						THREAD_MSleep(2000);
						return false;
				}


			}
			THREAD_MSleep(song.noteSequences[i].delay);
			if(stream.streamID != -1)
			{
				THREAD_MSleep(50);
				StopNote(stream.streamID);
				stream.streamID = -1;
				stream.currentNote = -1;
			}
		}
		AllLED(VERT);
		THREAD_MSleep(500);
		AllLED(ETEINDRE);
		THREAD_MSleep(500);
		currentNote++;
	}

	AllLED(VERT);
	LCD_ClearAndPrint("Bravo, tu as reussi!");
	THREAD_MSleep(500);
	AllLED(ETEINDRE);
	THREAD_MSleep(100);
	AllLED(VERT);
	THREAD_MSleep(500);
	AllLED(ETEINDRE);
	THREAD_MSleep(100);
	AllLED(VERT);
	THREAD_MSleep(500);
	AllLED(ETEINDRE);
	THREAD_MSleep(100);
	AllLED(VERT);
	THREAD_MSleep(500);

	return true;
}




