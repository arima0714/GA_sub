#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int main(int argc, char **argv){
	struct timeval myTime;
	struct tm *time_st;
	const char weekName[7][4] = {
		"Sun",
		"Mon",
		"Tue",
		"Wed",
		"Thu",
		"Fri",
		"Sat"
	};

	gettimeofday(&myTime, NULL);
	time_st = localtime(&myTime.tv_sec);

	printf("Date : %d/%02d/%02d(%s) %02d:%02d:%02d:%d\n",
			time_st->tm_year+1900,
			time_st->tm_mon+1,
			time_st->tm_mday,
			weekName[time_st->tm_wday],
			time_st->tm_hour,
			time_st->tm_min,
			time_st->tm_sec,
			myTime.tv_usec
			);
}
