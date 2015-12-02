/*
============================================================================
 Name : main
 Authors : M.A.G.I.E Team
 Version : V0.4.3
 Modified on: 2015-10-15
 Description : The Armus project is the S1 project at Sherbrooke university.
			   The code is under the MIT license. Please refer to the license
			   file for more information.
============================================================================
*/

#include "StateMachine/StateMachine.h"



int main()
{
	srand(time(NULL));
	LCD_SetMonitorMode(MONITOR_OFF);

	return run();

}

