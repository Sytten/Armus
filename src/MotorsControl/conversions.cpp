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

float turnForHoles(int holesQty)
{
	 float dist = travelledDistance(holesQty);
	 return (dist/WHEEL_AXE_CIRC) * (float)360;
}

