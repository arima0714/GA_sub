#include <stdio.h>
#include "ga_sub.h"

#define NUM_OF_GENE 4	// 生存可能な数の上限
#define NUM_OF_CHROMOSOME 6	// 各遺伝子が保有する染色体の数 // 並び替える値の個数

int** index_1[NUM_OF_GENE];
int** index_2[NUM_OF_GENE];

int* array_1[NUM_OF_CHROMOSOME];
int* array_2[NUM_OF_CHROMOSOME];
int* array_3[NUM_OF_CHROMOSOME];
int* array_4[NUM_OF_CHROMOSOME];

int root_array[NUM_OF_CHROMOSOME];	// ソートしたい配列

// root_arrayに値を入れる
// 最初に実行される全ての配列(array_1 ~ _4)にroot_arrayの内容をコピーする
void init(){
	input_root_array();
}

void print_array(int* array){
	printf("this array contents are\n");
	for(int i = 0; i < NUM_OF_CHROMOSOME; i++){
		printf(" %d ",array[i]);
	}
	printf("\n");
}

void input_root_array(void){
	root_array[0] = 6;
	root_array[1] = 5;
	root_array[2] = 4;
	root_array[3] = 3;
	root_array[4] = 2;
	root_array[5] = 1;
#ifdef DEBUG
	printf("これは root_array の内部\n");
	print_array(root_array);
#endif
}

int main(void){

	init();


	return 0;
}

