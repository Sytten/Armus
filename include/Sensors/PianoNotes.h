#ifndef PIANONOTES_H_
#define PIANONOTES_H_


#include <libarmus.h>

/***
 * Fonction qui lit les valeurs des 2 canaux 4 bit des 74HC4052
 * char readValue = readMux(9, 10, 15, 16);
 * Un appel similaire a la version ci-haut retourne les 8 valeurs
 * En suivant les résistances autour du 74hc4052, en sens anti-horaire (Do1, Mi, Fa, Re, Do2, Sol, La, Si)
 * @param
 */
char readMux(int z2, int z1, int s1, int s0);

/***
 * Vérifie dans un char si la note a la position voulue est pressée
 * @param note Entier représentant la note a faire jouer
 * @param noteValues char 8bit représentant les 8 notes
 */
bool isNotePressed(int note, char noteValues);

#endif /* PIANONOTES_H_ */
