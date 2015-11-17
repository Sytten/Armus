#include "Behaviors/Behaviors.h"

void wander()
{
	bool finished = false;
	int soundID = AUDIO_PlayFile("do_16b.wav");
	float distanceToPlayer = 0;
	char notes;
	RollVariables rollData;
		rollData.distance = 1000000;
		rollData.firstTime = true;

	while(!finished)
	{
		if(AUDIO_IsPlaybackDone(soundID))
			soundID = AUDIO_PlayFile("do_16b.wav");

		if(isLeftDetect() && !isRightDetect())
			spinXDegreesByHoles(SPIN_RIGHT, 100);
		else if(isRightDetect() && !isLeftDetect())
			spinXDegreesByHoles(SPIN_LEFT, 100);
		else if(isCenterDetect())
			spinXDegreesByHoles(SPIN_LEFT, 180);

		roll(&rollData);
		distanceToPlayer = SONAR_Detect(1);
		if(distanceToPlayer > 0.1 && distanceToPlayer < 40.0)
			finished = true;

		notes = readMux(9, 10, 15, 16);
		if (notes != 255)
			finished = true;

		THREAD_MSleep(50);
	}
}



