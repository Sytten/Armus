/*
============================================================================
 Name : motorsControl
 Author : M.A.G.I.E Team
 Modified on: 2015-11-16
 Description : Definition of the spin, turn and roll functions
============================================================================
*/

#ifndef MOTORSCONTROL_H_
#define MOTORSCONTROL_H_

#include <libarmus.h>
#include <math.h>

#include "MotorsControl/constants.h"
#include "MotorsControl/conversions.h"
#include "Sensors/LineDetection.h"


//Error correction
struct CorrectionData
{
	float LeftError;
	float RightError;
};

//Turn
bool turn(int direction, float degree, struct CorrectionData * error);

//Spin
bool spinXDegrees(int direction, float degree);
bool spinXDegreesByHoles(int direction, float degree);


//Roll
bool roll(int distance);
bool rollWithDetection(int distance, bool & firstDetection);
bool rollOnLine(int distance);

#endif /* MOTORSCONTROL_H_ */

