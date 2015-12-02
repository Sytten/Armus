/*
============================================================================
 Name : constants
 Author : M.A.G.I.E Team
 Modified on: 2015-10-14
 Description : Constants for the robot roll, spin and turn functions.
			   ***Please do not modify***
============================================================================
*/

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

//General specifications
#define PI_VAL 3.1416
#define ROBOT6


/*****Wheel specifications*****/
//Wheel specifications
#define WHEEL_DIAMETER 7.5
#define HOLES_QTY 64
#define WHEEL_CIRC (WHEEL_DIAMETER * PI_VAL)

#define WHEEL_AXE_DIAM 14
#define WHEEL_AXE_DIAM_MODIFIER 0
#define WHEEL_AXE_DIAM_MODIFIED (WHEEL_AXE_DIAM + WHEEL_AXE_DIAM_MODIFIER)
#define WHEEL_AXE_CIRC (WHEEL_AXE_DIAM_MODIFIED * PI_VAL)


/*****Spin and turn functions*****/
//Spin function
#define SPIN_LEFT 0
#define SPIN_RIGHT 1

//Turn function
#define TURN_LEFT 0
#define TURN_RIGHT 1
#define TURN_AXIS_DIAMETER 2 * WHEEL_AXE_DIAM
#define TURN_AXIS_CIRC (TURN_AXIS_DIAMETER * PI_VAL)

//General purpose
#define MOTOR_DEFAULT_SPEED 65
#define READING_CYCLE_DELAY 25
#define MAX_PRECISION 2


/*****Roll Function*****/
#ifdef ROBOT4
#define LEFT_STARTING_SPEED 75
#define RIGHT_STARTING_SPEED 74
#endif

#ifdef ROBOT6
#define LEFT_STARTING_SPEED 74
#define RIGHT_STARTING_SPEED 75
#endif

#define ROLL_FORWARD 1
#define ROLL_BACKWARDS -1

#define ROLL_READING_CYCLE_DELAY 100
#define INSTANT_PROPORTIONALITY 0.4
#define LONG_PROPORTIONALITY 0.25
#define MOTOR_TARGET_SPEED 15

#endif /* CONSTANTS_H_ */

