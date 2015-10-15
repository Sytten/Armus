/*
============================================================================
 Name : motorsControl
 Author : M.A.G.I.E Team
 Modified on: 2015-10-14
 Description : Definition of the spin and roll functions
============================================================================
*/

#ifndef MOTORSCONTROL_H_
#define MOTORSCONTROL_H_

#include <libarmus.h>
#include <math.h>

#include "MotorsControl/constants.h"
#include "MotorsControl/conversions.h"

class Robot;

//Error correction
struct CorrectionData
{
	float LeftError;
	float RightError;
};
/**
 *	@brief Returns the number of wheel holes that represent a degree angle of rotation for a trun
 *	@param degree The number of degree of rotation
 *	@return The number of encoder holes that make a degree angle rotation
 */
float holesForTurn(int degree);
/**
 *	@brief Returns the number of wheel holes that represent a degree angle of rotation for a spin
 *	@param degree The number of degree of rotation
 *	@return The number of encoder holes that make a degree angle rotation
 */
float holesForSpin(int degree);
/**
 * @brief Calculates the distance in encoder holes to drive for a distance in centimeters
 * @param degree
 * @return
 */
float holesForDistance(float centimeters);
/**
 *	@brief Evaluates the distance travelled with the number of encoder holes passed as parameter
 *	@param holesQty The number of encoder holes to evaluate the distance of
 *	@return The distance in centimeters that would be travelled by holesQty number of encoder holes
 */
float distanceForHoles(float holesQty);
/**
 *	@brief Evaluates the distance a wheel has to travel to rotate the robot on itself for degree angle of rotation
 *	@param degree
 *	@return
 */
float distanceForDegreeSpin (float degree);

/**
 *
 */
bool turn(int direction, float degree, struct CorrectionData * error);

//Spin
bool spinXDegrees(int direction, float degree);
bool spinXDegreesByHoles(int direction, float degree);


//Roll
bool roll(int distance);

#endif /* MOTORSCONTROL_H_ */

