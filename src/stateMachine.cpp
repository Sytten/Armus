/*
 * stateMachine.cpp
 *
 *  Created on: 2015-10-03
 *      Author: Jeep
 */

#include "stateMachine.h"

int run()
{
	struct Machine robus;
	robus.CurrentState = StatesInit;

	while(robus.CurrentState != StatesExit)
	{

		getSensorStatus(&robus);

		switch (robus.CurrentState)
		{
			case StatesInit:
				robus.MotorLeftSpeed = robus.MotorRightSpeed = 0;
				robus.StateParameter = 0;
				robus.NextState = StatesStop;
				robus.IRSensorStates = 0;
				robus.MotorLeftEncoder  = robus.MotorRightEncoder = 0;
				break;
			case StatesStop:
				break;
			case StatesTurn:
				break;
			case StatesSpin:
				break;
			case StatesRoll:
				break;
			case StatesEnd:
				break;
			default:
				MOTOR_SetSpeed(MOTOR_LEFT, 0);
				MOTOR_SetSpeed(MOTOR_RIGHT, 0);
				LCD_ClearAndPrint("Error in state execution");
				THREAD_MSleep(5000);
				return 0;
		}

		MOTOR_SetSpeed(MOTOR_LEFT, robus.MotorLeftSpeed);
		MOTOR_SetSpeed(MOTOR_RIGHT, robus.MotorRightSpeed);

		if(robus.NextState != robus.CurrentState)
		{
			switch (robus.NextState)
			{
				case StatesStop:
					robus.MotorLeftSpeed = robus.MotorRightSpeed = 0;
					MOTOR_SetSpeed(MOTOR_LEFT, robus.MotorLeftSpeed);
					MOTOR_SetSpeed(MOTOR_RIGHT, robus.MotorRightSpeed);
					break;
				case StatesTurn:
					break;
				case StatesSpin:
					break;
				case StatesEnd:
					break;
				case StatesRoll:
					robus.MotorLeftSpeed = robus.MotorRightSpeed = 0;
					MOTOR_SetSpeed(MOTOR_LEFT, robus.MotorLeftSpeed);
					MOTOR_SetSpeed(MOTOR_RIGHT, robus.MotorRightSpeed);
					break;
				default:
					MOTOR_SetSpeed(MOTOR_LEFT, 0);
					MOTOR_SetSpeed(MOTOR_RIGHT, 0);
					Print_Debug_Data("Error in state changing",DEBUG_CODE);
					THREAD_MSleep(5000);
					robus.CurrentState = StatesInit;
					break;
			}

			robus.MotorLeftEncoderTotal = robus.MotorRightEncoderTotal = 0;
			robus.CurrentState = robus.NextState;
		}
	}

	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);

	return 1;
}

void getSensorStatus(struct Machine * machine)
{
	machine->IRSensorStates = sensors_IRDetection();
	machine->MotorLeftEncoderLast = ENCODER_Read(ENCODER_LEFT);
	machine->MotorRightEncoderLast = ENCODER_Read(ENCODER_RIGHT);
	machine->MotorLeftEncoderTotal += machine->MotorLeftEncoderLast;
	machine->MotorRightEncoderTotal += machine->MotorRightEncoderLast;
}

void Print_Debug_Data(const char * message, int level)
{
	if((level >= DEBUG_LEVEL && DEBUG_LEVEL != DEBUG_BASE)
			|| (level == DEBUG_BASE && DEBUG_LEVEL == DEBUG_BASE))
		LCD_Printf(message);
}

