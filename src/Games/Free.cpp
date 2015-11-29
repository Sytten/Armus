#include "Games/Games.h"
#include <iostream>

bool freePlay()
{
	AllLED(VERT);

	PianoStreams pianoStreams;

	pianoStreams.size = PIANO_SIZE;
	pianoStreams.testID = -1;
	pianoStreams.storedNote = -1;

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
		//CheckStreamIsPlaying(&pianoStreams);
		//StopNotes(&pianoStreams);
		//PlayNotes(&pianoStreams);

		for(int i = 7; i >= 0; i--)
				{
					if(pianoStreams.streams[i].keyPressed == true)
					{
						if(pianoStreams.streams[i].firstTime == true)
						{
							pianoStreams.streams[i].firstTime = false;

							if(pianoStreams.testID != -1)
							{
								THREAD_MSleep(40);
								StopNote(pianoStreams.testID);
								cout << "Stopped\n";
							}

							pianoStreams.testID = PlayNote(pianoStreams.streams[i].note);
							pianoStreams.storedNote = i;
							cout << "Started\n";
						}
						break;
					}
					else
					{
						if(pianoStreams.storedNote == i && pianoStreams.testID != -1)
						{
							THREAD_MSleep(40);
							StopNote(pianoStreams.testID);
							pianoStreams.testID = -1;
							pianoStreams.storedNote = -1;
						}
					}
				}

		THREAD_MSleep(10);
		if(DIGITALIO_Read(BMP_REAR))
			break;
		//Ajouter check bouton pour quitter mode de jeu // j'avais mis BMP_LEFT. (spino)
	}

	return true;
}

