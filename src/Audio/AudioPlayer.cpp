#include "Audio/AudioPlayer.h"

unsigned int PlayNote(int notes)
{
	unsigned int returnValue = 0;

	switch(notes)
	{
		case VAL_DO1:
			returnValue = AUDIO_PlayFile(PATH_DO1);
			break;
		case VAL_RE:
			returnValue = AUDIO_PlayFile(PATH_RE);
			break;
		case VAL_MI:
			returnValue = AUDIO_PlayFile(PATH_MI);
			break;
		case VAL_FA:
			returnValue = AUDIO_PlayFile(PATH_FA);
			break;
		case VAL_SOL:
			returnValue = AUDIO_PlayFile(PATH_SOL);
			break;
		case VAL_LA:
			returnValue = AUDIO_PlayFile(PATH_LA);
			break;
		case VAL_SI:
			returnValue = AUDIO_PlayFile(PATH_SI);
			break;
		case VAL_DO2:
			returnValue = AUDIO_PlayFile(PATH_DO2);
			break;
	}
	return returnValue;

}

void StopNote(unsigned int ID)
{
	AUDIO_StopPlayback(ID);
}
