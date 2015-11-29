#ifndef MENU_H_
#define MENU_H_

#define FREEPLAY 0
#define SEQUENCE 1
#define REPEAT 2
#define OUT -1

#define VOIX_MENU "/media/usb0/ARMUS/MenuAntoine.WAV"

//EasterEgg voice
#define EASTER_EGG "/media/usb0/ARMUS/Easteregg.WAV"

#include <libarmus.h>
#include "Sensors/ReadMux.h"

int menu();

#endif /* MENU_H_ */
