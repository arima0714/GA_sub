#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

int return_rand(int num){
	// 実行時期が限りなく近いときに返値がバラバラにする必要がある
	int s;
	srand(time(NULL));
	s = rand() % num + 1;
	return s;
}

int return_rand_fixed(int num){
	// 実行時期が限りなく近いときに返値がバラバラにする必要がある
	int s;
	struct timeval myTime;
	struct tm *time_st;
	time_st = localtime(&myTime.tv_sec);
	srand(time(NULL) + myTime.tv_usec);
	s = rand() % num + 1;
	return s;
}

int main(int argc, char **argv){
	return 0;
}

