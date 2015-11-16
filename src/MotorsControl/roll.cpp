#include "MotorsControl/motorsControl.h"
#include "MotorsControl/RollVariables.h"

bool rollWithDetection(int distance, bool & firstDetection)
{
	int rightSpeed = RIGHT_STARTING_SPEED;
	int leftSpeed = LEFT_STARTING_SPEED;

	int leftEncoder = 0;
	int rightEncoder = 0;

	int totalTicks = distance/WHEEL_CIRC*HOLES_QTY;
	int doneRightTicks = 0;
	int doneLeftTicks= 0;
	int expectedTicks = 0;

	float distanceToEnnemy = 0;
	bool originalFirstDetection = firstDetection;

	//Clear encoders
	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	//Roll until reached destination
	while(doneRightTicks < totalTicks || doneLeftTicks < totalTicks)
	{
		distanceToEnnemy = SONAR_Detect(1);
		if(distanceToEnnemy > 0.1 && distanceToEnnemy < 20.0)
		{
			MOTOR_SetSpeed(MOTOR_RIGHT, 0);
			MOTOR_SetSpeed(MOTOR_LEFT, 0);
			THREAD_MSleep(3000);
		}

		if(totalTicks-doneRightTicks < MOTOR_TARGET_SPEED || totalTicks-doneLeftTicks < MOTOR_TARGET_SPEED)
		{
			MOTOR_SetSpeed(MOTOR_RIGHT, rightSpeed);
			MOTOR_SetSpeed(MOTOR_LEFT, leftSpeed);

			THREAD_MSleep(100);

			leftEncoder = ENCODER_Read(ENCODER_LEFT);
			rightEncoder = ENCODER_Read(ENCODER_RIGHT);
			LCD_ClearAndPrint("Left: %d\t Right: %d\n", leftEncoder, rightEncoder);

			doneRightTicks += rightEncoder;
			doneLeftTicks += leftEncoder;
			expectedTicks += MOTOR_TARGET_SPEED/2.5;

			//LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-leftEncoder, reads*MOTOR_TARGET_SPEED-doneLeftTicks);
			//LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-rightEncoder, reads*MOTOR_TARGET_SPEED-doneRightTicks);

			leftSpeed += (MOTOR_TARGET_SPEED/2.5-leftEncoder)*INSTANT_PROPORTIONALITY/2.5+(expectedTicks-doneLeftTicks)*LONG_PROPORTIONALITY/2.5;
			rightSpeed += (MOTOR_TARGET_SPEED/2.5-rightEncoder)*INSTANT_PROPORTIONALITY/2.5+(expectedTicks-doneRightTicks)*LONG_PROPORTIONALITY/2.5;
			//LCD_Printf("LeftSpeed: %d\t RightSpeed: %d\n", leftSpeed, rightSpeed);
		}

		else
		{
			MOTOR_SetSpeed(MOTOR_RIGHT, rightSpeed);
			MOTOR_SetSpeed(MOTOR_LEFT, leftSpeed);

			THREAD_MSleep(250);

			leftEncoder = ENCODER_Read(ENCODER_LEFT);
			rightEncoder = ENCODER_Read(ENCODER_RIGHT);
			//LCD_Printf("Left: %d\t Right: %d\n", leftEncoder, rightEncoder);

			doneRightTicks += rightEncoder;
			doneLeftTicks += leftEncoder;
			expectedTicks += MOTOR_TARGET_SPEED;

			//LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-leftEncoder, expectedTicks-doneLeftTicks);
			//LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-rightEncoder, expectedTicks-doneRightTicks);

			leftSpeed += (MOTOR_TARGET_SPEED-leftEncoder)*INSTANT_PROPORTIONALITY+(expectedTicks-doneLeftTicks)*LONG_PROPORTIONALITY;
			rightSpeed += (MOTOR_TARGET_SPEED-rightEncoder)*INSTANT_PROPORTIONALITY+(expectedTicks-doneRightTicks)*LONG_PROPORTIONALITY;
			//LCD_Printf("Left: %d\t Right: %d\n", leftSpeed, rightSpeed);
		}
	}

	//Stop robot
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	MOTOR_SetSpeed(MOTOR_LEFT, 0);

	return true;
}

bool roll(int distance)
{
	int rightSpeed = RIGHT_STARTING_SPEED;
	int leftSpeed = LEFT_STARTING_SPEED;

	int leftEncoder = 0;
	int rightEncoder = 0;

	int totalTicks = distance/WHEEL_CIRC*HOLES_QTY;
	int doneRightTicks = 0;
	int doneLeftTicks= 0;
	int expectedTicks = 0;

	//Clear encoders
	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	//Roll until reached destination
	while(doneRightTicks < totalTicks || doneLeftTicks < totalTicks)
	{

		if(totalTicks-doneRightTicks < MOTOR_TARGET_SPEED || totalTicks-doneLeftTicks < MOTOR_TARGET_SPEED)
		{
			MOTOR_SetSpeed(MOTOR_RIGHT, rightSpeed);
			MOTOR_SetSpeed(MOTOR_LEFT, leftSpeed);

			THREAD_MSleep(100);

			leftEncoder = ENCODER_Read(ENCODER_LEFT);
			rightEncoder = ENCODER_Read(ENCODER_RIGHT);
			LCD_ClearAndPrint("Left: %d\t Right: %d\n", leftEncoder, rightEncoder);

			doneRightTicks += rightEncoder;
			doneLeftTicks += leftEncoder;
			expectedTicks += MOTOR_TARGET_SPEED/2.5;

			//LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-leftEncoder, reads*MOTOR_TARGET_SPEED-doneLeftTicks);
			//LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-rightEncoder, reads*MOTOR_TARGET_SPEED-doneRightTicks);

			leftSpeed += (MOTOR_TARGET_SPEED/2.5-leftEncoder)*INSTANT_PROPORTIONALITY/2.5+(expectedTicks-doneLeftTicks)*LONG_PROPORTIONALITY/2.5;
			rightSpeed += (MOTOR_TARGET_SPEED/2.5-rightEncoder)*INSTANT_PROPORTIONALITY/2.5+(expectedTicks-doneRightTicks)*LONG_PROPORTIONALITY/2.5;
			//LCD_Printf("LeftSpeed: %d\t RightSpeed: %d\n", leftSpeed, rightSpeed);
		}

		else
		{
			MOTOR_SetSpeed(MOTOR_RIGHT, rightSpeed);
			MOTOR_SetSpeed(MOTOR_LEFT, leftSpeed);

			THREAD_MSleep(250);

			leftEncoder = ENCODER_Read(ENCODER_LEFT);
			rightEncoder = ENCODER_Read(ENCODER_RIGHT);
			//LCD_Printf("Left: %d\t Right: %d\n", leftEncoder, rightEncoder);

			doneRightTicks += rightEncoder;
			doneLeftTicks += leftEncoder;
			expectedTicks += MOTOR_TARGET_SPEED;

			//LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-leftEncoder, expectedTicks-doneLeftTicks);
			//LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-rightEncoder, expectedTicks-doneRightTicks);

			leftSpeed += (MOTOR_TARGET_SPEED-leftEncoder)*INSTANT_PROPORTIONALITY+(expectedTicks-doneLeftTicks)*LONG_PROPORTIONALITY;
			rightSpeed += (MOTOR_TARGET_SPEED-rightEncoder)*INSTANT_PROPORTIONALITY+(expectedTicks-doneRightTicks)*LONG_PROPORTIONALITY;
			LCD_Printf("Left: %d\t Right: %d\n", leftSpeed, rightSpeed);
		}
	}

	//Stop robot
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	MOTOR_SetSpeed(MOTOR_LEFT, 0);

	return true;
}

bool roll(RollVariables *data)
{
	static float lastMS = 0;

	if(firstTime)
	{
		ENCODER_Read(ENCODER_LEFT);
		ENCODER_Read(ENCODER_RIGHT);
	}

	if(!data->done)
	{
		int totalTicks = holesForDistance(data->distance);
		int leftEncoder = 0;
		int rightEncoder = 0;
		float currentMS = SYSTEM_ReadTimerMSeconds();

		if(data->doneRightTicks < totalTicks || data->doneLeftTicks < totalTicks)
		{
			if(currentMS >= lastMS + 250)
			{
				MOTOR_SetSpeed(MOTOR_RIGHT, rightSpeed);
				MOTOR_SetSpeed(MOTOR_LEFT, leftSpeed);

				THREAD_MSleep(250);

				leftEncoder = ENCODER_Read(ENCODER_LEFT);
				rightEncoder = ENCODER_Read(ENCODER_RIGHT);

				data->doneRightTicks += rightEncoder;
				data->doneLeftTicks += leftEncoder;
				data->expectedTicks += MOTOR_TARGET_SPEED;

				data->leftSpeed += (MOTOR_TARGET_SPEED-leftEncoder)*INSTANT_PROPORTIONALITY+(data->expectedTicks-data->doneLeftTicks)*LONG_PROPORTIONALITY;
				data->rightSpeed += (MOTOR_TARGET_SPEED-rightEncoder)*INSTANT_PROPORTIONALITY+(data->expectedTicks-data->doneRightTicks)*LONG_PROPORTIONALITY;

				lastMS = currentMS;
			}
		}
		else
			data->done = true;
	}

	//Stop robot
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	MOTOR_SetSpeed(MOTOR_LEFT, 0);

	return true;
}
