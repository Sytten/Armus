#include "Behaviors/Behaviors.h"

void stay()
{
	bool finished = false;
	int soundID = AUDIO_PlayFile("do_16b.wav");

	char notes = 0;

	while(!finished)
	{
		if(AUDIO_IsPlaybackDone(soundID));
			soundID = AUDIO_PlayFile("do_16b.wav");

		notes = readMux(9, 10, 15, 16);
		if (notes != 255)
			finished = true;

		THREAD_MSleep(50);
	}
}

