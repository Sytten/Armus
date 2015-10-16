/*
============================================================================
 Name : Color sensor
 Author : M.A.G.I.E Team
 Modified on: 2015-10-16
 Description : The color sensor allows us to reads the color under the robot.
============================================================================
*/

#ifndef COLORSENSOR_H_
#define COLORSENSOR_H_

#include <libarmus.h>
#include "Sensors/Colors.h"

enum SensorType
{
	Digital = 0,
	Analog
};

struct RGB
{
	RGB(): R(0), G(0), B(0) {}
	RGB(int p_R, int p_G, int p_B): R(p_R), G(p_G), B(p_B) {}
	int R;
	int G;
	int B;
};

class ColorSensor
{
	public:
		ColorSensor(SensorType p_type): m_type(p_type) {}

		Color getColor();
		RGB getRGBColor();

		Color RGB_To_Color(RGB p_RGB);

	private:
		SensorType m_type;
};

#endif /* COLORSENSOR_H_ */
