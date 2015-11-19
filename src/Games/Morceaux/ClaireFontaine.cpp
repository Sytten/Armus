#include <libarmus.h>
#include "//fontcion de LED"

void claireFontaine()
{
	LedDo1('v');
	THREAD_MSleep(1667);
	LedDo1('v');
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
	LedDo1('v');
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
	LedRé('v');
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
