/*
============================================================================
 Name : conversions
 Author : M.A.G.I.E Team
 Modified on: 2015-10-08
 Description : Definition of the different conversion functions
============================================================================
*/
#ifndef CONVERSIONS_H_
#define CONVERSIONS_H_

#include "MotorsControl/constants.h"

/**
 * Converts the holes necessary for the robot to turn degree degrees
 * @param degree The degrees to turn
 * @return The quantity of encoder holes to turn
 */
float holesForTurn(int degree);

/**
 * Converts the number of encoder holes to roll to do the distanceCM CMs
 * @param distanceCM The quantity of CM to roll
 * @return The hole quantity to travel
 */
float holesForDistance(float distanceCM);

/**
 * Calculates the distance travelled for holesQty encoder holes
 * @param holesQty The number of holes to convert in distance
 * @return Number of centi-meters travelled
 */
float travelledDistance(float holesQty);

/**
 * The distance to travel for a number of degrees of rotation
 * @param degree Quantity of degrees to turn
 * @return the distance to travel
 */
float distanceForDegree (float degree);

#endif /* CONVERSIONS_H_ */
