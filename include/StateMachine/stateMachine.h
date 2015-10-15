/*
============================================================================
 Name : stateMachine
 Author : M.A.G.I.E Team
 Modified on: 2015-10-15
 Description : State machine definition, with the different states and the machine
			   which contains all the necessary variables to monitor the robot and the env.
============================================================================
*/

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

/*********CHANGE LOCATION*************/
//Roll
#define NOTHING_DONE 0
#define FINISHED_ROLLING 1
#define CHANGED_SPEED 2

//Turn
#define FINISHED_TURNING 1
/************************************/

#include <libarmus.h>
#include <vector>
#include <math.h>

#include "StateMachine/States.h"
#include "MotorsControl/motorsControl.h"
#include "Sensors/IRDetection.h"
#include "Sensors/Listener.h"
#include "Position/Map.h"
#include "Position/Vector2.h"
#include "Position/Angle.h"
#include "debug.h"
#include "Behavior.h"

class Robot
{
	public:
		Robot();
		int run();

	private:
		States m_currentState;
		States m_nextState;

		Map m_map;
		Vector2<float> m_position;
		float m_angle;

		std::vector<Target> m_targets;
		int m_currentTarget;
		Behavior m_behavior;
		Color m_color;
		bool m_goingLeft;

		bool m_collision;
		char IRSensorStates;
		Listener m_listener;

		THREAD m_listenerThread;

	private:
		void initialization();
		void towardTarget();
		void avoid();
		void stop();
		void stay();

		void initialMenu();

		void getSensorStatus();
};

#endif /* STATEMACHINE_H_ */
