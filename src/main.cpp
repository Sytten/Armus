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
			roll(120);
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
	roll(37);
	turn(SPIN_LEFT, 85);
	roll(56);
	turn(SPIN_RIGHT, 45);
	roll(45);
	turn(SPIN_RIGHT, 15);
	roll(80);

	spinXDegrees(SPIN_LEFT, 182);
	roll(80);
	turn(SPIN_LEFT, 12);
	roll(45);
	turn(SPIN_LEFT, 45);
	roll(53);
	turn(SPIN_RIGHT, 85);
	roll(37);
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

void robot4()
{
	roll(210);
	turn(SPIN_LEFT, 90);
	roll(30);
	turn(SPIN_RIGHT, 92);
	roll(30);
	turn(SPIN_RIGHT, 93);
	roll(38);
	turn(SPIN_LEFT, 90);
	roll(20);
	turn(SPIN_RIGHT, 50);
	roll(40);
	turn(SPIN_LEFT, 85);
	roll(60);
	turn(SPIN_RIGHT, 45);
	roll(45);
	turn(SPIN_RIGHT, 25);
	roll(80);

	spinXDegrees(SPIN_LEFT, 180);
	roll(80);
	turn(SPIN_LEFT, 12);
	roll(45);
	turn(SPIN_LEFT, 48);
	roll(58);
	turn(SPIN_RIGHT, 85);
	roll(37);
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

