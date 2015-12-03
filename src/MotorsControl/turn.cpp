#include "MotorsControl/motorsControl.h"

void turn(int direction, float degree, struct CorrectionData * error)
{
	//Timing variables
	float lastMS = 0;
	float currentMS = 0;

	//Number of holes to travel
	float holesToTravel = holesForTurn(degree);

	// Values to use to follow progress
	int holesTravelled = 0;
	int wheel;
	int encoder;

	// Set initial motor speed
	int speedMotor = MOTOR_DEFAULT_SPEED;

	if(SPIN_LEFT == direction)
	{
		wheel = MOTOR_RIGHT;
		encoder = ENCODER_RIGHT;
		holesToTravel += (error->RightError - error->LeftError);
	}
	else
	{
		wheel = MOTOR_LEFT;
		encoder = ENCODER_LEFT;
		holesToTravel += (error->LeftError - error->RightError);
	}

	//Reinitialise the motor speeds
	MOTOR_SetSpeed (MOTOR_LEFT,0);
	MOTOR_SetSpeed (MOTOR_RIGHT,0);

	//Read encoder values
	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	currentMS = lastMS = SYSTEM_ReadTimerMSeconds();

	while(holesTravelled < holesToTravel)
	{
		currentMS = SYSTEM_ReadTimerMSeconds();
		MOTOR_SetSpeed(wheel, speedMotor);
		//If execution delay is passed
		if(currentMS >= lastMS + READING_CYCLE_DELAY)
		{
			holesTravelled += ENCODER_Read(encoder);

			lastMS = currentMS;
		}
	}

	if(SPIN_LEFT == direction)
	{
		error->LeftError = holesTravelled - holesToTravel;
		error->RightError = 0;
	}
	else
	{
		error->RightError = holesTravelled - holesToTravel;
		error->LeftError = 0;
	}

	MOTOR_SetSpeed(wheel, 0);
}
