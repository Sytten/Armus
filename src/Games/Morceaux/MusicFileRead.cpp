/*
 * MusicFileRead.cpp
 *
 *  Created on: 2015-11-19
 *      Author: Jeep
 */
#include "Games/Games.h"


SongSequenceData readSongFile(const char* file_name)
{
	SongSequenceData song;
	ifstream read(file_name);
	string s;
	getline(read, s);
	//LCD_Printf("Taille lue : ");
	//LCD_Printf(s.c_str());
	//LCD_Printf("\n");
	song.size = atoi(s.c_str());
	//LCD_Printf("Taille conv: %d\n", song.size);
	song.noteSequences = new NoteSequenceData[song.size];
	//NoteSequenceData * sequence[song->size];
	//LCD_Printf ("Taille : %d ", song->size);

	for(int i = 0; i < song.size; i++)
	{
		getline(read, s);
		song.noteSequences[i].note = atoi(s.c_str());
		getline(read, s);
		song.noteSequences[i].delay = atoi(s.c_str());

		//LCD_Printf ("Note : %d, Temps : %d ", song.noteSequences[i].note, song.noteSequences[i].delay);
	}
	return song;
}




