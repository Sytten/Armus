/*
============================================================================
 Name : stateMachine
 Author : M.A.G.I.E Team
 Modified on: 2015-11-05
 Description : State machine definition used to change the general behavior of the robot.
 	 	 	   These behaviors are defined in their own folder.
============================================================================
*/

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include <libarmus.h>
#include <math.h>

#include "StateMachine/GeneralStates.h"
#include "Behaviors/Behaviors.h"
#include "debug.h"

//Call this function when you want to start the state machine. It should not be called more than once.
int run();

#endif /* STATEMACHINE_H_ */
