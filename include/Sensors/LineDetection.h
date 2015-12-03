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

/*
 * Function that reads the line detector and returns if a line is detected
 * @return True if there is a line, false if not
 */
bool isLeftDetect();

/*
 * Function that reads the line detector and returns if a line is detected
 * @return True if there is a line, false if not
 */
bool isCenterDetect();

/*
 * Function that reads the line detector and returns if a line is detected
 * @return True if there is a line, false if not
 */
bool isRightDetect();

/*
 * Function that reads the line detector and returns if a line is detected
 * @return True if there is a line, false if not
 */
bool isCentered();

/*
 * Function that reads the line detector and returns true if a line is not detected
 * @return True if there is a line, false if not
 */
bool detectNoLine();

/*
 * Function that reads the line detector and returns true if all sensors read a line
 * @return True if there is a line, false if not
 */
bool detectFull();

#endif /* LINEDETECTION_H_ */
