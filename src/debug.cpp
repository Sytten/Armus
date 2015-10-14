#include "debug.h"

void Print_Debug_Data(const char * message, int level)
{
	if((level >= DEBUG_LEVEL && DEBUG_LEVEL != DEBUG_BASE)
			|| (level == DEBUG_BASE && DEBUG_LEVEL == DEBUG_BASE))
		LCD_Printf(message);
}
