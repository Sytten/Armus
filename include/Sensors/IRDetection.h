/*
============================================================================
 Name : constants
 Author : M.A.G.I.E Team
 Modified on: 2015-10-14
 Description : The IR function check the inputs and return a single variable
			   (with the help of the bitwise operator). Check can be done to
			   verify if the direction detects something.
============================================================================
*/

#ifndef IRDETECTION_H_
#define IRDETECTION_H_

#include <libarmus.h>

#define IR_FRONT_LEFT 7
#define IR_FRONT_RIGHT 6
#define IR_RIGHT_LEFT 5
#define IR_RIGHT_RIGHT 4
#define IR_BACK_LEFT 3
#define IR_BACK_RIGHT 2
#define IR_LEFT_LEFT 1
#define IR_LEFT_RIGHT 0

#define MINIMUM_DISTANCE 10
#define MULTIPLICATOR 0.1

char sensor_IRDetection();

bool doesIRDetect(char position);

float getExternalIR(int pinNumber);

#endif /* IRDETECTION_H_ */
