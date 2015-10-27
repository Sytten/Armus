#include "Sensors/Listener.h"

void Listener::listenForStartingSound(Behavior p_behavior)
{
	int sound = 0, noise = 0;
	bool heardOnce = false;
	int iterations = 0;
	float lastTime = SYSTEM_ReadTimerMSeconds();
	float currentTime = 0;
	while(1)
	{
		while((lastTime+STARTING_SOUND_LENGTH) > currentTime)
		{
			sound += ANALOG_Read(1);
			noise += ANALOG_Read(2);

			iterations++;

			THREAD_MSleep(100);
			currentTime = SYSTEM_ReadTimerMSeconds();
		}
		lastTime = currentTime;

		LCD_Printf("Sound: %d, Noise: %d\n", sound/iterations, noise/iterations);

		if (sound/iterations-noise/iterations > 50)
		{
			if(p_behavior == Sumo)
			{
				(*m_state) = TowardTarget;
				return;
			}
			else if(p_behavior == Ninja)
			{
				if(heardOnce)
				{
					(*m_state) = TowardTarget;
					return;
				}
				else
					heardOnce = true;
			}
		}

		sound = noise = iterations = 0;
	}
}

void Listener::listenForStopingSound()
{
	int sound = 0, noise = 0;
	int iterations = 0;
	float lastTime = SYSTEM_ReadTimerMSeconds();
	float currentTime = 0;
	while(1)
	{
		while((lastTime+STOPING_SOUND_LENGTH) > currentTime)
		{
			sound += ANALOG_Read(1);
			noise += ANALOG_Read(2);

			iterations++;

			THREAD_MSleep(100);
			currentTime = SYSTEM_ReadTimerMSeconds();
		}
		lastTime = currentTime;

		if (sound/iterations-noise/iterations > 50)
		{
			pthread_mutex_lock(&m_mutex);
			(*m_state) = Exit;
			pthread_mutex_unlock(&m_mutex);
			return;
		}

		sound = noise = iterations = 0;
	}
}

