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

bool spinXDegrees(int direction, float degree)
{

	//Variables de timing pour ralentir les lectures d'encodeur
	float lastMS = 0;
	float currentMS = 0;

	//Distance que les roues doivent tourner pour faire une rotation de X degree
	float distanceToTravel = distanceForDegree(degree) ;		// Définition de la distance d'un degrée.

	// Définition des valeurs des distances parcourues Temporaire.
	float leftTravel = 0;
	float rightTravel = 0;

	// Variable des encodeurs pour se souvenir des distances.
	int encoderValLeft = 0;
	int encoderValRight = 0;

	// Vitesse initial des moteurs par default
	int speedMotorLeft = MOTOR_DEFAULT_SPEED;
	int speedMotorRight = MOTOR_DEFAULT_SPEED;

	// On réinitialise les moteurs a 0.
	MOTOR_SetSpeed (MOTOR_LEFT,0);
	MOTOR_SetSpeed (MOTOR_RIGHT,0);

	// On lit la valeur de chaque encodeurs.
	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	currentMS = lastMS = SYSTEM_ReadTimerMSeconds();
	LCD_Printf("\n# distancetodo :%f cm\n",distanceToTravel);
	// On comptabilise la distance parcouru pour un deg.
	while(leftTravel <= distanceToTravel ||  rightTravel <= distanceToTravel)
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
		if(currentMS >= lastMS + READING_CYCLE_DELAY)
		{
			encoderValLeft += ENCODER_Read(ENCODER_LEFT);
			encoderValRight += ENCODER_Read(ENCODER_RIGHT);

			//LCD_Printf("#gauche :%d\n",encoderValLeft);
			//LCD_Printf("#droite :%d\n",encoderValRight);

			leftTravel = travelledDistance((float)encoderValLeft);
			rightTravel = travelledDistance((float)encoderValRight);

			if(leftTravel > rightTravel)
				speedMotorLeft++;
			else if(leftTravel < rightTravel)
				speedMotorRight++;

			//LCD_Printf("#gauche :%d\n",encoderValLeft);
			//LCD_Printf("#droite :%d\n",encoderValRight);

			LCD_Printf("#dist_gauche : %f cm\n", leftTravel);
			LCD_Printf("#dist_droite : %f cm\n", rightTravel);

			lastMS = currentMS;
		}
	}
	LCD_Printf("\n#distancetodo :%f cm\n",distanceToTravel);
	LCD_Printf("#dist_gauche f : %f cm\n", leftTravel);
	LCD_Printf("#dist_droite f : %f cm\n", rightTravel);

	// On arrete les moteurs a 0.
	MOTOR_SetSpeed (MOTOR_LEFT,0);
	MOTOR_SetSpeed (MOTOR_RIGHT,0);

	return true;
}

float travelledDistance(float holesQty)
{
	return ((float)WHEEL_CIRC/(float)HOLES_QTY) * holesQty;
}

float distanceForDegree (float degree)
{
	return (degree/(float)360) * WHEEL_AXE_CIRC;
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

	//Stop robot
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);
	MOTOR_SetSpeed(MOTOR_LEFT, 0);

	return true;
}


