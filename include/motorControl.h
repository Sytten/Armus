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

//Spin
bool spinXDegreesCM(int direction, float degree);
float travelledDistance(float holesQty);
float distanceForDegree (float degree);

float holesForDistance(float distanceCM);
bool spinXDegrees(int direction, float degree);

//Roll
bool roll(int distance);

#endif /* MOTORCONTROL_H_ */
