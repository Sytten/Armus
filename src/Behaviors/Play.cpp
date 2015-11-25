#include "Behaviors/Behaviors.h"
#include "Menu/Menu.h"

void play()
{
	int gameMode = menu();

	switch(gameMode)
	{
		case SEQUENCE:
			sequence();
			break;
		case REPEAT:
			repeat();
			break;
		case FREEPLAY:
		default:
			freePlay();
			break;

	}
	freePlay();
}




