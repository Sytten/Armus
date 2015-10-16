#include "Sensors/ColorSensor.h"

Color ColorSensor::getColor()
{
	return RGB_To_Color(getRGBColor());
}

RGB getRGBColor()
{
	RGB color;

	if(SensorType == Digital)
	{
		//Turn LED on
		DIGITALIO_Write(9, 1); /*******change depending on contact point*******/
		THREAD_MSleep (200);
		// Read pipes and compensate
		color.R = ANALOG_Read(1) * 10;
		color.G = ANALOG_Read(2) * 12;
		color.B = ANALOG_Read(3) * 19;
		//Turn LED off
		DIGITALIO_Write(9, 0); /*******change depending on contact point*******/
	}

	else if(SensorType == Analog)
	{

	}

	return color;
}

Color RGB_To_Color(RGB p_RGB)
{
	Color color(Other);

	return color;
}

