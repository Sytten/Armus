/*
============================================================================
 Name : main
 Authors : M.A.G.I.E Team
 Version : V0.4.3
 Modified on: 2015-10-15
 Description : The Armus project is the S1 project at Sherbrooke university.
			   The code is under the MIT license. Please refer to the license
			   file for more information.
============================================================================
*/

#include "StateMachine/StateMachine.h"

#define PARAMETER_PATH "/media/usb0/ARMUS/flinstones.txt"

int main()
{
	//return run();
	SongSequenceData song = readSongFile(PARAMETER_PATH);
	int streamID;
	for(int i = 0; i < song.size; i++)
	{
		for(int j = 7; j >= 0; j--)
		{
			if(isNotePressed(j, song.noteSequences[i].note))
			{
				streamID = PlayNote(j);
			}
		}
		THREAD_MSleep(song.noteSequences[i].delay);
		StopNote(streamID);
	}


	return 0;
}

