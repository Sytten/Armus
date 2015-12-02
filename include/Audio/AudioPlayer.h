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

/**
 * Using the sent parameter, plays the good audio file
 * @param notes Value that will select the good audio file, recommended to be used with Audio/Notes.h defines
 * @return The audio playfile system stream ID
 */
unsigned int PlayNote(int notes);

/**
 *	Stops the stream at the parameters ID
 *	@param ID Stream ID to stop
 */
void StopNote(unsigned int ID);

#endif /*CHOOSINGNTOES_H_*/
