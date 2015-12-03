#include "MotorsControl/motorsControl.h"

void spinXDegrees(int direction, float degree)
{

	//Timing variables
	float lastMS = 0;
	float currentMS = 0;

	//Distance the wheels need to travel
	float distanceToTravel = distanceForDegree(degree);

	//Variables to keep up of the progress
	float leftTravel = 0;
	float rightTravel = 0;

	//Encoder read value variables
	int encoderValLeft = 0;
	int encoderValRight = 0;

	//Default motor speeds
	int speedMotorLeft = MOTOR_DEFAULT_SPEED;
	int speedMotorRight = MOTOR_DEFAULT_SPEED;

	float averageDistance = 0;

	//Init motors at 0 speed
	MOTOR_SetSpeed (MOTOR_LEFT,0);
	MOTOR_SetSpeed (MOTOR_RIGHT,0);

	//Init encoder values by reading them
	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	currentMS = lastMS = SYSTEM_ReadTimerMSeconds();

	// While distance travelled is not as much as the objective
	while(leftTravel <= distanceToTravel &&  rightTravel <= distanceToTravel)
	{
		if (direction == SPIN_LEFT)
		{
			MOTOR_SetSpeed (MOTOR_LEFT,speedMotorLeft * -1);
			MOTOR_SetSpeed (MOTOR_RIGHT,speedMotorRight);
		}
		else
		{
			MOTOR_SetSpeed (MOTOR_LEFT,speedMotorLeft);
			MOTOR_SetSpeed (MOTOR_RIGHT,speedMotorRight * -1);
		}

		currentMS = SYSTEM_ReadTimerMSeconds();

		//If the execution delay of the encoder read time is passed
		if(currentMS >= lastMS + READING_CYCLE_DELAY)
		{
			encoderValLeft += ENCODER_Read(ENCODER_LEFT);
			encoderValRight += ENCODER_Read(ENCODER_RIGHT);

			leftTravel = travelledDistance((float)encoderValLeft);
			rightTravel = travelledDistance((float)encoderValRight);

			if(leftTravel > rightTravel)
				speedMotorLeft++;
			else if(leftTravel < rightTravel)
				speedMotorRight++;

			if(leftTravel >= distanceToTravel)
				MOTOR_SetSpeed(MOTOR_LEFT,0);
			else if(rightTravel >= distanceToTravel)
				MOTOR_SetSpeed(MOTOR_RIGHT,0);

			lastMS = currentMS;
		}
		averageDistance = (rightTravel + leftTravel) * 0.5;
	}

	//Init motors to 0 for safety
	MOTOR_SetSpeed (MOTOR_LEFT,0);
	MOTOR_SetSpeed (MOTOR_RIGHT,0);
}

/********************************************************************************************************************************************/

void spinXDegreesByHoles(int direction, float degree)
{
	//Timing variables
	float lastMS = 0;
	float currentMS = 0;

	//Holes to travel
	float holesToTravel = holesForDistance(distanceForDegree(degree));

	//Values to keep track of progress
	int holesLeft = 0;
	int holesRight = 0;

	//Encoder variables
	int encoderValLeft = 0;
	int encoderValRight = 0;

	//Set default
	int speedMotorLeft = MOTOR_DEFAULT_SPEED;
	int speedMotorRight = MOTOR_DEFAULT_SPEED;

	float holesAverage = 0;

	//Init motors at 0
	MOTOR_SetSpeed (MOTOR_LEFT,0);
	MOTOR_SetSpeed (MOTOR_RIGHT,0);

	//Init encoder reading
	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	currentMS = lastMS = SYSTEM_ReadTimerMSeconds();

	// While distance travelled is not as much as the objective
	while(holesLeft <= holesToTravel &&  holesRight <= holesToTravel)
	{
		if (direction == SPIN_LEFT)
		{
			MOTOR_SetSpeed (MOTOR_LEFT,speedMotorLeft * -1);
			MOTOR_SetSpeed (MOTOR_RIGHT,speedMotorRight);
		}
		else
		{
			MOTOR_SetSpeed (MOTOR_LEFT,speedMotorLeft);
			MOTOR_SetSpeed (MOTOR_RIGHT,speedMotorRight * -1);
		}
		currentMS = SYSTEM_ReadTimerMSeconds();

		//IF execution delay is passed
		if(currentMS >= lastMS + READING_CYCLE_DELAY)
		{
			encoderValLeft = ENCODER_Read(ENCODER_LEFT);
			encoderValRight = ENCODER_Read(ENCODER_RIGHT);

			holesLeft += encoderValLeft;
			holesRight += encoderValRight;

			if(holesLeft >= holesToTravel)
				MOTOR_SetSpeed(MOTOR_LEFT,0);
			else if(holesRight >= holesToTravel)
				MOTOR_SetSpeed(MOTOR_RIGHT,0);

			lastMS = currentMS;
		}

	}
}
