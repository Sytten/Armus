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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <string>
#include <libarmus.h>

#include "StateMachine/GameStates.h"
#include "Audio/AudioController.h"
#include "Sensors/ReadMux.h"
#include "Sensors/Buttons.h"
#include "LED/LED.h"

//Song file paths
#define PATH_FLINSTONES "/media/usb0/ARMUS/flinstones.txt"
#define PATH_CLAIRE_FONTAINE "/media/usb0/ARMUS/clairefontaine.txt"
#define PATH_STAR_WARS "/media/usb0/ARMUS/starwars.txt"
#define PATH_HYMNE_A_LA_JOIE "/media/usb0/ARMUS/hymnealajoie.txt"

//Voice of Free begining.
#define VOIX_FREE "Freeplay.wav"
#define VOIX_REPEAT "Repeat.wav"
#define VOIX_SEQUENCE "Sequence.wav"
#define VOIX_MENU "MenuAntoine.wav"
#define VOIX_CONFIRMATION_FREE "Confirmefree.wav"
#define VOIX_CONFIRMATION_SEQUENCE "Confirmesequence.wav"
#define VOIX_CONFIRMATION_REPEAT "Confirmejouer.wav"
#define VOIX_CONFIRMATION_OUI "Confirme_oui_non.wav"
#define VOIX_WANDER "Wandervoice.wav"

//images
#define CHAPEAU "/media/usb0/ARMUS/chapeau.bmp"


using namespace std;

#define PIANO_SIZE 8

/**
 * Freeplay game mode
 */
bool freePlay();

/**
 * Sequence repeating game mode
 */
bool sequence();

/**
 * Repeat mode song selection
 */
void repeatSongSelection();

/**
 * Repeat game mode
 */
void repeat(char * path);

/**
 * Structure that holds a note sequence and a time delay for the note
 */
struct NoteSequenceData{
	char note;
	int delay;
};

/**
 * Structure that hold a array of note sequences and a size
 */
struct SongSequenceData{
	NoteSequenceData * noteSequences;
	int size;
};

/**
 * Function that read a song file
 * @param file_name Name of the file to read. Absolute path is necessary
 */
SongSequenceData readSongFile(const char* file_name);

////DEPRECATED FONCTIONS
void ClaireFontaine();
void HymneALaJoie();
void StarWars();

#endif /* GAMES_H_ */
