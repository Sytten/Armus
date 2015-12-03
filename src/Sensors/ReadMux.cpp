/*
 * PianoNotes.cpp
 *
 *  Created on: 2015-11-05
 *      Author: Jeep
 */
#include "Sensors/ReadMux.h"

char readMux(int z2, int z1, int s1, int s0)
{
	char returnValue = 0;

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			DIGITALIO_Write(s1, i);
			DIGITALIO_Write(s0, j);

			//Use the I and J values to bit shift into the char 8-bit representation of the piano notes
			//Using I and J, the notes are placed appropriately
			returnValue |= (DIGITALIO_Read(z2) << 7 - ((2 * i) + j));
			returnValue |= (DIGITALIO_Read(z1) << 3 - ((2 * i) + j));
		}
	}
	return returnValue;
}

bool isNotePressed(int note, char noteValues)
{
	bool returnedValue = false;
	noteValues = (noteValues >> (7 - note)) & 0x01;

	if(!noteValues)
	{
		returnedValue = true;
	}

	return returnedValue;
}

void CheckPressedKeys(PianoStream * stream)
{
	char readValue = readMux(9, 10, 15, 16);

	for(int i = 0; i < 8; i++)
	{

		if (stream->notes[i].keyPressed == false && isNotePressed(i,readValue) == true)
			stream->notes[i].firstTime = true;

		stream->notes[i].keyPressed = isNotePressed(i, readValue);
	}

}

char StreamToValue(PianoStream * stream)
{
	char returnedValue = 0;

	for(int i = 0; i < 8; i++)
	{
		if(!stream->notes[i].keyPressed || (stream->notes[i].keyPressed && !stream->notes[i].firstTime))
		{
			returnedValue |= 1 << 7 - i;
		}
	}
	return returnedValue;
}
