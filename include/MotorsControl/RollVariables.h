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
	int distance;

	int rightSpeed;
	int leftSpeed;

	int doneRightTicks;
	int doneLeftTicks;
	int expectedTicks;

	bool firstTime;
	bool done;
};

#endif /* ROLLVARIABLES_H_ */
