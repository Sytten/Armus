#include "Menu/Menu.h"

int menu()
{
	int jeux = -1;
	bool confirmed = false;
	bool internalConfirmed = false;
	float timerOut1 = 0;
	float timerOut2 = 0;
	float timerOut = 0;

	while(!confirmed)
	{

		LCD_ClearAndPrint("Bonjour, je propose 3 modes de jeux! Le premier est un mode de memorisation, le deuxieme permet d'apprendre la musique et le dernier est un mode libre\n");
		LCD_Printf("Clique sur le premier bouton pour tester ta memoire\n"); // bumper front
		LCD_Printf("Clique sur le deuxieme bouton pour apprendre une chanson au piano\n"); // bumper rear
		LCD_Printf("Clique sur le troisieme bouton pour jouer librement"); // bumper right

		timerOut1 = SYSTEM_ReadTimerMSeconds();

		while (!internalConfirmed)
		{
			if(DIGITALIO_Read(13))
			{
				jeux = SEQUENCE;
				internalConfirmed = true;
			}
			if(DIGITALIO_Read(12))
			{
				jeux = REPEAT;
				internalConfirmed = true;
			}
			if(DIGITALIO_Read(11))
			{
				jeux = FREEPLAY;
				internalConfirmed = true;
			}

			if(internalConfirmed == false)
			{

				if (readMux(9, 10, 15, 16) != 255)
				{
					timerOut1 = SYSTEM_ReadTimerMSeconds();
				}
				else
				{
					timerOut2 = SYSTEM_ReadTimerMSeconds();
					if(timerOut2 - timerOut1 == 60000)
						return OUT;
				}



			}

			THREAD_MSleep(100);
		}
		internalConfirmed = false;
		THREAD_MSleep(500);

		LCD_ClearAndPrint("Il reste seulement a confimer ton choix\n");

		if (jeux == 0)
			LCD_ClearAndPrint("Tu desire jouer en mode libre\n");

		else if (jeux == 1)
			LCD_ClearAndPrint("Tu desire pratiquer ta memoire\n");

		else if (jeux == 2)
			LCD_ClearAndPrint("Tu desire apprendre le piano\n");


		LCD_Printf("C'est ok?\n");
		LCD_Printf("Oui, premier bouton\n");
		LCD_Printf("Non, deuxieme bouton\n");

		while(!internalConfirmed)
		{
			if(DIGITALIO_Read(13)) {
				internalConfirmed = true;
				confirmed = true;
			}
			if(DIGITALIO_Read(12)) {
				internalConfirmed = true;
				confirmed = false;
			}
			THREAD_MSleep(100);
		}
		internalConfirmed = false;
		THREAD_MSleep(500);
	}

	return jeux;

}
