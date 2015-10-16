#include "Sensors/ColorSensor.h"

ColorSensor::ColorSensor(SensorType p_type):m_type(p_type)
{
	if(m_type == Analog)
	{
		ERROR_CHECK(color_Init(adjd_dev));

		cap_SetValue(CAP_RED, 15);
		cap_SetValue(CAP_GREEN, 15);
		cap_SetValue(CAP_BLUE, 15);
		cap_SetValue(CAP_CLEAR, 15);

		integrationTime_SetValue(INTEGRATION_RED, 255);
		integrationTime_SetValue(INTEGRATION_GREEN, 255);
		integrationTime_SetValue(INTEGRATION_BLUE, 255);
		integrationTime_SetValue(INTEGRATION_CLEAR, 255);
	}
}

Color ColorSensor::getColor()
{
	return RGB_To_Color(getRGBColor());
}

RGB ColorSensor::getRGBColor()
{
	RGB color;
	int clear = 0;

	if(m_type == Digital)
	{
		led_TurnOn();

		THREAD_MSleep (200);

		// Read pipes and compensate
		color.R = ANALOG_Read(1) * 10;
		color.G = ANALOG_Read(2) * 12;
		color.B = ANALOG_Read(3) * 19;

		led_TurnOff();
	}

	else if(m_type == Analog)
	{
		color_Read(color.R, color.B, color.G, clear);
	}

	return color;
}

Color ColorSensor::RGB_To_Color(RGB p_RGB)
{
	Color color(Other);

	return color;
}

// TODO: change contact point
void ColorSensor::led_TurnOff()
{
	DIGITALIO_Write(9, 0);
}

// TODO: change contact point
void ColorSensor::led_TurnOn()
{
	DIGITALIO_Write(9, 1);
}

/**************For the analog sensor, please don't fuck it up**************/

//The argument is an integer that should not be modified
int ColorSensor::color_Init(int& dev_handle)
{
	int error;
	error = armus::i2c_RegisterDevice(ADJD_S371_QR999_SADR, 100000, 1000, dev_handle);

	return error;
}

void ColorSensor::color_ReadToCalibrate(int& data_red, int& data_blue, int& data_green, int& data_clear)
{
	led_TurnOn();
	adjd_SetRegister(ADJD_REG_CONFIG, 0 << CONFIG_TOFS);
	adjd_SetRegister(ADJD_REG_CTRL, 1 << CTRL_GSSR);
	while(adjd_ReadRegister(ADJD_REG_CTRL))
	{
		THREAD_MSleep(50);
	}
	led_TurnOff();

	data_red = adjd_ReadRegister16(DATA_RED_LO);
	data_green = adjd_ReadRegister16(DATA_GREEN_LO);
	data_blue = adjd_ReadRegister16(DATA_BLUE_LO);
	data_clear = adjd_ReadRegister16(DATA_CLEAR_LO);

}

//Allow a differential reading with or without light from the LED
void ColorSensor::color_Read(int& data_red, int& data_blue, int& data_green, int& data_clear)
{
	//First read without light
	led_TurnOff();

	adjd_SetRegister(ADJD_REG_CONFIG, 1 << CONFIG_TOFS);
	adjd_SetRegister(ADJD_REG_CTRL, 1 << CTRL_GOFS);
	while(adjd_ReadRegister(ADJD_REG_CTRL))
	{
		THREAD_MSleep(50);
	}

	//Read with light
	led_TurnOn();
	adjd_SetRegister(ADJD_REG_CTRL, 1 << CTRL_GSSR);
	while(adjd_ReadRegister(ADJD_REG_CTRL))
	{
		THREAD_MSleep(50);
	}

	led_TurnOff();

	data_red = adjd_ReadRegister16(DATA_RED_LO);
	data_green = adjd_ReadRegister16(DATA_GREEN_LO);
	data_blue = adjd_ReadRegister16(DATA_BLUE_LO);
	data_clear = adjd_ReadRegister16(DATA_CLEAR_LO);
}

//Allow us to read values in registers
unsigned char ColorSensor::adjd_ReadRegister(unsigned char reg)
{
	unsigned char val;

	armus::i2c_ReadAfterWrite(adjd_dev, 1, &reg, 1, &val);

	return val;
}

//Allow us to change values in registers
void ColorSensor::adjd_SetRegister(unsigned char reg, unsigned char val)
{
	unsigned char data[2];
	data[0] = reg;
	data[1] = val;
	armus::i2c_Write(adjd_dev, 2, data);
}

//Allow us to read values in 16bits registers
int ColorSensor::adjd_ReadRegister16(unsigned char reg)
{
	int val16;
	unsigned char val;
	armus::i2c_ReadAfterWrite(adjd_dev, 1, &reg, 1, &val);
	val16 = val;
	reg = reg+1;
	armus::i2c_ReadAfterWrite(adjd_dev, 1, &reg, 1, &val);
	val16 = val16 + ((val << 8) & 0xFF00);
	return val16;
}

//Allow us to change values in 16bits registers
void ColorSensor::adjd_SetRegister16(unsigned char reg, int val)
{
	unsigned char data[2];
	data[0] = reg;
	data[1] = val & 0xFF;
	armus::i2c_Write(adjd_dev, 2, data);
	data[0] = reg+1;
	data[1] = (val >> 8) & 0xFF;
	armus::i2c_Write(adjd_dev, 2, data);
}

// Allow us to get the value of CAP in the register
// take as argument a constant CAP_RED, CAP_BLUE, CAP_CLEAR or CAP_GREEN
// return an unsigned char of the value
unsigned char ColorSensor::cap_GetValue(unsigned char cap_address)
{
	return adjd_ReadRegister(cap_address);
}

// Allow us to set the value of CAP in the register
// take as first argument a constant CAP_RED, CAP_BLUE, CAP_CLEAR or CAP_GREEN
// the second argument is a number between 0 and 15, is it the value of CAP to write in the register
void ColorSensor::cap_SetValue(unsigned char cap_address, unsigned char cap_value)
{
	adjd_SetRegister(cap_address, cap_value);
}

// Allow us to get the value of CAP in the register
// take as first argument an address like INTEGRATION_RED, ...
// return an integer of the value read
int ColorSensor::integrationTime_GetValue(unsigned char address)
{
	return adjd_ReadRegister16(address);
}

// Allow us to set the value of CAP in the register
// take as first argument an address like INTEGRATION_RED, ...
// the second argument is a time value between 0 and 4095, is it the value of CAP to write in the register
void ColorSensor::integrationTime_SetValue(unsigned char address, int time_value)
{
	adjd_SetRegister16(address, time_value);
}



