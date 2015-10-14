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
#include "debug.h"

enum States
{
	StatesInit = 0,
	StatesStop,
	StatesTurn,
	StatesSpin,
	StatesRoll,
	StatesEnd,
	StatesExit
};

struct Machine
{
	int MotorLeftSpeed;				//Motor left speed
	int MotorRightSpeed;			//Motor right speed
	enum States CurrentState;		//Current state machine state
	enum States NextState;			//Next state machine state
	float StateDistance;			//State parameter (speed, angle)
	float StateDegree;
	int StateDirection;				//Direction of the state (Forward, left, back, right)
	char IRSensorStates;			//Char representing all IR sensor values
	int MotorLeftEncoderTotal;		//Total number of read left encoder values since state change
	int MotorRightEncoderTotal;		//Total number of read right encoder values since state change
	int MotorLeftEncoderLast;		//Last number of read left encoder values
	int MotorRightEncoderLast;		//Last number of read right encoder values
	int StateTicks;					//Counts number of iterations in the same state
	int StateLastMs;
};

int run();

void getSensorStatus(struct Machine * robus);

#endif /* STATEMACHINE_H_ */
