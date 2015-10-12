/*
============================================================================
 Name : main.cpp
 Authors : fuge2701 & fouj1807
 Version : V0.1
 Description : Main program
============================================================================
*/

#include <libarmus.h>
#include "motorControl.h"
#include "stateMachine.h"

void robot6();
void robot4();

int main()
{
	while(1)
	{
		if(DIGITALIO_Read(BMP_LEFT))
		{
<<<<<<< HEAD
			roll(223);
			spin(SPIN_LEFT, 90);
			roll(48);
			spin(SPIN_RIGHT, 90);
			roll(45);
			spin(SPIN_RIGHT, 90);
			roll(48);
			spin(SPIN_LEFT, 90);
			roll(32);
			spin(SPIN_RIGHT, 45);
			roll(77);
			spin(SPIN_LEFT, 90);
			roll(63);
			spin(SPIN_RIGHT, 45);
			roll(50);
			spin(SPIN_RIGHT, 12.5);
			roll(80);
		}
		else if(DIGITALIO_Read(BMP_REAR))
		{
			roll(210);
			turn(SPIN_LEFT, (float)90);
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
=======
			//robot4();
		}
		else if(DIGITALIO_Read(BMP_REAR))
		{
			robot6();
>>>>>>> f336c15f6e3b88ea571735efe49f03b844beee5d
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

