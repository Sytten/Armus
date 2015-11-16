/*
============================================================================
 Name : Behaviors
 Author : M.A.G.I.E Team
 Modified on: 2015-11-05
 Description : Access the different general behaviors of the robots
============================================================================
*/
#ifndef BEHAVIORS_H_
#define BEHAVIORS_H_

#include "StateMachine/GameStates.h"
#include "Sensors/PianoNotes.h"
#include "MotorsControl/motorsControl.h"

void wander();
void towardPlayer();
void play();
void stay();

#endif /* BEHAVIORS_H_ */
