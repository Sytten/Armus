#include "stateMachine.h"

Robot::Robot(): m_currentState(Initial), m_nextState(Stop), m_behavior(Sumo), m_color(Other), m_collision(false), IRSensorStates(0)
{
}

int Robot::run()
{
	while(m_currentState != Exit)
	{
		switch (m_currentState)
		{

			case Initial:
				initialization();
				break;
			case TowardTarget:
				break;
			default:
				Print_Debug_Data("Error in state execution",DEBUG_CODE);
				m_currentState = Exit;
				return 0;
		}

		if(m_nextState != m_currentState)
		{
			switch (m_nextState)
			{
				case Stop:
					break;
				default:
					Print_Debug_Data("Error in state changing",DEBUG_CODE);
					THREAD_MSleep(5000);
					m_currentState = Exit;
					break;
			}
		}

	}

	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);

	return 1;
}

void Robot::initialization()
{
	//Get initial color and behavior from user
	initialMenu();

	//Get the targets and position depending on the color and behaviors of the robot
	m_targets = m_map.raceTargets(m_color, m_goingLeft, m_behavior);
	m_position = m_map.initialPosition(m_color, m_goingLeft, m_behavior);
	m_angle = m_map.initialAngle(m_color, m_goingLeft, m_behavior);

	//Waiting for the starting sound
	int sound = 0, noise = 0;
	while(1)
	{
		for(int i = 0; i < 20; i++)
		{
			sound += ANALOG_Read(1);
			noise += ANALOG_Read(2);
		}

		if (sound/20-noise/20 > 50)
		{
			m_currentState = TowardTarget;
			return;
		}

		THREAD_MSleep(500);
		sound = noise = 0;
	}
}

void Robot::initialMenu()
{
	bool confirmed = false;
	bool internalConfirmed = false;

	while(!confirmed)
	{

		LCD_ClearAndPrint("Je suis sur qu'elle couleur?\n");
		LCD_Printf("Bumper arriere pour bleu\n");
		LCD_Printf("Bumper avant pour vert\n");
		LCD_Printf("Bumper droit pour jaune\n");
		LCD_Printf("Bumper gauche pour mauve\n");

		while (!internalConfirmed)
		{
			if(DIGITALIO_Read(BMP_REAR)) {
				m_color = Blue;
				internalConfirmed = true;
			}
			if(DIGITALIO_Read(BMP_FRONT)) {
				m_color = Green;
				internalConfirmed = true;
			}
			if(DIGITALIO_Read(BMP_RIGHT)) {
				m_color = Yellow;
				internalConfirmed = true;
			}
			if(DIGITALIO_Read(BMP_LEFT)) {
				m_color = Purple;
				internalConfirmed = true;
			}
		}
		internalConfirmed = false;

		LCD_ClearAndPrint("Si j'etais le ninja, je devrais aller vers la droite ou la gauche?\n");
		LCD_Printf("Bumper droit pour la droite\n");
		LCD_Printf("Bumper gauche pour la gauche\n");

		while (!internalConfirmed)
		{
			if(DIGITALIO_Read(BMP_RIGHT)) {
				m_goingLeft = false;
				internalConfirmed = true;
			}
			if(DIGITALIO_Read(BMP_LEFT)) {
				m_goingLeft = true;
				internalConfirmed = true;
			}
		}
		internalConfirmed = false;

		LCD_ClearAndPrint("Quel est mon role?\n");
		LCD_Printf("Bumper droit pour le sumo\n");
		LCD_Printf("Bumper gauche pour le ninja\n");

		while (!internalConfirmed)
		{
			if(DIGITALIO_Read(BMP_RIGHT)) {
				m_behavior = Sumo;
				internalConfirmed = true;
			}
			if(DIGITALIO_Read(BMP_LEFT)) {
				m_behavior = Ninja;
				internalConfirmed = true;
			}
		}
		internalConfirmed = false;

		LCD_ClearAndPrint("Voici le choix!\n");
		if (m_color == Blue)
			LCD_Printf("La couleur est bleue\n");
		else if (m_color == Green)
			LCD_Printf("La couleur est verte\n");
		else if (m_color == Yellow)
			LCD_Printf("La couleur est jaune\n");
		else if (m_color == Purple)
			LCD_Printf("La couleur est mauve\n");

		if (m_goingLeft)
			LCD_Printf("Je pars vers la gauche\n");
		else
			LCD_Printf("Je pars vers la droite\n");

		LCD_Printf("C'est ok?\n");
		LCD_Printf("Oui, bumper droit\n");
		LCD_Printf("NON! bumper gauche\n");

		while(!internalConfirmed)
		{
			if(DIGITALIO_Read(BMP_RIGHT)) {
				internalConfirmed = true;
				confirmed = true;
			}
			if(DIGITALIO_Read(BMP_LEFT)) {
				internalConfirmed = true;
				confirmed = false;
			}
		}
		internalConfirmed = false;

		THREAD_MSleep(1000);
	}
}

void Robot::getSensorStatus()
{
	IRSensorStates = sensor_IRDetection();
}

