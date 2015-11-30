/*
============================================================================
 Name : Armus.cpp
 Author :
 Version :
 Description : Hello world - Exe source file
============================================================================
*/

// Include Files

#include <libarmus.h>
#include "LED/LED.h"

// Global Functions

int rouge = 0;
int vert = 0;


void output2(void){
	int x = 0;

	DIGITALIO_Write(COMO,1);

	x =  rouge %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  vert %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>1) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>1) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>2) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>2) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>3) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>3) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);


	x =  (rouge>>4) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>4) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>5) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>5) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>6) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>6) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>7) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>7) %2;
	DIGITALIO_Write(DATO,x);
	DIGITALIO_Write(CLKO,1);
	DIGITALIO_Write(CLKO,0);

	DIGITALIO_Write(COMO,0);
}

/*******************************************************************************/

char readLEDStatus(int LED)
{
	if(LED > 7 || LED < 0)
		return -1;

	int x = (rouge>>LED) %2;
	int y = (vert>>LED) %2;

	if(x == 1 && y == 1)
		return JAUNE;

	else if(x == 1 && y == 0)
		return ROUGE;

	else if(x == 0 && y == 1)
		return VERT;

	else if(x == 0 && y == 0)
		return ETEINDRE;
	else
		return -1;
}

char readLEDStatusInBuffer(int LED, int bufferVert, int bufferRouge)
{
	if(LED > 7 || LED < 0)
		return -1;

	int x = (bufferRouge>>LED) %2;
	int y = (bufferVert>>LED) %2;

	if(x == 1 && y == 1)
		return JAUNE;

	else if(x == 1 && y == 0)
		return ROUGE;

	else if(x == 0 && y == 1)
		return VERT;

	else if(x == 0 && y == 0)
		return ETEINDRE;
	else
		return -1;
}

/*******************************************************************************/

void p_ledDo(char couleur){
	if (couleur == VERT){
		if ((rouge%2)== 1){
			rouge = rouge - 1;
		}
		if ((vert%2)== 0){
			vert = vert + 1;
		}
	}

	if (couleur == JAUNE){
		if ((rouge%2)==0){
			rouge = rouge + 1;
		}
		if ((vert%2)==0){
			vert = vert + 1;
		}
	}

	if (couleur == ROUGE){
		if ((rouge%2)== 0){
			rouge = rouge + 1;
		}
		if ((vert%2)==1){
			vert = vert - 1;
		}
	}

	if (couleur == ETEINDRE){
		if ((rouge%2)== 1){
			rouge = rouge - 1;
		}
		if ((vert%2)== 1){
			vert = vert - 1;
		}
	}
}

void p_ledRe(char couleur){
	if (couleur == VERT){
		if (((rouge>>1)%2)== 1){
			rouge = rouge - 2;
		}
		if (((vert>>1)%2)== 0){
			vert = vert + 2;
		}
	}

	if (couleur == JAUNE){
		if (((rouge>>1)%2)==0){
			rouge = rouge + 2;
		}
		if (((vert>>1)%2)==0){
			vert = vert + 2;
		}
	}

	if (couleur == ROUGE){
		if (((rouge>>1)%2)== 0){
			rouge = rouge + 2;
		}
		if (((vert>>1)%2)==1){
			vert = vert - 2;
		}
	}
	if (couleur == ETEINDRE){
		if (((rouge>>1)%2)== 1){
			rouge = rouge - 2;
		}
		if (((vert>>1)%2)== 1){
			vert = vert - 2;
		}
	}
}

void p_ledMi(char couleur){
	if (couleur == VERT){
		if (((rouge>>2)%2)== 1){
			rouge = rouge - 4;
		}
		if (((vert>>2)%2)== 0){
			vert = vert + 4;
		}
	}

	if (couleur == JAUNE){
		if (((rouge>>2)%2)==0){
			rouge = rouge + 4;
		}
		if (((vert>>2)%2)==0){
			vert = vert + 4;
		}
	}

	if (couleur == ROUGE){
		if (((rouge>>2)%2)== 0){
			rouge = rouge + 4;
		}
		if (((vert>>2)%2)==1){
			vert = vert - 4;
		}
	}
	if (couleur == ETEINDRE){
		if (((rouge>>2)%2)== 1){
			rouge = rouge - 4;
		}
		if (((vert>>2)%2)== 1){
			vert = vert - 4;
		}
	}
}

void p_ledFa(char couleur){
	if (couleur == VERT){
		if (((rouge>>3)%2)== 1){
			rouge = rouge - 8;
		}
		if (((vert>>3)%2)== 0){
			vert = vert + 8;
		}
	}

	if (couleur == JAUNE){
		if (((rouge>>3)%2)==0){
			rouge = rouge + 8;
		}
		if (((vert>>3)%2)==0){
			vert = vert + 8;
		}
	}

	if (couleur == ROUGE){
		if (((rouge>>3)%2)== 0){
			rouge = rouge + 8;
		}
		if (((vert>>3)%2)==1){
			vert = vert - 8;
		}
	}
	if (couleur == ETEINDRE){
		if (((rouge>>3)%2)== 1){
			rouge = rouge - 8;
		}
		if (((vert>>3)%2)== 1){
			vert = vert - 8;
		}
	}
}

void p_ledSol(char couleur){
	if (couleur == VERT){
		if (((rouge>>4)%2)== 1){
			rouge = rouge - 16;
		}
		if (((vert>>4)%2)== 0){
			vert = vert + 16;
		}
	}

	if (couleur == JAUNE){
		if (((rouge>>4)%2)==0){
			rouge = rouge + 16;
		}
		if (((vert>>4)%2)==0){
			vert = vert + 16;
		}
	}

	if (couleur == ROUGE){
		if (((rouge>>4)%2)== 0){
			rouge = rouge + 16;
		}
		if (((vert>>4)%2)==1){
			vert = vert - 16;
		}
	}
	if (couleur == ETEINDRE){
		if (((rouge>>4)%2)== 1){
			rouge = rouge - 16;
		}
		if (((vert>>4)%2)== 1){
			vert = vert - 16;
		}
	}
}

void p_ledLa(char couleur){
	if (couleur == VERT){
		if (((rouge>>5)%2)== 1){
			rouge = rouge - 32;
		}
		if (((vert>>5)%2)== 0){
			vert = vert + 32;
		}
	}

	if (couleur == JAUNE){
		if (((rouge>>5)%2)==0){
			rouge = rouge + 32;
		}
		if (((vert>>5)%2)==0){
			vert = vert + 32;
		}
	}

	if (couleur == ROUGE){
		if (((rouge>>5)%2)== 0){
			rouge = rouge + 32;
		}
		if (((vert>>5)%2)==1){
			vert = vert - 32;
		}
	}
	if (couleur == ETEINDRE){
		if (((rouge>>5)%2)== 1){
			rouge = rouge - 32;
		}
		if (((vert>>5)%2)== 1){
			vert = vert - 32;
		}
	}
}

void p_ledSi(char couleur){
	if (couleur == VERT){
		if (((rouge>>6)%2)== 1){
			rouge = rouge - 64;
		}
		if (((vert>>6)%2)== 0){
			vert = vert + 64;
		}
	}

	if (couleur == JAUNE){
		if (((rouge>>6)%2)==0){
			rouge = rouge + 64;
		}
		if (((vert>>6)%2)==0){
			vert = vert + 64;
		}
	}

	if (couleur == ROUGE){
		if (((rouge>>6)%2)== 0){
			rouge = rouge + 64;
		}
		if (((vert>>6)%2)==1){
			vert = vert - 64;
		}
	}
	if (couleur == ETEINDRE){
		if (((rouge>>6)%2)== 1){
			rouge = rouge - 64;
		}
		if (((vert>>6)%2)== 1){
			vert = vert - 64;
		}
	}
}

void p_ledDo2(char couleur){
	if (couleur == VERT){
		if (((rouge>>7)%2)== 1){
			rouge = rouge - 128;
		}
		if (((vert>>7)%2)== 0){
			vert = vert + 128;
		}
	}

	if (couleur == JAUNE){
		if (((rouge>>7)%2)==0){
			rouge = rouge + 128;
		}
		if (((vert>>7)%2)==0){
			vert = vert + 128;
		}
	}

	if (couleur == ROUGE){
		if (((rouge>>7)%2)== 0){
			rouge = rouge + 128;
		}
		if (((vert>>7)%2)==1){
			vert = vert - 128;
		}
	}
	if (couleur == ETEINDRE){
		if (((rouge>>7)%2)== 1){
			rouge = rouge - 128;
		}
		if (((vert>>7)%2)== 1){
			vert = vert - 128;
		}
	}
}

void p_allLED(char couleur)
{
	p_ledDo(couleur);
	p_ledRe(couleur);
	p_ledMi(couleur);
	p_ledFa(couleur);
	p_ledSol(couleur);
	p_ledLa(couleur);
	p_ledSi(couleur);
	p_ledDo2(couleur);
}

/*******************************************************************************/

void LedDo(char couleur)
{
	p_ledDo(couleur);
	output2();
}

void LedRe(char couleur)
{
	p_ledRe(couleur);
	output2();
}

void LedMi(char couleur)
{
	p_ledMi(couleur);
	output2();
}

void LedFa(char couleur)
{
	p_ledFa(couleur);
	output2();
}

void LedSol(char couleur)
{
	p_ledSol(couleur);
	output2();
}

void LedLa(char couleur)
{
	p_ledLa(couleur);
	output2();
}

void LedSi(char couleur)
{
	p_ledSi(couleur);
	output2();
}

void LedDo2(char couleur)
{
	p_ledDo2(couleur);
	output2();
}

void AllLED(char couleur)
{
	p_allLED(couleur);

	output2();
}

/*******************************************************************************/

void OpenLEDForNotes(char noteSequence)
{
	int previousRouge = rouge;
	int previousVert = vert;
	p_allLED(ETEINDRE);
	for(int j = 7; j >= 0; j--)
	{
		if(isNotePressed(j, noteSequence))
		{
			switch(j)
			{
				case VAL_DO1:
					if(readLEDStatusInBuffer(VAL_DO1, previousVert, previousRouge) == VERT)
					{
						LedDo(JAUNE);
						break;
					}
					LedDo(VERT);
					break;
				case VAL_RE:
					if(readLEDStatusInBuffer(VAL_RE, previousVert, previousRouge) == VERT)
					{
						LedRe(JAUNE);
						break;
					}
					LedRe(VERT);
					break;
				case VAL_MI:
					if(readLEDStatusInBuffer(VAL_MI, previousVert, previousRouge) == VERT)
					{
						LedMi(JAUNE);
						break;
					}
					LedMi(VERT);
					break;
				case VAL_FA:
					if(readLEDStatusInBuffer(VAL_FA, previousVert, previousRouge) == VERT)
					{
						LedFa(JAUNE);
						break;
					}
					LedFa(VERT);
					break;
				case VAL_SOL:
					if(readLEDStatusInBuffer(VAL_SOL, previousVert, previousRouge) == VERT)
					{
						LedSol(JAUNE);
						break;
					}
					LedSol(VERT);
					break;
				case VAL_LA:
					if(readLEDStatusInBuffer(VAL_LA, previousVert, previousRouge) == VERT)
					{
						LedLa(JAUNE);
						break;
					}
					LedLa(VERT);
					break;
				case VAL_SI:
					if(readLEDStatusInBuffer(VAL_SI, previousVert, previousRouge) == VERT)
					{
						LedSi(JAUNE);
						break;
					}
					LedSi(VERT);
					break;
				case VAL_DO2:
					if(readLEDStatusInBuffer(VAL_DO2, previousVert, previousRouge) == VERT)
					{
						LedDo2(JAUNE);
						break;
					}
					LedDo2(VERT);
					break;
				default:
					AllLED(ROUGE);
					break;
			}
		}
	}
}



