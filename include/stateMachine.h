/*
 * stateMachine.h
 *
 *  Created on: 2015-10-03
 *      Author: Jeep
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

/*****STATE MACHINE*****/
/*****STATE ROLL*****/
#define ROLL_FORWARD 1
#define ROLL_BACKWARDS -1

/*****STATE TURN SPIN*****/
#define SPIN_LEFT 0
#define SPIN_RIGHT 1
#define TURN_LEFT 0
#define TURN_RIGHT 1

#define DEBUG_LEVEL 1
#define DEBUG_USER 2
#define DEBUG_CODE 1
#define DEBUG_BASE 0

#include <libarmus.h>
#include "constants.h"
#include "sensorDetection.h"
#include "motorControl.h"

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
	float StateParameter;			//State parameter (speed, angle)
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

void Print_Debug_Data(const char * message, int level);

#endif /* STATEMACHINE_H_ */
