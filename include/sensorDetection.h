/*
 * sensorDetection.h
 *
 *  Created on: 2015-10-03
 *      Author: Jeep
 */

#ifndef SENSORDETECTION_H_
#define SENSORDETECTION_H_

#include <libarmus.h>
#include "constants.h"

#define IR_FRONT_LEFT 7
#define IR_FRONT_RIGHT 6
#define IR_RIGHT_LEFT 5
#define IR_RIGHT_RIGHT 4
#define IR_BACK_LEFT 3
#define IR_BACK_RIGHT 2
#define IR_LEFT_LEFT 1
#define IR_LEFT_RIGHT 0

char sensors_IRDetection();

bool doesIRDetect(char position);

#endif /* SENSORDETECTION_H_ */
