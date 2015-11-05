/*
 * Timer.cpp
 *
 *  Created on: 2015-10-27
 *      Author: emile
 */
#include "StateMachine/Timer.h"

float BeginTime::globalTime = 0;

bool NinjaTimesUp()
{ if(SYSTEM_ReadTimerMSeconds() + 115000 > BeginTime::globalTime)
						return true;
					  else
						return false;
}

bool SumoTimesUp()
{
	if(SYSTEM_ReadTimerMSeconds() + 175000 > BeginTime::globalTime)
	return true;
  else
	return false;
}
