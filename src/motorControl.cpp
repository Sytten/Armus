/*
============================================================================
 Name : motorControl.cpp
 Author : fuge2701 & fouj1807
 Version : V0.1
 Created on: 2015-09-24
 Description : Implementation of the spin and roll functions
============================================================================
*/

#include "motorControl.h"
#include "stateMachine.h"

float holesForTurn(int degree)
{
	return holesForDistance((float)TURN_AXIS_CIRC * ((float)degree / float(360.0)));
}

float holesForSpin(int degree)
{
	return holesForDistance((float)WHEEL_AXE_CIRC * ((float)degree / float(360.0)));
}

float holesForDistance(float centimeters)
{
	return centimeters / (float)WHEEL_CIRC * (float)HOLES_QTY;
}

float distanceForHoles(float holesQty)
{
	return ((float)WHEEL_CIRC/(float)HOLES_QTY) * holesQty;
}

float distanceForDegreeSpin (float degree)
{
	return (degree/(float)360) * WHEEL_AXE_CIRC;
}

bool spin(int direction, float degree)
{
	//Variables de timing pour ralentir les lectures d'encodeur
	float lastMS = 0;
	float currentMS = 0;

	//Quantite de trous d'encodeur que les roues doivent tourner pour faire une rotation de X degree
	float holesToTravel = holesForDistance(distanceForDegreeSpin(degree));		// D�finition de la distance d'un degr�e.

	// Definition des valeurs des distances parcourues Temporaire.
	int holesLeft = 0;
	int holesRight = 0;

	// Variable des encodeurs pour se souvenir des distances.
	int encoderValLeft = 0;
	int encoderValRight = 0;

	// Vitesse initial des moteurs par default
	int speedMotorLeft = MOTOR_DEFAULT_SPEED;
	int speedMotorRight = MOTOR_DEFAULT_SPEED;

	float holesAverage = 0;

	// On r�initialise les moteurs a 0.
	MOTOR_SetSpeed (MOTOR_LEFT,0);
	MOTOR_SetSpeed (MOTOR_RIGHT,0);

	// On lit la valeur de chaque encodeurs.
	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	currentMS = lastMS = SYSTEM_ReadTimerMSeconds();

	while(holesLeft <= holesToTravel &&  holesRight <= holesToTravel)
	//while(holesAverage < holesToTravel)
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

		//Si le delai d'execution est depasse
		if(currentMS >= lastMS + READING_CYCLE_DELAY_MS)
		{
			encoderValLeft = ENCODER_Read(ENCODER_LEFT);
			encoderValRight = ENCODER_Read(ENCODER_RIGHT);

			//LCD_Printf("#gauche :%d\n",encoderValLeft);
			//LCD_Printf("#droite :%d\n",encoderValRight);

			holesLeft += encoderValLeft;
			holesRight += encoderValRight;

			//holesAverage = (holesLeft + holesRight) / 2;

			/**
			if(leftTravel > rightTravel)
				speedMotorLeft++;
			else if(leftTravel < rightTravel)
				speedMotorRight++;
			**/

			if(holesLeft >= holesToTravel)
				MOTOR_SetSpeed(MOTOR_LEFT,0);
			else if(holesRight >= holesToTravel)
				MOTOR_SetSpeed(MOTOR_RIGHT,0);

			//LCD_Printf("#gauche :%d\n",encoderValLeft);
			//LCD_Printf("#droite :%d\n",encoderValRight);

			LCD_Printf("#dist_gauche : %f fentes\n", holesLeft);
			LCD_Printf("#dist_droite : %f fentes\n", holesRight);

			lastMS = currentMS;
		}

	}
	return 0;
}

bool turn(int direction, float degree)
{
	//Variables de timing pour ralentir les lectures d'encodeur
	float lastMS = 0;
	float currentMS = 0;

	//Quantit� de trous d'encodeur que les roues doivent tourner pour faire une rotation de X degree
	float holesToTravel = holesForTurn(degree);
	LCD_Printf("%d HOLES : ", holesToTravel);
	// D�finition des valeurs des distances parcourues Temporaire.
	int holesTravelled = 0;
	int wheel;
	int encoder;

	// Vitesse initial des moteurs par default
	int speedMotor = MOTOR_DEFAULT_SPEED;

	if(SPIN_LEFT == direction)
	{
		wheel = MOTOR_RIGHT;
		encoder = ENCODER_RIGHT;
	}
	else
	{
		wheel = MOTOR_LEFT;
		encoder = ENCODER_LEFT;
	}

	// On r�initialise les moteurs a 0.
	MOTOR_SetSpeed (MOTOR_LEFT,0);
	MOTOR_SetSpeed (MOTOR_RIGHT,0);

	// On lit la valeur de chaque encodeurs.
	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	currentMS = lastMS = SYSTEM_ReadTimerMSeconds();

	while(holesTravelled < holesToTravel)
	{
		currentMS = SYSTEM_ReadTimerMSeconds();
		MOTOR_SetSpeed(wheel, speedMotor);
		//Si le delai d'execution est depasse
		if(currentMS >= lastMS + READING_CYCLE_DELAY_MS)
		{
			holesTravelled += ENCODER_Read(encoder);

			lastMS = currentMS;
		}

	}

	MOTOR_SetSpeed(wheel, 0);
	return 0;
}

/**********************************************************************/

bool roll(int distance)
{
	int rightSpeed = LEFT_STARTING_SPEED;
	int leftSpeed = RIGHT_STARTING_SPEED;

	int leftEncoder = 0;
	int rightEncoder = 0;

	int totalTicks = distance/WHEEL_CIRC*HOLES_QTY;
	int doneRightTicks = 0;
	int doneLeftTicks= 0;
	int reads = 0;

	//Clear encoders
	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	LCD_ClearAndPrint("Starting!\n");

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
			LCD_Printf("Left: %d\t Right: %d\n", leftEncoder, rightEncoder);


			doneRightTicks += rightEncoder;
			doneLeftTicks += leftEncoder;
			++reads;

			//LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-leftEncoder, reads*MOTOR_TARGET_SPEED-doneLeftTicks);
			//LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-rightEncoder, reads*MOTOR_TARGET_SPEED-doneRightTicks);

			leftSpeed += round((MOTOR_TARGET_SPEED/5-leftEncoder)*INSTANT_PROPORTIONALITY/5+(reads*MOTOR_TARGET_SPEED-doneLeftTicks)*LONG_PROPORTIONALITY/5);
			rightSpeed += round((MOTOR_TARGET_SPEED/5-rightEncoder)*INSTANT_PROPORTIONALITY/5+(reads*MOTOR_TARGET_SPEED-doneRightTicks)*LONG_PROPORTIONALITY/5);
			LCD_Printf("LeftSpeed: %d\t RightSpeed: %d\n", leftSpeed, rightSpeed);
		}

		else
		{
			MOTOR_SetSpeed(MOTOR_RIGHT, rightSpeed);
			MOTOR_SetSpeed(MOTOR_LEFT, leftSpeed);

			THREAD_MSleep(500);

			leftEncoder = ENCODER_Read(ENCODER_LEFT);
			rightEncoder = ENCODER_Read(ENCODER_RIGHT);
			LCD_Printf("Left: %d\t Right: %d\n", leftEncoder, rightEncoder);


			doneRightTicks += rightEncoder;
			doneLeftTicks += leftEncoder;
			++reads;

			LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-leftEncoder, reads*MOTOR_TARGET_SPEED-doneLeftTicks);
			LCD_Printf("Instant: %d\tLong: %d\n", MOTOR_TARGET_SPEED-rightEncoder, reads*MOTOR_TARGET_SPEED-doneRightTicks);

			leftSpeed += round((MOTOR_TARGET_SPEED-leftEncoder)*INSTANT_PROPORTIONALITY+(reads*MOTOR_TARGET_SPEED-doneLeftTicks)*LONG_PROPORTIONALITY);
			rightSpeed += round((MOTOR_TARGET_SPEED-rightEncoder)*INSTANT_PROPORTIONALITY+(reads*MOTOR_TARGET_SPEED-doneRightTicks)*LONG_PROPORTIONALITY);
			LCD_Printf("Left: %d\t Right: %d\n*******\n", leftSpeed, rightSpeed);
		}

	}

	//Stop robot
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	MOTOR_SetSpeed(MOTOR_LEFT, 0);

	return true;
}

