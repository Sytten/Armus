/*
============================================================================
 Name : Listener
 Author : M.A.G.I.E Team
 Modified on: 2015-10-16
 Description : The listener waits for a specific signal and change the state of the robot.
============================================================================
*/

#ifndef LISTENER_H_
#define LISTENER_H_

#define STARTING_SOUND_LENGTH 500
#define STOPING_SOUND_LENGTH 2000

#include <libarmus.h>
#include <pthread.h>
#include "StateMachine/States.h"
#include "Behavior.h"

class Listener
{
	public:
		Listener(States *p_state):m_state(p_state){ pthread_mutex_init(&m_mutex, NULL);}

		void listenForStartingSound(Behavior p_behavior);
		void listenForStopingSound();

		static void *listener_helper(void* p_listener) { ((Listener*)p_listener)->listenForStopingSound();}

	private:
		States *m_state;
		pthread_mutex_t m_mutex;
};

#endif /* LISTENER_H_ */
