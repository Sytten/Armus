

#define como 9
#define clko 10
#define dato 11

int rouge = 0;
int vert = 0;

void output2(void); // communication avec le PIC (16F1789)


// Controle les LEDS (caractere a envoyer : r -> rouge, j-> jaune, v -> vert n -> éteindre)
void LedDo(char);
void LedRe(char);
void LedMi(char);
void LedFa(char);
void LedSol(char);
void LedLa(char);
void LedSi(char);
void LedDo2(char);
