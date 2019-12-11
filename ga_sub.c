#include "ga_sub.h"

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

// インデックスの要素すべてを突然変異させる関数
void init_mutate(int NOG, int NOC, int index[NOG][NOC]){
	int a = 0;
	int b = 0;
	int tmp = 0;
	for(int i = 0; i < NOG; i++){
		while(a == b){
			a = return_rand(NOC);
			b = return_rand(NOC);
		}
		tmp = index[i][a];
		index[i][a] = index[i][b];
		index[i][b] = tmp;
		a = 0;
		b = 0;
	}
}

// 元となる配列を作成
void input_root_array(int NOC, int root_array[NOC]){
    for(int i = 0; i < NOC; i++){
        root_array[i] = NOC - i;
    }
}