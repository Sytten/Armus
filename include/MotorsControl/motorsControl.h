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
#include "MotorsControl/RollVariables.h"
#include "Sensors/LineDetection.h"

//Error correction
struct CorrectionData
{
	float LeftError;
	float RightError;
};

/**
 * Turns the robot in a direction of a certain number of degrees
 * @param direction The direction to go
 * @param degree The number of degrees to turn
 * @param error The error correction structure
 */
void turn(int direction, float degree, struct CorrectionData * error);

/**
 * Spins the robot on itself
 * This function uses and does its verification based on distance
 * @param direction The direction to take
 * @param degree The number of degrees to turn
 */
void spinXDegrees(int direction, float degree);

/**
 * Spins the robot on itself
 * This function uses and does its verification based on the number of encoder holes
 * @param direction The direction to take
 * @param degree The number of degrees to turn
 */
void spinXDegreesByHoles(int direction, float degree);

/**
 * Robot rolls for the distance given. This is a blocking function
 * @param distance Distance in centimeters to roll for
 */
void roll(int distance);

/**
 * Robot rolls for the distance given. This is not a blocking function
 * @param data Roll variables
 */
void roll(RollVariables *data);

/**
 * Robot rolls but with added detection with the connected sonar. This is a blocking function
 * @param distance Distance in centimeters to roll for
 * @param firstDetection Variable to modify if a detection happens
 */
void rollWithDetection(int distance, bool & firstDetection);

#endif /* MOTORSCONTROL_H_ */

