/*
============================================================================
 Name : RollVariables
 Author : M.A.G.I.E Team
 Modified on: 2015-11-16
 Description : Structure to hold the variables of the non blocking roll function
============================================================================
*/
#ifndef ROLLVARIABLES_H_
#define ROLLVARIABLES_H_

#include "MotorsControl/constants.h"

struct RollVariables
{
	int distance = 0;

	int rightSpeed =  RIGHT_STARTING_SPEED;
	int leftSpeed = LEFT_STARTING_SPEED;

	int doneRightTicks = 0;
	int doneLeftTicks = 0;
	int expectedTicks = 0;

	bool firstTime = true;
	bool done = false;
};

#endif /* ROLLVARIABLES_H_ */
