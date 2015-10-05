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
	while(1)
	{
		if(DIGITALIO_Read(BMP_FRONT))
		{
			roll(223);
			spinXDegrees(SPIN_LEFT, 90);
			roll(48);
			spinXDegrees(SPIN_RIGHT, 90);
			roll(45);
			spinXDegrees(SPIN_RIGHT, 90);
			roll(48);
			spinXDegrees(SPIN_LEFT, 90);
			roll(32);
			spinXDegrees(SPIN_RIGHT, 45);
			roll(77);
			spinXDegrees(SPIN_LEFT, 90);
			roll(63);
			spinXDegrees(SPIN_RIGHT, 45);
			roll(50);
			spinXDegrees(SPIN_RIGHT, 12.5);
			roll(80);
		}
		else if(DIGITALIO_Read(BMP_REAR))
		{
			roll(210);
			turn(SPIN_LEFT, 90);
			roll(35);
			turn(SPIN_RIGHT, 90);
			roll(30);
			turn(SPIN_RIGHT, 90);
			roll(35);
			turn(SPIN_LEFT, 90);
			roll(18);
			turn(SPIN_RIGHT, 45);
			roll(35);
			turn(SPIN_LEFT, 88);
			roll(48);
			turn(SPIN_RIGHT, 45);
			roll(43);
			turn(SPIN_RIGHT, 20);
			roll(74);

			turn(SPIN_RIGHT, 180);
			roll(74);
			turn(SPIN_LEFT, 15);
			roll(43);
			turn(SPIN_LEFT, 45);
			roll(48);
			turn(SPIN_RIGHT, 90);
			roll(35);
			turn(SPIN_LEFT, 45);
			roll(18);
			turn(SPIN_RIGHT, 90);
			roll(35);
			turn(SPIN_LEFT, 90);
			roll(30);
			turn(SPIN_LEFT, 90);
			roll(35);
			turn(SPIN_RIGHT, 90);
			roll(220);
		}
		THREAD_MSleep(100);
	}
	   
	return 0;
}
