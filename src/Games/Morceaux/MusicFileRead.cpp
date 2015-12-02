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

	//Read the number of notes
	getline(read, s);
	song.size = atoi(s.c_str());

	song.noteSequences = new NoteSequenceData[song.size];

	for(int i = 0; i < song.size; i++)
	{
		//Read the note value
		getline(read, s);
		song.noteSequences[i].note = atoi(s.c_str());
		//Read the delay value
		getline(read, s);
		song.noteSequences[i].delay = atoi(s.c_str());
	}
	return song;
}




