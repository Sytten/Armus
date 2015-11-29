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

	while(!confirmed)
	{

		LCD_ClearAndPrint("Choisis ton mode de jeu!\n");
		LCD_Printf("1- Teste ta memoire\n"); // bumper front
		LCD_Printf("2- Apprends une chanson\n"); // bumper rear
		LCD_Printf("3- Joue librement"); // bumper right

		AUDIO_PlayFile(VOIX_MENU);

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


			if(SYSTEM_ReadTimerMSeconds() - timerOut == 60000)
				return ExitGames;

			THREAD_MSleep(100);
		}

		internalConfirmed = false;
		timerOut = SYSTEM_ReadTimerMSeconds();

		LCD_ClearAndPrint("Il reste seulement a confimer ton choix\n");
		if (game == Free)
			LCD_ClearAndPrint("Tu desire jouer en mode libre\n");
		else if (game == Sequence)
			LCD_ClearAndPrint("Tu desire pratiquer ta memoire\n");
		else if (game == Repeat)
			LCD_ClearAndPrint("Tu desire apprendre une chansonn");

		LCD_Printf("C'est ok?\n");
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

			if(SYSTEM_ReadTimerMSeconds() - timerOut == 60000)
				return ExitGames;

			THREAD_MSleep(100);
		}
		internalConfirmed = false;
	}

	return game;
}




