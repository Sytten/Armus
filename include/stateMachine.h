/*
============================================================================
 Name : stateMachine
 Author : M.A.G.I.E Team
 Modified on: 2015-10-14
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
#include "MotorsControl/motorsControl.h"
#include "Sensors/IRDetection.h"
#include "Position/Map.h"
#include "Position/Vector2.h"
#include "debug.h"

enum States
{
	Initial = 0,
	TowardTarget,
	Avoid,
	Stop,
	Stay,
	Exit
};

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

		bool m_collision;
		char IRSensorStates;

	private:
		void initialization();
		void towardTarget();
		void avoid();
		void stop();
		void stay();

		void getSensorStatus();
};

#endif /* STATEMACHINE_H_ */
