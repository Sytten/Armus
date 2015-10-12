/*
============================================================================
 Name : turn.cpp
 Authors : fuge2701 & fouj1807
 Version : V0.2
 Modified on: 2015-10-08
 Description : Implementation of the turn function
============================================================================
*/
#include "MotorsControl/motorsControl.h"

bool turn(int direction, float degree, struct CorrectionData * error)
{
	//Variables de timing pour ralentir les lectures d'encodeur
	float lastMS = 0;
	float currentMS = 0;

	//Quantite de trous d'encodeur que les roues doivent tourner pour faire une rotation de X degree
	float holesToTravel = holesForTurn(degree);
	//LCD_Printf("%d HOLES : ", holesToTravel);
	// Definition des valeurs des distances parcourues Temporaire.
	int holesTravelled = 0;
	int wheel;
	int encoder;

	// Vitesse initial des moteurs par default
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

	return true;
}

int stateTurn(struct Machine * robus)
{
	int currentMS = SYSTEM_ReadTimerMSeconds();
	float wheelTicks = holesForTurn(robus->StateDegree);

	if(robus->StateDirection == TURN_LEFT)
	{
		if(robus->MotorRightEncoderTotal >= wheelTicks)
		{
			robus->MotorLeftSpeed = 0;
			robus->MotorRightSpeed = 0;
			return FINISHED_TURNING;
		}

		return CHANGED_SPEED;
	}
	else
	{
		if(robus->MotorLeftEncoderTotal >= wheelTicks)
		{
			robus->MotorLeftSpeed = 0;
			robus->MotorRightSpeed = 0;
			return FINISHED_TURNING;
		}

		return CHANGED_SPEED;
	}
	return NOTHING_DONE;
}
