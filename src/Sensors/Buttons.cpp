#include "Sensors/Buttons.h"

int ButtonStatus(int number)
{
	switch(number)
	{
		case 1:
			return DIGITALIO_Read(13);
			break;

		case 2:
			return DIGITALIO_Read(12);
			break;

		case 3:
			return DIGITALIO_Read(11);
			break;

		default:
			return -1;
			break;
	}

	return -1;
}



