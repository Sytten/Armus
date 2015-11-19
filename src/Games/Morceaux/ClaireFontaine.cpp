#include <libarmus.h>
#include "//fontcion de LED"

void claireFontaine()
{
	LedDo1('v');
	THREAD_MSleep(1700);
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
	THREAD_MSleep(1700);
	LedDo1('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(850);
	LedRe('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(1700);
	LedMi('v');
	THREAD_MSleep(1700);

	LedMi('v');
	THREAD_MSleep(850);
	LedRe('v');
	THREAD_MSleep(850);
	LedDo('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(850);
	LedSol('v');
	THREAD_MSleep(1700);

	LedSol('v');
	THREAD_MSleep(850);
	LedMi('v');
	THREAD_MSleep(850);
	LedDo('v');
	THREAD_MSleep(850);
	LedRe('v');
	THREAD_MSleep(1700);

}
