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
#include "LED/LED.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <libarmus.h>

#define PATH_FLINSTONES "/media/usb0/ARMUS/flinstones.txt"
#define PATH_CLAIRE_FONTAINE "/media/usb0/ARMUS/clairefontaine.txt"
#define PATH_STAR_WARS "/media/usb0/ARMUS/starwars.txt"
#define PATH_HYMNE_A_LA_JOIE "/media/usb0/ARMUS/hymnealajoie.txt"

using namespace std;

#define PIANO_SIZE 8

bool freePlay();
bool sequence();
void repeatSongSelection();
void repeat(char * path);

//Directory path for repeat mode.
struct NoteSequenceData{
	char note;
	int delay;
};

//Structure representant le fichier de musique lu
//size est la taille en notes du morceau
//noteSequences est un tableau contenant toutes les sequences de notes
struct SongSequenceData{
	NoteSequenceData * noteSequences;
	int size;
};

SongSequenceData readSongFile(const char* file_name);

// songs to be played by kids.
void ClaireFontaine();
void HymneALaJoie();
void StarWars();

#endif /* GAMES_H_ */
