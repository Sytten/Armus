/*
============================================================================
 Name : motorsControl.h
 Author : fuge2701 & fouj1807
 Version : V0.2
 Modified on: 2015-09-24
 Description : Definition of the spin and roll functions
============================================================================
*/

#ifndef MOTORSCONTROL_H_
#define MOTORSCONTROL_H_

#include <libarmus.h>
#include <math.h>

#include "MotorsControl/constants.h"
#include "MotorsControl/conversions.h"

//Error correction
struct CorrectionData
{
	float LeftError;
	float RightError;
};

//Spin
bool spinXDegrees(int direction, float degree);
bool spinXDegreesByHoles(int direction, float degree);

//Turn
bool turn(int direction, float degree, struct CorrectionData * error);

//Roll
bool roll(int distance);

#endif /* MOTORSCONTROL_H_ */

