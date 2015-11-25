#include "Games/Games.h"

void repeat()
{
	srand(time(NULL));
	int songSelect = rand()%3 + 1;

	switch (songSelect) {
		case 1:
			ClaireFontaine();
			break;
		case 2:
			HymneALaJoie();
			break;
		case 3:
			StarWars();
			break;
		default:
			break;
	}
}




