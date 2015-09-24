/*
============================================================================
 Name : main.cpp
 Author : fuge2701 & fouj1807
 Version : V0.1
 Description : Test program
============================================================================
*/

#include <libarmus.h>
#include "motorControl.h"

int main()
{
	if(DIGITALIO_Read(BMP_FRONT))
		roll(150);
	
	if(DIGITALIO_Read(BMP_REAR))
	{
		LCD_Printf(" %f WHEEL_CIRC", WHEEL_CIRC);
		LCD_Printf(" %f  WHEEL_AXE_CIRC", WHEEL_AXE_CIRC);

		int degreesToTurn = 90;

		spinXDegrees(SPIN_LEFT, degreesToTurn);
		LCD_Printf("J'ai tourné de : %d ", degreesToTurn);

		//Pause de 2 sec
		THREAD_MSleep(2000);

		//LCD_Printf(" %f DISTANCE for 32", travelledDistance((float)32));
		//LCD_Printf(" %f  DIST for 1", travelledDistance((float)1));

		degreesToTurn = 180;

		spinXDegrees(SPIN_LEFT, degreesToTurn);
		LCD_Printf("J'ai tourné de : %d ", degreesToTurn);

		THREAD_MSleep(2000);

		degreesToTurn = 270;

		spinXDegrees(SPIN_LEFT, degreesToTurn);
		LCD_Printf("J'ai tourné de : %d ", degreesToTurn);

		THREAD_MSleep(2000);

		spinXDegrees(SPIN_RIGHT, degreesToTurn);
		LCD_Printf("J'ai tourné de : %d ", degreesToTurn);

		THREAD_MSleep(2000);
	}
	   
	return 0;
}
