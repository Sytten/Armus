/*
============================================================================
 Name : IR detection
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

//Enumeration of values to easily represent the direction of the detection in the sensors_IRDetection() format
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

/*
 * Reads the IR sensors and returns an char with a representation of all possible detection directions
 * @return The IR bits
 */
char sensor_IRDetection();

/*
 * Given a char with IR state bits, returns true or false if the position is on
 * @param position The char with the IR state bits
 * @return True if detection at position
 */
bool doesIRDetect(char position);

/*
 * Function to read an external IR detector
 * @param pinNumber The pin number on which the IR sensor is plugged
 * @return The distance of the detection from the IR sensor
 */
float getExternalIR(int pinNumber);

#endif /* IRDETECTION_H_ */
