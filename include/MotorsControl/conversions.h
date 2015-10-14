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

float holesForTurn(int degree);

float holesForDistance(float distanceCM);

float travelledDistance(float holesQty);

float distanceForDegree (float degree);

#endif /* CONVERSIONS_H_ */
