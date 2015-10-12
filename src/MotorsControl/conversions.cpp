/*
============================================================================
 Name : conversions.h
 Author : fuge2701 & fouj1807
 Version : V0.2
 Modified on: 2015-10-08
 Description : Implementation of the different conversion functions
============================================================================
*/
#include "MotorsControl/conversions.h"

float holesForTurn(int degree)
{
	 float dist = (float)TURN_AXIS_CIRC * ((float)degree / float(360.0));
	 return holesForDistance(dist);
}

float holesForDistance(float distanceCM)
{
	return distanceCM / (float)WHEEL_CIRC * (float)HOLES_QTY;
}

float travelledDistance(float holesQty)
{
	return ((float)WHEEL_CIRC/(float)HOLES_QTY) * holesQty;
}

float distanceForDegree (float degree)
{
	return (degree/(float)360) * WHEEL_AXE_CIRC;
}

