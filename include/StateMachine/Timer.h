/*
============================================================================
 Name : Timer
 Author : M.A.G.I.E Team
 Modified on: 2015-10-14
 Description : Shitty global variables to check time
============================================================================
*/

#ifndef TIMER_H_
#define TIMER_H_

#include <libarmus.h>

class BeginTime
{
public:
	static float globalTime;
};

bool NinjaTimesUp();
bool SumoTimesUp();


#endif /* TIMER_H_ */
