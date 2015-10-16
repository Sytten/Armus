/*
============================================================================
 Name : debug
 Author : M.A.G.I.E Team
 Modified on: 2015-10-15
 Description : The debug functions allow the user to print error messages or
			   write them in a log file.
============================================================================
*/
#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG_FILE_PATH "/media/usb0/ARMUS/debug.txt"

#define DEBUG_LEVEL 1
#define DEBUG_USER 2
#define DEBUG_CODE 1
#define DEBUG_BASE 0

#include <libarmus.h>
#include <fstream>
#include <iostream>
#include <string>

void Print_Debug_Data(const char * message, int level);
void Log_Debug_data(std::string message, int level);
void Clear_Log_File();

#endif
