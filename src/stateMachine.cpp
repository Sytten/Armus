#include "stateMachine.h"

Robot::Robot(): m_currentState(Initial), m_nextState(Stop), m_collision(false), IRSensorStates(0)
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

void Robot::getSensorStatus()
{
	IRSensorStates = sensor_IRDetection();
}

