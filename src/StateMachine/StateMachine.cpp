#include "StateMachine/StateMachine.h"

int run()
{
	//General variables we will need in our program
	GeneralStates robotState = Play;

	//Main state machine of the program, a state is just a way of behaving corresponding to some inputs that we decide
	while(robotState != Exit)
	{
		//Think of this switch like many if combined
		switch (robotState)
		{
			case Wander:
				wander();
				robotState = TowardPlayer;
				break;

			case TowardPlayer:
				towardPlayer();
				robotState = Play;
				break;

			case Play:
				play();
				robotState = Wander;
				break;

			case Stay:
				stay();
				robotState = Wander;
				break;



			default: //In case something goes wrong in our code
				Print_Debug_Data("Error in state execution",DEBUG_CODE);
				robotState = Exit;
				return 0;
				break;
		}
	}

	//Be sure that the robot is not moving
	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);

	return 0;
}
