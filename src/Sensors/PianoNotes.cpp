/*
 * PianoNotes.cpp
 *
 *  Created on: 2015-11-05
 *      Author: Jeep
 */
#include "Sensors/PianoNotes.h"

char readMux(int z2, int z1, int s1, int s0)
{
	char returnValue = 0;

	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			DIGITALIO_Write(s1, i);
			DIGITALIO_Write(s0, j);

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


void setIsPressedStreams(PianoStreams * stream)
{
	char readValue = readMux(9, 10, 15, 16);

	for(int i = 0; i < 8; i++)
	{
		stream->streams[i].keyPressed = isNotePressed(i, readValue);
	}

}
