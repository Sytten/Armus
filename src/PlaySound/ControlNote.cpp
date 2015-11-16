#include "Notes.h"
#include "ControlNote.h"

unsigned int PlayNote(int notes)
{
	unsigned int returnValue = 0;

	switch(notes)
	{
		case VAL_DO1:
			returnValue = AUDIO_PlayFile(DO1);
			break;
		case VAL_DO1:
			returnValue = AUDIO_PlayFile(RE);
			break;
		case VAL_DO1:
			returnValue = AUDIO_PlayFile(MI);
			break;
		case VAL_DO1:
			returnValue = AUDIO_PlayFile(FA);
			break;
		case VAL_DO1:
			returnValue = AUDIO_PlayFile(SOL);
			break;
		case VAL_DO1:
			returnValue = AUDIO_PlayFile(LA);
			break;
		case VAL_DO1:
			returnValue = AUDIO_PlayFile(SI);
			break;
		case VAL_DO1:
			returnValue = AUDIO_PlayFile(DO2);
			break;
	}
	return returnValue;

}

unsigned int StopNote(unsigned int ID)
{
	AUDIO_StopPlayback(ID);
}
