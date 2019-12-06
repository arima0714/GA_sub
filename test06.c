#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

int pre_num = 0;

int GetRandom(int min, int max){
	return min + (int)(rand() * max-min+1.0)/ (1.0 + RAND_MAX);
}

int return_rand(int num){
	// 実行時期が限りなく近いときに返値がバラバラにする必要がある
	int s = 0;
	srand(time(NULL));
	while(s == pre_num){
		s = rand() % num + 1;
	}
	pre_num = s;
	return s;
}

int return_rand_fixed(int num){
	// 実行時期が限りなく近いときに返値がバラバラにする必要がある
	int s = 0;
	struct timeval myTime;
	struct tm *time_st;
	time_st = localtime(&myTime.tv_sec);
	srand(myTime.tv_usec);
	while(s == pre_num){
		s = rand() % num + 1;
	}
	pre_num = s;
	return s;
}

int main(int argc, char **argv){
	int i = 0;

	printf("return_rand() = ");
	for(i = 0; i < 10; i++){
		printf("%d", return_rand(6));
	}
	printf("\n");

	printf("return_rand_fixed() = ");
	for(i = 0; i < 10; i++){
		printf("%d", return_rand_fixed(6));
	}
	printf("\n");

	printf("GetRandom() = ");
	for(i = 0; i < 10; i++){
		printf("%d", GetRandom(0, 6));
	}
	printf("\n");

	return 0;
}

