#include "Behaviors/Behaviors.h"

GameStates playMenu();

void play()
{
	bool presence = true;
	GameStates gameMode = Menu;

	while (presence)
	{
		switch(gameMode)
		{
			case Menu:
				gameMode = playMenu();
				break;
			case Sequence:
				sequence();
				gameMode = Menu;
				break;
			case Repeat:
				repeatSongSelection();
				gameMode = Menu;
				break;
			case Free:
				freePlay();
				gameMode = Menu;
				break;
			case ExitGames:
				presence = false;
				break;
			default:
				gameMode = Menu;
				break;
		}
	}
}

GameStates playMenu()
{
	AllLED(ETEINDRE);
	GameStates game = Menu;
	bool confirmed = false;
	bool internalConfirmed = false;
	float timerOut = 0;

	int streamID = -1;

	while(!confirmed)
	{

		LCD_ClearAndPrint("Choisis ton mode de jeu!\n");
		LCD_Printf("1- Appuie sur le bouton de gauche pour tester ta memoire,\n"); // bumper front
		LCD_Printf("2- appuie sur le bouton du centre pour apprendre une piece de piano,\n"); // bumper rear
		LCD_Printf("3- ou appuie sur le bouton de droite pour jouer librement du piano"); // bumper right

		if(streamID != -1)
			AUDIO_StopPlayback(streamID);

		streamID = AUDIO_PlayFile(VOIX_MENU);

		timerOut = SYSTEM_ReadTimerMSeconds();

		while (!internalConfirmed)
		{
			if(ButtonStatus(1) == 1)
			{
				game = Sequence;
				internalConfirmed = true;
			}
			if(ButtonStatus(2) == 1)
			{
				game = Repeat;
				internalConfirmed = true;
			}
			if(ButtonStatus(3) == 1)
			{
				game = Free;
				internalConfirmed = true;
			}


			if(SYSTEM_ReadTimerMSeconds() - timerOut >= 60000)
				return ExitGames;

			THREAD_MSleep(100);
		}
		THREAD_MSleep(500);
		internalConfirmed = false;
		timerOut = SYSTEM_ReadTimerMSeconds();

		if (game == Free)
		{
			AUDIO_StopPlayback(streamID);
			streamID = -1;
			LCD_ClearAndPrint("Voulais-tu vraiment le mode libre?\n");
			AUDIO_PlayFile(VOIX_CONFIRMATION_FREE);
			THREAD_MSleep(1500);
			streamID = AUDIO_PlayFile(VOIX_CONFIRMATION_OUI);
		}
		else if (game == Sequence)
		{
			AUDIO_StopPlayback(streamID);
			streamID = -1;
			LCD_ClearAndPrint("Voulais-tu vraiment le mode sequence?\n");
			AUDIO_PlayFile(VOIX_CONFIRMATION_SEQUENCE);
			THREAD_MSleep(1500);
			streamID = AUDIO_PlayFile(VOIX_CONFIRMATION_OUI);
		}
		else if (game == Repeat)
		{
			AUDIO_StopPlayback(streamID);
			streamID = -1;
			LCD_ClearAndPrint("Voulais-tu vraiment le mode jouer?");
			AUDIO_PlayFile(VOIX_CONFIRMATION_REPEAT);
			THREAD_MSleep(2000);
			streamID = AUDIO_PlayFile(VOIX_CONFIRMATION_OUI);
		}

		LCD_Printf("Appuie sur le bouton de gauche pour oui et le bouton du centre pour non\n");
		LCD_Printf("1- Oui\n");
		LCD_Printf("2- Non\n");

		while(!internalConfirmed)
		{
			if(ButtonStatus(1))
			{
				internalConfirmed = true;
				confirmed = true;
			}
			if(ButtonStatus(2))
			{
				internalConfirmed = true;
				confirmed = false;
			}

			if(SYSTEM_ReadTimerMSeconds() - timerOut >= 60000)
							return ExitGames;

			THREAD_MSleep(100);
		}
		internalConfirmed = false;
	}



	if(streamID != -1)
		AUDIO_StopPlayback(streamID);

	return game;
}




