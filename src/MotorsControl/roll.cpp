#include "MotorsControl/motorsControl.h"

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

			leftSpeed += round((MOTOR_TARGET_SPEED/2.5-leftEncoder)*INSTANT_PROPORTIONALITY/2.5+(expectedTicks-doneLeftTicks)*LONG_PROPORTIONALITY/2.5);
			rightSpeed += round((MOTOR_TARGET_SPEED/2.5-rightEncoder)*INSTANT_PROPORTIONALITY/2.5+(expectedTicks-doneRightTicks)*LONG_PROPORTIONALITY/2.5);
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

			leftSpeed += round((MOTOR_TARGET_SPEED-leftEncoder)*INSTANT_PROPORTIONALITY+(expectedTicks-doneLeftTicks)*LONG_PROPORTIONALITY);
			rightSpeed += round((MOTOR_TARGET_SPEED-rightEncoder)*INSTANT_PROPORTIONALITY+(expectedTicks-doneRightTicks)*LONG_PROPORTIONALITY);
			LCD_Printf("Left: %d\t Right: %d\n", leftSpeed, rightSpeed);
		}

	}

	//Stop robot
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	MOTOR_SetSpeed(MOTOR_LEFT, 0);

	return true;
}

/*int rollState(Robot * robus)
{
	int currentMS = SYSTEM_ReadTimerMSeconds();
	int wheelTicks = robus->StateDistance / WHEEL_CIRC * HOLES_QTY;

	if(robus->MotorRightEncoderTotal >= wheelTicks
			|| robus->MotorLeftEncoderTotal >= wheelTicks)
	{
		robus->MotorLeftSpeed = 0;
		robus->MotorRightSpeed = 0;
		return FINISHED_ROLLING;
	}
	else if(currentMS >= robus->StateLastMs + ROLL_READING_CYCLE_DELAY)
	{
		if(wheelTicks - robus->MotorRightEncoderTotal < MOTOR_TARGET_SPEED
				|| wheelTicks - robus->MotorLeftEncoderTotal < MOTOR_TARGET_SPEED )
		{
			//THREAD_MSleep(100);
			robus->MotorLeftSpeed  += round((MOTOR_TARGET_SPEED / 5 - robus->MotorLeftEncoderLast)
													* INSTANT_PROPORTIONALITY / 5 +	(robus->StateTicks * MOTOR_TARGET_SPEED - robus->MotorLeftEncoderTotal) * LONG_PROPORTIONALITY / 5);
			robus->MotorRightSpeed += round((MOTOR_TARGET_SPEED / 5 - robus->MotorRightEncoderLast)
													* INSTANT_PROPORTIONALITY / 5 + (robus->StateTicks * MOTOR_TARGET_SPEED - robus->MotorRightEncoderTotal) * LONG_PROPORTIONALITY / 5);
			robus->StateLastMs += ROLL_READING_CYCLE_DELAY;
			return CHANGED_SPEED;
		}
		else if(currentMS >= robus->StateLastMs + (ROLL_READING_CYCLE_DELAY * 5))
		{
			//THREAD_MSleep(500);
			robus->MotorLeftSpeed += round(((MOTOR_TARGET_SPEED - robus->MotorLeftEncoderLast) *
										INSTANT_PROPORTIONALITY + (robus->StateTicks * MOTOR_TARGET_SPEED - robus->MotorLeftEncoderTotal) * LONG_PROPORTIONALITY));
			robus->MotorRightSpeed += round(((MOTOR_TARGET_SPEED - robus->MotorRightEncoderLast) *
										INSTANT_PROPORTIONALITY + (robus->StateTicks * MOTOR_TARGET_SPEED - robus->MotorRightEncoderTotal) * LONG_PROPORTIONALITY));
			robus->StateLastMs += ROLL_READING_CYCLE_DELAY;
			return CHANGED_SPEED;
		}
	}
	return NOTHING_DONE;
}*/
