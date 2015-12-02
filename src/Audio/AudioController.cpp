#include "Audio/AudioController.h"

void PlayAndStopNotes(PianoStream* stream)
{
	//Iterate through all notes using the piano stream size
	for(int i = stream->size - 1; i >= 0; i--)
	{
		//If the note is pressed
		if(stream->notes[i].keyPressed == true)
		{
			//If the note is pressed for the first time
			if(stream->notes[i].firstTime == true)
			{
				stream->notes[i].firstTime = false;

				//Stop the stream that is already on
				if(stream->streamID != -1)
				{
					THREAD_MSleep(100);
					StopNote(stream->streamID);
				}

				//Play the new stream and
				stream->streamID = PlayNote(stream->notes[i].note);
				stream->currentNote = i;
			}
			break;
		}
		else
		{
			//If the note is currently playing
			if(stream->currentNote == i && stream->streamID != -1)
			{
				//Stop it and set the stream ID to -1 to indicate no stream playing
				THREAD_MSleep(40);
				StopNote(stream->streamID);
				stream->streamID = -1;
				stream->currentNote = -1;
			}
		}
	}
}

void ResetStream(PianoStream * stream)
{
	for(int i = stream->size - 1; i >= 0; i--)
	{

		//Init everything to its starting value
		stream->notes[i].keyPressed = false;
		stream->notes[i].firstTime = true;

		if(stream->streamID != -1)
		{
			THREAD_MSleep(40);
			StopNote(stream->streamID);
			stream->streamID = -1;
			stream->currentNote = -1;
		}
	}
}
