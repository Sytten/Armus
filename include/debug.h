/*
============================================================================
 Name : debug
 Author : M.A.G.I.E Team
 Modified on: 2015-10-14
 Description : The debug functions allow the user to print error messages and
			   (TO BE ADDED) write them in a log file.
============================================================================
*/
#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG_LEVEL 1
#define DEBUG_USER 2
#define DEBUG_CODE 1
#define DEBUG_BASE 0

#include <libarmus.h>

void Print_Debug_Data(const char * message, int level);

#endif
