
#include "Sensors/LineDetection.h"

bool isLeftDetect()
{
	return !DIGITALIO_Read(LEFT_LINE_DETECT);
}

bool isCenterDetect()
{
	return !DIGITALIO_Read(CENTER_LINE_DETECT);
}

bool isRightDetect()
{
	return !DIGITALIO_Read(RIGHT_LINE_DETECT);
}

bool isCentered()
{
	return (isCenterDetect() && !isLeftDetect() && !isRightDetect());
}
