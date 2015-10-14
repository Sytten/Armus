#include "MotorsControl/motorsControl.h"

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

	float averageDistance = 0;

	// On réinitialise les moteurs a 0.
	MOTOR_SetSpeed (MOTOR_LEFT,0);
	MOTOR_SetSpeed (MOTOR_RIGHT,0);

	// On lit la valeur de chaque encodeurs.
	ENCODER_Read(ENCODER_LEFT);
	ENCODER_Read(ENCODER_RIGHT);

	currentMS = lastMS = SYSTEM_ReadTimerMSeconds();
	//LCD_Printf("\n# distancetodo :%f cm\n",distanceToTravel);
	// On comptabilise la distance parcouru pour un deg.
	while(leftTravel <= distanceToTravel &&  rightTravel <= distanceToTravel)
	//while(averageDistance <= distanceToTravel)
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

	// On arrete les moteurs a 0.
	MOTOR_SetSpeed (MOTOR_LEFT,0);
	MOTOR_SetSpeed (MOTOR_RIGHT,0);

	return true;
}

/********************************************************************************************************************************************/

bool spinXDegreesByHoles(int direction, float degree)
{
	//Variables de timing pour ralentir les lectures d'encodeur
	float lastMS = 0;
	float currentMS = 0;

	//Quantit� de trous d'encodeur que les roues doivent tourner pour faire une rotation de X degree
	float holesToTravel = holesForDistance(distanceForDegree(degree));		// D�finition de la distance d'un degr�e.

	// D�finition des valeurs des distances parcourues Temporaire.
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
	return true;
}
