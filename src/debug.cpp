#include "debug.h"

using namespace std;

void Print_Debug_Data(const char * message, int level)
{
	if((level >= DEBUG_LEVEL && DEBUG_LEVEL != DEBUG_BASE)
			|| (level == DEBUG_BASE && DEBUG_LEVEL == DEBUG_BASE))
		LCD_Printf(message);
}

void Log_Debug_data(string message, int level)
{
	ofstream debugFile;

	debugFile.open(DEBUG_FILE_PATH, ios::out | ios::app);
	if(debugFile.is_open())
	{
		if((level >= DEBUG_LEVEL && DEBUG_LEVEL != DEBUG_BASE)
					|| (level == DEBUG_BASE && DEBUG_LEVEL == DEBUG_BASE))
			debugFile << message << std::endl;

		debugFile.close();
	}
	else
		LCD_Printf("Error opening debug file!");
}

void Clear_Log_File()
{
	ofstream debugFile;

	debugFile.open(DEBUG_FILE_PATH);

	if(debugFile.is_open())
		debugFile.close();
	else
		LCD_Printf("Error clearing debug file!");
}
