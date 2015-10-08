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

void robot6();
void robot4();

int main()
{
	while(1)
	{
		if(DIGITALIO_Read(BMP_LEFT))
		{
			//robot4();
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
	struct CorrectionData wheelError;

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
	struct CorrectionData wheelError;

	wheelError.RightError = 0;
	wheelError.LeftError = 0;

	roll(210);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(30);
	turn(SPIN_RIGHT, 92, &wheelError);
	roll(30);
	turn(SPIN_RIGHT, 93, &wheelError);
	roll(38);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(20);
	turn(SPIN_RIGHT, 50, &wheelError);
	roll(40);
	turn(SPIN_LEFT, 85, &wheelError);
	roll(68);
	turn(SPIN_RIGHT, 45, &wheelError);
	roll(45);
	turn(SPIN_RIGHT, 20, &wheelError);
	roll(80);

	spinXDegrees(SPIN_LEFT, 180);
	roll(80);
	turn(SPIN_LEFT, 12, &wheelError);
	roll(45);
	turn(SPIN_LEFT, 48, &wheelError);
	roll(58);
	turn(SPIN_RIGHT, 85, &wheelError);
	roll(37);
	turn(SPIN_LEFT, 42, &wheelError);
	roll(18);
	turn(SPIN_RIGHT, 90, &wheelError);
	roll(35);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(30);
	turn(SPIN_LEFT, 90, &wheelError);
	roll(35);
	turn(SPIN_RIGHT, 92, &wheelError);
	roll(220);
}

