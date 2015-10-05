/*
============================================================================
 Name : constants.h
 Author : fuge2701 & fouj1807
 Version : V0.1
 Created on: 2015-09-24
 Description : Constants for the robot
============================================================================
*/

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#define PI_VAL 3.1416

/*****Wheel specifications*****/
#define WHEEL_DIAMETER 7.5
#define HOLES_QTY 64
#define WHEEL_CIRC (WHEEL_DIAMETER * PI_VAL)

#define WHEEL_AXE_DIAM 14
#define WHEEL_AXE_DIAM_MODIFIER 0
#define WHEEL_AXE_DIAM_MODIFIED (WHEEL_AXE_DIAM + WHEEL_AXE_DIAM_MODIFIER)
#define WHEEL_AXE_CIRC (WHEEL_AXE_DIAM_MODIFIED * PI_VAL)

/*****Spin function*****/
#define SPIN_LEFT 0
#define SPIN_RIGHT 1
#define MOTOR_DEFAULT_SPEED 65
#define READING_CYCLE_DELAY 100
#define MAX_PRECISION 2

/*****TURN FUNCTION*****/
#define TURN_AXIS_DIAMETER 2 * WHEEL_AXE_DIAM
#define TURN_AXIS_CIRC (TURN_AXIS_DIAMETER * PI_VAL)

/*****Roll Function****/
#define LEFT_STARTING_SPEED 74 //Robot4:74 Robot6:74
#define RIGHT_STARTING_SPEED 75 //Robot4:75 Robot6:75
#define INSTANT_PROPORTIONALITY 0.8 //0.8
#define LONG_PROPORTIONALITY 0.5 //0.5
#define MOTOR_TARGET_SPEED 30

#endif /* CONSTANTS_H_ */

