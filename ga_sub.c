#include <stdio.h>
#include <stdbool.h>
#include "ga_sub.h"
#include <stdlib.h>
#include <time.h>

static unsigned long int next = 1;

int return_rand(int num){
	next = next *1103515245+12345;
	return (unsigned int)(next / 65536) % 32768 % num;
}

// インデックスに親配列を全代入する
void init_indexes(int NOG, int NOC, int index[NOG][NOC], int root_array[NOC]){
	for(int i = 0; i < NOG; i++){
		for(int j = 0; j < NOC; j++){
			index[i][j] = root_array[j];
		}
	}
}