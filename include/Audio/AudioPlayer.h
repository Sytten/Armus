/*
============================================================================
 Name : AudioPlayer
 Author : M.A.G.I.E Team
 Modified on: 2015-11-29
 Description : Wrapper on the libarmus API calls
============================================================================
*/

#ifndef AUDIOPLAYER_H_
#define AUDIOPLAYER_H_

#include <libarmus.h>

#include "Audio/Notes.h"

unsigned int PlayNote(int notes);
void StopNote(unsigned int ID);

#endif /*CHOOSINGNTOES_H_*/
