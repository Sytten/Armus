#include "Audio/AudioController.h"

bool PlayAndStopNotes(PianoStream* stream)
{
	for(int i = 7; i >= 0; i--)
	{
		if(stream->notes[i].keyPressed == true)
		{
			if(stream->notes[i].firstTime == true)
			{
				stream->notes[i].firstTime = false;

				if(stream->streamID != -1)
				{
					THREAD_MSleep(40);
					StopNote(stream->streamID);
				}

				stream->streamID = PlayNote(stream->notes[i].note);
				stream->currentNote = i;
			}
			break;
		}
		else
		{
			if(stream->currentNote == i && stream->streamID != -1)
			{
				THREAD_MSleep(40);
				StopNote(stream->streamID);
				stream->streamID = -1;
				stream->currentNote = -1;
			}
		}
	}

	return true;
}

bool ResetStream(PianoStream * stream)
{
	for(int i = 7; i >= 0; i--)
	{
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

	return true;
}
