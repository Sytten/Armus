#include "Behaviors/Behaviors.h"

void stay()
{
	bool finished = false;
	int soundID = AUDIO_PlayFile(VOIX_WANDER);

	float timer = SYSTEM_ReadTimerMSeconds();

	char notes = 0;

	while(!finished)
	{
		if(AUDIO_IsPlaybackDone(soundID) && (timer + 3000 < SYSTEM_ReadTimerMSeconds()))
		{
			soundID = AUDIO_PlayFile(VOIX_WANDER);
			timer = SYSTEM_ReadTimerMSeconds();
		}

		notes = readMux(9, 10, 15, 16);
		if (notes != 255)
			finished = true;

		if(ButtonStatus(1) == 1 || ButtonStatus(2) == 1 || ButtonStatus(3) == 1)
			finished = true;

		THREAD_MSleep(50);
	}

	AUDIO_StopPlayback(soundID);
}

