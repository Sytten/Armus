/*
============================================================================
 Name : Listener
 Author : M.A.G.I.E Team
 Modified on: 2015-10-15
 Description : The listener waits for a specific signal and change the state of the robot.
============================================================================
*/

#ifndef LISTENER_H_
#define LISTENER_H_

#include <libarmus.h>

#include "StateMachine/States.h"
#include "Behavior.h"

class Listener
{
	public:
		Listener(States *p_state):m_state(p_state){}

		void listenForStartingSound(Behavior p_behavior);
		void listenForStopingSound();

	private:
		States *m_state;
};

#endif /* LISTENER_H_ */
