#include <libarmus.h>
#include "LED/LED.h"

void starWars()
{
	LedDo('v');
	THREAD_MSleep(2000);
	LedSol('v');
	THREAD_MSleep(2000);
	LedFa('v');
	THREAD_MSleep(333);
	LedMi('v');
	THREAD_MSleep(333);
	LedRe('v');
	THREAD_MSleep(333);
	LedDo2('v');
	THREAD_MSleep(2000);
	LedSol('v');
	THREAD_MSleep(1000);
	LedFa('v');
	THREAD_MSleep(333);
	LedMi('v');
	THREAD_MSleep(333);
	LedRe('v');
	THREAD_MSleep(333);
	LedDo2('v');
	THREAD_MSleep(2000);
	LedSol('v');
	THREAD_MSleep(1000);
	LedFa('v');
	THREAD_MSleep(333);
	LedMi('v');
	THREAD_MSleep(333);
	LedFa('v');
	THREAD_MSleep(333);
	LedRe('v');
	THREAD_MSleep(4000);

}
