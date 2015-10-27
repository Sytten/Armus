/*
============================================================================
 Name : Line detection
 Author : M.A.G.I.E Team
 Modified on: 2015-10-14
 Description : The line follower sensor can be access with this API.
			   We can also check if we are centered.
============================================================================
*/
#ifndef LINEDETECTION_H_
#define LINEDETECTION_H_

#include <libarmus.h>

#define LEFT_LINE_DETECT 14
#define CENTER_LINE_DETECT 16
#define RIGHT_LINE_DETECT 15

bool isLeftDetect();
bool isCenterDetect();
bool isRightDetect();

bool isCentered();

#endif /* LINEDETECTION_H_ */
