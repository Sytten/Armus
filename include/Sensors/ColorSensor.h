/*
============================================================================
 Name : Color sensor
 Author : M.A.G.I.E Team
 Modified on: 2015-10-16
 Description : The color sensor allows us to reads the color under the robot.
			   We support both digital and analog sensors.
============================================================================
*/

#ifndef COLORSENSOR_H_
#define COLORSENSOR_H_

#define ADJD_S371_QR999_SADR 	0x74
#define CAP_RED					0x6
#define CAP_GREEN				0x7
#define CAP_BLUE				0x8
#define CAP_CLEAR				0x9
#define INTEGRATION_RED			10
#define INTEGRATION_GREEN		12
#define INTEGRATION_BLUE		14
#define INTEGRATION_CLEAR		16
#define ADJD_REG_CTRL			0
#define ADJD_REG_CONFIG			1
#define DATA_RED_LO				64
#define DATA_GREEN_LO			66
#define DATA_BLUE_LO			68
#define DATA_CLEAR_LO			70

#define CTRL_GSSR				0
#define CTRL_GOFS				1

#define CONFIG_TOFS				0

int adjd_dev;

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
		ColorSensor(SensorType p_type);

		Color getColor();
		RGB getRGBColor();

		Color RGB_To_Color(RGB p_RGB);

	private:
		void led_TurnOff();
		void led_TurnOn();

	private:
		SensorType m_type;

	private: //For the analog sensor, please don't fuck it up. For more information, check the source file
		int color_Init(int& dev_handle);
		void color_ReadToCalibrate(int& data_red, int& data_blue, int& data_green, int& data_clear);
		void color_Read(int& data_red, int& data_blue, int& data_green, int& data_clear);

		int adjd_ReadRegister16(unsigned char reg);
		void adjd_SetRegister16(unsigned char reg, int val);

		unsigned char adjd_ReadRegister(unsigned char reg);
		void adjd_SetRegister(unsigned char reg, unsigned char val);

		unsigned char cap_GetValue(unsigned char cap_address);
		void cap_SetValue(unsigned char cap_address, unsigned char cap_value);

		int integrationTime_GetValue(unsigned char address);
		void integrationTime_SetValue(unsigned char address, int time_value);
};

#endif /* COLORSENSOR_H_ */
