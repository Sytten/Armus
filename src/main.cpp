/*
============================================================================
 Name : main.cpp
 Authors : fuge2701 & fouj1807
 Version : V0.2
 Modified on: 2015-10-08
 Description : Main program
============================================================================
*/

#include <libarmus.h>
#include "MotorsControl/motorsControl.h"

void robot6();
void robot4();

int main()
{
	while(1)
	{
		if(DIGITALIO_Read(BMP_LEFT))
		{
			robot4();
		}
		else if(DIGITALIO_Read(BMP_REAR))
		{
			robot6();
		}
		THREAD_MSleep(100);
	}
	return 0;
}

void robot6()
{
	CorrectionData wheelError;

	wheelError.RightError = 0;
	wheelError.LeftError = 0;

	roll(210);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(35);
	turn(SPIN_RIGHT, 90, &wheelError);
	roll(30);
	turn(SPIN_RIGHT, 90, &wheelError);
	roll(30);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(20);
	turn(SPIN_RIGHT, 45, &wheelError);
	roll(35);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(63);
	turn(SPIN_RIGHT, 40, &wheelError);
	roll(43);
	turn(SPIN_RIGHT, 15, &wheelError);
	roll(80);

	spinXDegreesByHoles(SPIN_LEFT, 185);
	roll(80);
	turn(SPIN_LEFT, 12, &wheelError);
	roll(45);
	turn(SPIN_LEFT, 45, &wheelError);
	roll(63);
	turn(SPIN_RIGHT, 85, &wheelError);
	roll(37);
	turn(SPIN_LEFT, 45, &wheelError);
	roll(18);
	turn(SPIN_RIGHT, 90, &wheelError);
	roll(35);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(30);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(35);
	turn(SPIN_RIGHT, 90, &wheelError);
	roll(220);

}

void robot4()
{
	CorrectionData wheelError;

	wheelError.RightError = 0;
	wheelError.LeftError = 0;

	roll(210);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(34);
	turn(SPIN_RIGHT, 90, &wheelError);
	roll(35);
	turn(SPIN_RIGHT, 90, &wheelError);
	roll(30);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(20);
	turn(SPIN_RIGHT, 50, &wheelError);
	roll(38);
	turn(SPIN_LEFT, 85, &wheelError);
	roll(62);
	turn(SPIN_RIGHT, 45, &wheelError);
	roll(42);
	turn(SPIN_RIGHT, 17, &wheelError);
	roll(80);

	spinXDegreesByHoles(SPIN_LEFT, 177);
	roll(84);
	turn(SPIN_LEFT, 17, &wheelError);
	roll(42);
	turn(SPIN_LEFT, 48, &wheelError);
	roll(62);
	turn(SPIN_RIGHT, 90, &wheelError);
	roll(40);
	turn(SPIN_LEFT, 42, &wheelError);
	roll(20);
	turn(SPIN_RIGHT, 90, &wheelError);
	roll(30);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(35);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(34);
	turn(SPIN_RIGHT, 90, &wheelError);
	roll(220);
}

