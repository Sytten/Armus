/*
============================================================================
 Name : Games
 Author : M.A.G.I.E Team
 Modified on: 2015-11-05
 Description : Access the different games that can be played on the robots
============================================================================
*/

#ifndef GAMES_H_
#define GAMES_H_

#include "PlaySound/PianoStreams.h"
#include "PlaySound/PlaySounds.h"
#include "Sensors/PianoNotes.h"
#include "PlaySound/Notes.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <libarmus.h>

using namespace std;

#define PIANO_SIZE 8

bool freePlay();
void memory();
void repeat();

//Directory path for repeat mode.
struct NoteSequenceData{
	char note;
	int delay;
};

struct SongSequenceData{
	NoteSequenceData * noteSequences;
	int size;
};

SongSequenceData readSongFile(const char* file_name);

// songs to be played by kids.
void claireFontaine();
void HymeDeLaJoie();
void starwars();

#endif /* GAMES_H_ */
