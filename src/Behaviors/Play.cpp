#include "Behaviors/Behaviors.h"
#include "Menu/Menu.h"

void play()
{
	int gameMode = menu();

	switch(gameMode)
	{
		case MEMORY:
			sequence();
			break;
		case LEARN:
			repeat();
			break;
		case FREEPLAY:
		default:
			freePlay();
			break;

	}
	freePlay();
}




