#include "StateMachine/stateMachine.h"

Robot::Robot(): m_currentState(Initial), m_nextState(Stop), m_currentTarget(0), m_behavior(Sumo), m_color(Other), m_collision(false), IRSensorStates(0), m_listener(&m_nextState )
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
				pthread_create(&m_listenerThread, NULL, &Listener::listener_helper, &m_listener);
				break;
			case TowardTarget:
				towardTarget();
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
				case Exit:
					m_currentState = Exit;
					LCD_ClearAndPrint("BYE!");
					break;
				case TowardTarget:
					m_currentState = TowardTarget;
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
	//initialMenu();
	m_color = Blue;
	m_behavior = Sumo;
	m_goingLeft = false;

	//Get the targets and position depending on the color and behaviors of the robot
	m_targets = m_map.raceTargets(m_color, m_goingLeft, m_behavior);
	m_position = m_map.initialPosition(m_color, m_goingLeft, m_behavior);
	m_angle = m_map.initialAngle(m_color, m_goingLeft, m_behavior);

	//Waiting for the starting sound
	LCD_Printf("Starting sound check");
	m_listener.listenForStartingSound(m_behavior);
}

void Robot::towardTarget()
{
	if(m_currentTarget != -1)
	{
		LCD_ClearAndPrint("Target:%f,%f", m_targets[m_currentTarget].position.x, m_targets[m_currentTarget].position.y);

		float angleToTurn = rotationAngle(m_angle, (m_targets[m_currentTarget].position-m_position).angle()); //rotationAngle(Vector2<float>(1*cos(m_angle), 1*sin(m_angle)), m_targets[m_currenTarget].position);
		float rollDistance = sqrtDistance(m_position, m_targets[m_currentTarget].position);
		Vector2<float> move;
		CorrectionData error;

		//Turn the robot and update its angle
		if(angleToTurn > 0)
		{
			turn(TURN_RIGHT, angleToTurn, &error);
			m_angle -= angleToTurn + turnForHoles(error.RightError);
		}
		else if(angleToTurn < 0)
		{
			turn(TURN_LEFT, -angleToTurn, &error);
			m_angle += -angleToTurn + turnForHoles(error.LeftError);
		}

		//Move the robot and update its position
		roll(rollDistance);

		m_position.x += rollDistance*cos(m_angle * PI_VAL / 180);
		m_position.y += rollDistance*sin(m_angle * PI_VAL / 180);

		LCD_Printf("Position: %f, %f\n", m_position.x, m_position.y);
		LCD_Printf("Angle: %f", m_angle);
		LCD_Printf("Target: %f, %f\n", m_targets[m_currentTarget].position.x, m_targets[m_currentTarget].position.y);
		LCD_Printf("Distance: %f\n", sqrtDistance(m_position, m_targets[m_currentTarget].position));
		if(near(m_position, m_targets[m_currentTarget].position))
			m_currentTarget++;

		if(m_currentTarget == m_targets.size())
			m_currentTarget = -1;
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
		LCD_Printf("Bumper gauche pour rose\n");

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
				m_color = Pink;
				internalConfirmed = true;
			}
			THREAD_MSleep(100);
		}
		internalConfirmed = false;
		THREAD_MSleep(500);

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
			THREAD_MSleep(100);
		}
		internalConfirmed = false;
		THREAD_MSleep(500);

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
			THREAD_MSleep(100);
		}
		internalConfirmed = false;
		THREAD_MSleep(500);

		LCD_ClearAndPrint("Voici le choix!\n");
		if (m_color == Blue)
			LCD_Printf("La couleur est bleue\n");
		else if (m_color == Green)
			LCD_Printf("La couleur est verte\n");
		else if (m_color == Yellow)
			LCD_Printf("La couleur est jaune\n");
		else if (m_color == Pink)
			LCD_Printf("La couleur est rose\n");

		if (m_goingLeft)
			LCD_Printf("Je pars vers la gauche\n");
		else
			LCD_Printf("Je pars vers la droite\n");

		if (m_behavior == Sumo)
			LCD_Printf("Je suis un sumo\n");
		else
			LCD_Printf("Je suis un ninja\n");

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
			THREAD_MSleep(100);
		}
		internalConfirmed = false;
		THREAD_MSleep(500);
	}
}

void Robot::getSensorStatus()
{
	IRSensorStates = sensor_IRDetection();
}

