#include "stateMachine.h"

int run()
{
	int returnedValue;

	Machine robus;
	robus.CurrentState = StatesInit;

	while(robus.CurrentState != StatesExit)
	{

		getSensorStatus(&robus);

		/********STATE CHANGE LOGIC*********/
		//TO DO
		/******** END **********************/

		//Execute state
		switch (robus.CurrentState)
		{

			case StatesInit:
				robus.MotorLeftSpeed = robus.MotorRightSpeed = 0;
				robus.StateDistance = 0;
				robus.StateDegree = 0;
				robus.NextState = StatesStop;
				robus.IRSensorStates = 0;
				robus.MotorLeftEncoderTotal  = robus.MotorRightEncoderTotal = 0;
				robus.StateTicks = 0;
				break;
			case StatesStop:
				break;
			case StatesTurn:
				break;
			case StatesSpin:
				break;
			case StatesRoll:
				returnedValue = (rollState(&robus));

				if(returnedValue == CHANGED_SPEED)
				{
					robus.StateTicks++;
				}
				else if(returnedValue == FINISHED_ROLLING)
				{
					robus.NextState == StatesStop;
				}

				MOTOR_SetSpeed(MOTOR_LEFT, robus.MotorLeftSpeed);
				MOTOR_SetSpeed(MOTOR_RIGHT, robus.MotorRightSpeed);
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
			robus.MotorLeftSpeed = robus.MotorRightSpeed = 0;
			switch (robus.NextState)
			{
				case StatesStop:
					break;
				case StatesTurn:
					break;
				case StatesSpin:
					break;
				case StatesEnd:
					break;
				case StatesRoll:
					robus.MotorLeftSpeed = RIGHT_STARTING_SPEED;
					robus.MotorRightSpeed = LEFT_STARTING_SPEED;
					MOTOR_SetSpeed(MOTOR_LEFT, robus.MotorLeftSpeed);
					MOTOR_SetSpeed(MOTOR_RIGHT, robus.MotorRightSpeed);
					break;
				default:

					Print_Debug_Data("Error in state changing",DEBUG_CODE);
					THREAD_MSleep(5000);
					robus.CurrentState = StatesInit;
					break;
			}

			robus.MotorLeftEncoderTotal = robus.MotorRightEncoderTotal = 0;
			MOTOR_SetSpeed(MOTOR_LEFT, robus.MotorLeftSpeed);
			MOTOR_SetSpeed(MOTOR_RIGHT, robus.MotorRightSpeed);

			ENCODER_Read(ENCODER_LEFT);
			ENCODER_Read(ENCODER_RIGHT);

			robus.StateTicks = robus.StateLastMs = 0;
			robus.CurrentState = robus.NextState;
		}

	}

	MOTOR_SetSpeed(MOTOR_LEFT, 0);
	MOTOR_SetSpeed(MOTOR_RIGHT, 0);

	return 1;
}

void getSensorStatus(struct Machine * robus)
{
	robus->IRSensorStates = sensor_IRDetection();
	robus->MotorLeftEncoderLast = ENCODER_Read(ENCODER_LEFT);
	robus->MotorRightEncoderLast = ENCODER_Read(ENCODER_RIGHT);
	robus->MotorLeftEncoderTotal += robus->MotorLeftEncoderLast;
	robus->MotorRightEncoderTotal += robus->MotorRightEncoderLast;
}

