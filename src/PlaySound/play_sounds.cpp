#include "play_sound.h"

void play_sound(char playedNote[]) 	// note_appuyer est la logic de l'action.
{
	/*if(playedNote == "Do1")
	{
		while (notes_appuyer == 1)
			AUDIO_PlayFile(Do1);
	}

	else if(playedNote == "Re")
		{
			while (notes_appuyer == 1)
				AUDIO_PlayFile(Re);
		}

	else if(playedNote == "Mi")
		{
			while (notes_appuyer == 1)
				AUDIO_PlayFile(Mi);
		}


	else if(playedNote == "Fa")
			{
				while (notes_appuyer == 1)
					AUDIO_PlayFile(Fa);
			}

	else if(playedNote == "Sol")
				{
					while (notes_appuyer == 1)
						AUDIO_PlayFile(Sol);

				}
	else if(playedNote == "La")
				{
					while (notes_appuyer == 1)
						AUDIO_PlayFile(La);
				}

	else if(playedNote == "Si")
				{
					while (notes_appuyer == 1)
						AUDIO_PlayFile(Si);
				}

	else if(playedNote == "Do2")
				{
					while (notes_appuyer == 1)
						AUDIO_PlayFile(Do2);
				}*/
}

int PlayNotes(/*Manque une struct*/)
{
	int returnedValue = 0;

	//Boucle de démarrage des sons
	for(int i = 7; i >= 0; i--)
	{
		//Démarrage du son et assignation du nouveau stream
		//Modification des bool
	}

	return returnedValue;
}

int StopNotes(/*Manque une struct*/)
{
	int returnedValue = 0;

	//Boucle de démarrage des sons
	for(int i = 7; i >= 0; i--)
	{
		//Fermeture des sons et modification du bool
	}

	return returnedValue;
}
