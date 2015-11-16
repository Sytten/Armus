#include <libarmus.h>

// Sound directory defining.

//only for testing
#define Do1 "son.wav"


//#define Do1 "do_16b.wav"  remove comment sign after testing is completed.
#define Re "re_16b.wav"
#define Mi "mi_16b.wav"
#define Fa "fa_16b.wav"
#define Sol "sol_16b.wav"
#define La "la_16b.wav"
#define Si "si_16b.wav"
#define Do2 "do2_16b.wav"

// values of notes.
#define VAL_DO1 0
#define VAL_RE 	1
#define VAL_MI	2
#define VAL_FA 	3
#define VAL_SOL 4
#define VAL_LA	5
#define VAL_SI	6
#define VAL_DO2 7

// Definition of if file is played or not
#define played 0
#define unplayed -1

// Max Values.
#define MAX_CHARACTER 5


// définition des fonctions
void play_sound(int playedNote);
