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
#include "Games/Games.h"
#include "Sensors/ReadMux.h"
#include "MotorsControl/motorsControl.h"

/**
 * State in which the robot wanders around, waiting a player
 */
void wander();

/**
 * State in which the robot turns to find the player who pressed his notes to indicate the will to play
 */
void towardPlayer();

/**
 * State in which the games are played
 */
void play();

/**
 * Game menu function, that returns a value to select the good game mode
 */
GameStates playMenu();

/**
 * State in which the robot is immobilized
 */
void stay();

#endif /* BEHAVIORS_H_ */
