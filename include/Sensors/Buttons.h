/*
============================================================================
 Name : Button
 Author : M.A.G.I.E Team
 Modified on: 2015-11-29
 Description : Simple API to get the buttons' input
============================================================================
*/

#ifndef BUTTONS_H_
#define BUTTONS_H_

#include <libarmus.h>

/**
 * Reads the status of the buttons on the front interface
 * @param number Button number to read
 * @return Value of the state of the button
 */
int ButtonStatus(int number);

#endif /* BUTTONS_H_ */
