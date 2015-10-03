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
	int MotorLeftSpeed;
	int MotorRightSpeed;
	enum States CurrentState;
	enum States NextState;
	int StateParameter;
	char IRSensorStates;
	int MotorLeftEncoderTotal;
	int MotorRightEncoderTotal;
	int MotorLeftEncoderLast;
	int MotorRightEncoderLast;
};

int run();

void getSensorStatus(struct Machine * machine);

void Print_Debug_Data(const char * message, int level);

#endif /* STATEMACHINE_H_ */
