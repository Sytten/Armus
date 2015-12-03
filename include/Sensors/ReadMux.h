/*
============================================================================
 Name : Read Mux
 Author : M.A.G.I.E Team
 Modified on: 2015-10-14
 Description : These function give access to the piano notes
============================================================================
*/


#ifndef READMUX_H_
#define READMUX_H_


#include <libarmus.h>
#include "Audio/AudioController.h"

/**
 * Function that reads all the notes on the multiplexor
 * char readValue = readMux(9, 10, 15, 16);
 * This is the default call for our version of the board
 * @param z2, z1 input pins for data reading
 * @param s1, s0 output pins to control mux address
 * @return The char representing all notes on the keyboard
 */
char readMux(int z2, int z1, int s1, int s0);

/**
 * Goes through a piano notes char value and confirms if the selected note is pressed
 * @param note The note to check if pressed
 * @param noteValues Piano note values
 */
bool isNotePressed(int note, char noteValues);

/**
 * Combines readMux and a PianoStream to automatically set all data
 * @param stream Of all the piano peripherals
 */
void CheckPressedKeys(PianoStream * stream);

/**
 * Takes a piano stream and returns a char
 * @param stream The stream to extract the char value
 * @return The piano notes char representation
 */
char StreamToValue(PianoStream * stream);

#endif /* READMUX_H_ */
