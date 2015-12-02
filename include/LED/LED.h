/*
============================================================================
 Name : LED
 Author : M.A.G.I.E Team
 Modified on: 2015-11-29
 Description : Simple API to control the LED on the keyboard
============================================================================
*/

#ifndef LED_H_
#define LED_H_

#include "Audio/Notes.h"
#include "Sensors/ReadMux.h"

//Pins repr�sentant les bus de communication avec le PIC16
#define COMO 9
#define CLKO 10
#define DATO 11

//Constants that define the colors to put on the DEL
#define ROUGE 'r'
#define JAUNE 'j'
#define VERT 'v'
#define ETEINDRE 'n'

void output2(void); // communication avec le PIC (16F1789)

// Function that control the output on the LEDs
void LedDo(char);
void LedRe(char);
void LedMi(char);
void LedFa(char);
void LedSol(char);
void LedLa(char);
void LedSi(char);
void LedDo2(char);

/**
 * Function that opens the LEDs in the note sequence
 */
void OpenLEDForNotes(char noteSequence);

/**
 * Function to control all LED
 */
void AllLED(char couleur);

/**
 * Function that sets all LED to char couleur but does not communicate
 */
void p_allLED(char couleur);

#endif
