#include <libarmus.h>
#include "LED/LED.h"

void claireFontaine()
{
	LedDo('v');
	THREAD_MSleep(1667);
	LedDo('v');
	THREAD_MSleep(8500);
	LedMi('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(850);
	LedRe('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(850);
	LedRe('v');
	THREAD_MSleep(850);

	LedDo('v');
	THREAD_MSleep(1667);
	LedDo('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(850);
	LedRe('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(1667);
	LedMi('v');
	THREAD_MSleep(1667);

	LedMi('v');
	THREAD_MSleep(850);
	LedRe('v');
	THREAD_MSleep(850);
	LedDo('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(850);
	LedSol('v');
	THREAD_MSleep(1667);

	LedSol('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(850);
	LedDo('v');
	THREAD_MSleep(850);
	LedRe('v');
	THREAD_MSleep(1667);

}
