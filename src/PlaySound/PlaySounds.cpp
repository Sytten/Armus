#include "PlaySound/PlaySounds.h"

int PlayNotes(PianoStreams * piano)
{
	int returnedValue = 0;

	//Boucle de démarrage des sons
	for(int i = 7; i >= 0; i--)
	{
		if(piano->streams[i].keyPressed == true && piano->streams[i].firstTime == true)
		{
			piano->streams[i].firstTime = false;

			if(piano->streams[i].streamPlaying == true)
				StopNote(piano->streams[i].streamID);
			else
				piano->streams[i].streamPlaying = true;

			piano->streams[i].streamID = PlayNote(piano->streams[i].note);
		}
	}

	return returnedValue;
}

int StopNotes(PianoStreams* piano)
{
	int returnedValue = 0;

	//Boucle de fermeture des sons
	for(int i = 7; i >= 0; i--)
	{
		//Fermeture des sons et modification du bool
		if (piano->streams[i].keyPressed == false && piano->streams[i].streamPlaying == true)
		{
			LCD_Printf("Starting closure\n Time: %f\n", piano->streams[i].timeKeyReleased);

			if(piano->streams[i].timeKeyReleased < 0)
				piano->streams[i].timeKeyReleased = SYSTEM_ReadTimerMSeconds();

			else if(SYSTEM_ReadTimerMSeconds() > (piano->streams[i].timeKeyReleased + 500))
			{
				StopNote(piano->streams[i].streamID);
				piano->streams[i].streamPlaying = false;
				piano->streams[i].timeKeyReleased = -1;
			}
		}
	}

	return returnedValue;
}

int CheckStreamIsPlaying(PianoStreams * piano)
{
	int returnedValue = 0;

	for(int i = 7; i >= 0; i--)
	{
		if(piano->streams[i].streamPlaying)
		{
			piano->streams[i].streamPlaying = !AUDIO_IsPlaybackDone(piano->streams[i].streamID);
		}
	}

	return returnedValue;
}
