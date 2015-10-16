#include "Sensors/IRDetection.h"

char sensor_IRDetection()
{
	char returnValue = 0;

	int temp = IR_Detect(IR_FRONT);
	returnValue |= temp << 6;

	temp = IR_Detect(IR_RIGHT);
	returnValue |= temp << 4;

	temp = IR_Detect(IR_BACK);
	returnValue |= temp << 2;

	temp = IR_Detect(IR_LEFT);
	returnValue |= temp << 0;

	return returnValue;

}

bool doesIRDetect(char sensorValues, char position)
{
	return ((sensorValues >> position) & 1);
}

float getExternalIR(int pinNumber)
{
	return ((float)(500-ANALOG_Read(pinNumber)) * MULTIPLICATOR) + 10;
}

