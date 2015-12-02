#include "Behaviors/Behaviors.h"

void towardPlayer()
{

	int totalRotation = 0;
	bool finished = false;
	float distanceToPlayer = SONAR_Detect(1);

	if(distanceToPlayer > 0.1 && distanceToPlayer < 50.0)
		finished = true;

	//While the player is not detected and the total rotation is not 360+
	while(!finished && totalRotation < 360)
	{
		//Sping
		spinXDegreesByHoles(TURN_LEFT, 15);
		totalRotation += 15;
		//Try to detect a player
		distanceToPlayer = SONAR_Detect(1);
		if(distanceToPlayer > 5.0 && distanceToPlayer < 30.0)
			finished = true;
	}

	//Close all motors
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);

}
