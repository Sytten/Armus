#include "PlaySound/Notes.h"
#include "PlaySound/ControlNote.h"
#include "LED/LED.h"

unsigned int PlayNote(int notes)
{
	unsigned int returnValue = 0;

	switch(notes)
	{
		case VAL_DO1:
			returnValue = AUDIO_PlayFile(PATH_DO1);
			LedDo(ROUGE);
			break;
		case VAL_RE:
			returnValue = AUDIO_PlayFile(PATH_RE);
			LedRe(ROUGE);
			break;
		case VAL_MI:
			returnValue = AUDIO_PlayFile(PATH_MI);
			LedMi(ROUGE);
			break;
		case VAL_FA:
			returnValue = AUDIO_PlayFile(PATH_FA);
			LedFa(ROUGE);
			break;
		case VAL_SOL:
			returnValue = AUDIO_PlayFile(PATH_SOL);
			LedSol(ROUGE);
			break;
		case VAL_LA:
			returnValue = AUDIO_PlayFile(PATH_LA);
			LedLa(ROUGE);
			break;
		case VAL_SI:
			returnValue = AUDIO_PlayFile(PATH_SI);
			LedSi(ROUGE);
			break;
		case VAL_DO2:
			returnValue = AUDIO_PlayFile(PATH_DO2);
			LedDo2(ROUGE);
			break;
	}
	return returnValue;

}

void StopNote(unsigned int ID)
{
	AUDIO_StopPlayback(ID);
}
