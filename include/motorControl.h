/*
============================================================================
 Name : motorControl.h
 Author : fuge2701 & fouj1807
 Version : V0.1
 Created on: 2015-09-24
 Description : Definition of the spin and roll functions
============================================================================
*/

#ifndef MOTORCONTROL_H_
#define MOTORCONTROL_H_

#include <libarmus.h>
#include <math.h>

#include "constants.h"


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

bool spin(int direction, float degree);

/**
 *
 */
bool turn(int direction, float degree);

//Roll
bool roll(int distance);

#endif /* MOTORCONTROL_H_ */
