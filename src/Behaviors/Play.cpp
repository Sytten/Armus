#include "Behaviors/Behaviors.h"
#include "Menu/Menu.h"

void play()
{
	bool presence = true;

	while (presence)

	{
		int gameMode = menu();

		switch(gameMode)
		{
			case SEQUENCE:
				sequence();
				break;
			case REPEAT:
				repeatSongSelection();
				break;
			case FREEPLAY:
			default:
				freePlay();
				break;
			case OUT:
				presence = false;
				break;
		}
	}
}




