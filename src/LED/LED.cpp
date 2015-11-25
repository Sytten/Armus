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
	THREAD_MSleep(3);

	x =  rouge %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  vert %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>1) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>1) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>2) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>2) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>3) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>3) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);


	x =  (rouge>>4) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>4) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>5) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>5) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>6) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>6) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (rouge>>7) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	x =  (vert>>7) %2;
	DIGITALIO_Write(DATO,x);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,1);
	THREAD_MSleep(3);
	DIGITALIO_Write(CLKO,0);

	DIGITALIO_Write(COMO,0);
}

void LedDo(char couleur){
	if (couleur == 'v'){
		if ((rouge%2)== 1){
			rouge = rouge - 1;
		}
		if ((vert%2)== 0){
			vert = vert + 1;
		}
	}

	if (couleur == 'j'){
		if ((rouge%2)==0){
			rouge = rouge + 1;
		}
		if ((vert%2)==0){
			vert = vert + 1;
		}
	}

	if (couleur == 'r'){
		if ((rouge%2)== 0){
			rouge = rouge + 1;
		}
		if ((vert%2)==1){
			vert = vert - 1;
		}
	}

	if (couleur == 'n'){
		if ((rouge%2)== 1){
			rouge = rouge - 1;
		}
		if ((vert%2)== 1){
			vert = vert - 1;
		}
	}
	output2();
}

void LedRe(char couleur){
	if (couleur == 'v'){
		if (((rouge>>1)%2)== 1){
			rouge = rouge - 2;
		}
		if (((vert>>1)%2)== 0){
			vert = vert + 2;
		}
	}

	if (couleur == 'j'){
		if (((rouge>>1)%2)==0){
			rouge = rouge + 2;
		}
		if (((vert>>1)%2)==0){
			vert = vert + 2;
		}
	}

	if (couleur == 'r'){
		if (((rouge>>1)%2)== 0){
			rouge = rouge + 2;
		}
		if (((vert>>1)%2)==1){
			vert = vert - 2;
		}
	}
	if (couleur == 'n'){
		if (((rouge>>1)%2)== 1){
			rouge = rouge - 2;
		}
		if (((vert>>1)%2)== 1){
			vert = vert - 2;
		}
	}
	output2();
}

void LedMi(char couleur){
	if (couleur == 'v'){
		if (((rouge>>2)%2)== 1){
			rouge = rouge - 4;
		}
		if (((vert>>2)%2)== 0){
			vert = vert + 4;
		}
	}

	if (couleur == 'j'){
		if (((rouge>>2)%2)==0){
			rouge = rouge + 4;
		}
		if (((vert>>2)%2)==0){
			vert = vert + 4;
		}
	}

	if (couleur == 'r'){
		if (((rouge>>2)%2)== 0){
			rouge = rouge + 4;
		}
		if (((vert>>2)%2)==1){
			vert = vert - 4;
		}
	}
	if (couleur == 'n'){
		if (((rouge>>2)%2)== 1){
			rouge = rouge - 4;
		}
		if (((vert>>2)%2)== 1){
			vert = vert - 4;
		}
	}
	output2();
}

void LedFa(char couleur){
	if (couleur == 'v'){
		if (((rouge>>3)%2)== 1){
			rouge = rouge - 8;
		}
		if (((vert>>3)%2)== 0){
			vert = vert + 8;
		}
	}

	if (couleur == 'j'){
		if (((rouge>>3)%2)==0){
			rouge = rouge + 8;
		}
		if (((vert>>3)%2)==0){
			vert = vert + 8;
		}
	}

	if (couleur == 'r'){
		if (((rouge>>3)%2)== 0){
			rouge = rouge + 8;
		}
		if (((vert>>3)%2)==1){
			vert = vert - 8;
		}
	}
	if (couleur == 'n'){
		if (((rouge>>3)%2)== 1){
			rouge = rouge - 8;
		}
		if (((vert>>3)%2)== 1){
			vert = vert - 8;
		}
	}
	output2();
}

void LedSol(char couleur){
	if (couleur == 'v'){
		if (((rouge>>4)%2)== 1){
			rouge = rouge - 16;
		}
		if (((vert>>4)%2)== 0){
			vert = vert + 16;
		}
	}

	if (couleur == 'j'){
		if (((rouge>>4)%2)==0){
			rouge = rouge + 16;
		}
		if (((vert>>4)%2)==0){
			vert = vert + 16;
		}
	}

	if (couleur == 'r'){
		if (((rouge>>4)%2)== 0){
			rouge = rouge + 16;
		}
		if (((vert>>4)%2)==1){
			vert = vert - 16;
		}
	}
	if (couleur == 'n'){
		if (((rouge>>4)%2)== 1){
			rouge = rouge - 16;
		}
		if (((vert>>4)%2)== 1){
			vert = vert - 16;
		}
	}
	output2();
}

void LedLa(char couleur){
	if (couleur == 'v'){
		if (((rouge>>5)%2)== 1){
			rouge = rouge - 32;
		}
		if (((vert>>5)%2)== 0){
			vert = vert + 32;
		}
	}

	if (couleur == 'j'){
		if (((rouge>>5)%2)==0){
			rouge = rouge + 32;
		}
		if (((vert>>5)%2)==0){
			vert = vert + 32;
		}
	}

	if (couleur == 'r'){
		if (((rouge>>5)%2)== 0){
			rouge = rouge + 32;
		}
		if (((vert>>5)%2)==1){
			vert = vert - 32;
		}
	}
	if (couleur == 'n'){
		if (((rouge>>5)%2)== 1){
			rouge = rouge - 32;
		}
		if (((vert>>5)%2)== 1){
			vert = vert - 32;
		}
	}
	output2();
}

void LedSi(char couleur){
	if (couleur == 'v'){
		if (((rouge>>6)%2)== 1){
			rouge = rouge - 64;
		}
		if (((vert>>6)%2)== 0){
			vert = vert + 64;
		}
	}

	if (couleur == 'j'){
		if (((rouge>>6)%2)==0){
			rouge = rouge + 64;
		}
		if (((vert>>6)%2)==0){
			vert = vert + 64;
		}
	}

	if (couleur == 'r'){
		if (((rouge>>6)%2)== 0){
			rouge = rouge + 64;
		}
		if (((vert>>6)%2)==1){
			vert = vert - 64;
		}
	}
	if (couleur == 'n'){
		if (((rouge>>6)%2)== 1){
			rouge = rouge - 64;
		}
		if (((vert>>6)%2)== 1){
			vert = vert - 64;
		}
	}
	output2();
}

void LedDo2(char couleur){
	if (couleur == 'v'){
		if (((rouge>>7)%2)== 1){
			rouge = rouge - 128;
		}
		if (((vert>>7)%2)== 0){
			vert = vert + 128;
		}
	}

	if (couleur == 'j'){
		if (((rouge>>7)%2)==0){
			rouge = rouge + 128;
		}
		if (((vert>>7)%2)==0){
			vert = vert + 128;
		}
	}

	if (couleur == 'r'){
		if (((rouge>>7)%2)== 0){
			rouge = rouge + 128;
		}
		if (((vert>>7)%2)==1){
			vert = vert - 128;
		}
	}
	if (couleur == 'n'){
		if (((rouge>>7)%2)== 1){
			rouge = rouge - 128;
		}
		if (((vert>>7)%2)== 1){
			vert = vert - 128;
		}
	}
	output2();
}

void OpenLEDForNotes(char noteSequence)
{
	for(int j = 7; j >= 0; j--)
	{
		if(isNotePressed(j, noteSequence))
		{
			switch(j)
			{
				case VAL_DO1:
					LedDo('v');
					break;
				case VAL_RE:
					LedRe('v');
					break;
				case VAL_MI:
					LedMi('v');
					break;
				case VAL_FA:
					LedFa('v');
					break;
				case VAL_SOL:
					LedSol('v');
					break;
				case VAL_LA:
					LedLa('v');
					break;
				case VAL_SI:
					LedSi('v');
					break;
				case VAL_DO2:
				default:
					LedDo2('v');
					break;
			}
		}
	}
}

