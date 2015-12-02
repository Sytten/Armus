#include "Behaviors/Behaviors.h"

void towardPlayer()
{

	int totalRotation = 0;
	bool finished = false;
	float distanceToPlayer = SONAR_Detect(1);

	if(distanceToPlayer > 0.1 && distanceToPlayer < 50.0)
		finished = true;

	while(!finished && totalRotation < 360)
	{
		spinXDegreesByHoles(TURN_LEFT, 15);
		totalRotation += 15;
		distanceToPlayer = SONAR_Detect(1);
		if(distanceToPlayer > 5.0 && distanceToPlayer < 30.0)
			finished = true;
	}

	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);

}
