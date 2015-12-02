#include "Behaviors/Behaviors.h"

void wander()
{
	bool finished = false;
	int soundID = AUDIO_PlayFile(VOIX_WANDER);
	float timer = SYSTEM_ReadTimerMSeconds();
	float distanceToPlayer = 0;
	char notes;

	//Make the robot turn right
	MOTOR_SetSpeed(MOTOR_LEFT, 70);
	MOTOR_SetSpeed(MOTOR_RIGHT, 50);

	//While a player has not been detected or the player has not touched a note
	while(!finished)
	{
		if(AUDIO_IsPlaybackDone(soundID) && (timer + 3000 < SYSTEM_ReadTimerMSeconds()))
		{
			soundID = AUDIO_PlayFile(VOIX_WANDER);
			timer = SYSTEM_ReadTimerMSeconds();
		};

		distanceToPlayer = SONAR_Detect(1);
		if(distanceToPlayer > 0.1 && distanceToPlayer < 50.0)
			finished = true;

		notes = readMux(9, 10, 15, 16);
		if (notes != 255)
			finished = true;

		if(ButtonStatus(1) == 1 || ButtonStatus(2) == 1 || ButtonStatus(3) == 1)
			finished = true;

		THREAD_MSleep(50);
	}

	AUDIO_StopPlayback(soundID);

	//Stop the motors
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
}



