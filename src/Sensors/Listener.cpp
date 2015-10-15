#include "Sensors/Listener.h"

void Listener::listenForStartingSound(Behavior p_behavior)
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
			(*m_state) = TowardTarget;
			return;
		}

		THREAD_MSleep(500);
		sound = noise = 0;
	}
}

void Listener::listenForStopingSound()
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
			(*m_state) = Exit;
			return;
		}

		THREAD_MSleep(500);
		sound = noise = 0;
	}
}

