#include <stdio.h>
#include "ga_sub.h"
#include <stdlib.h>
#include <time.h>

#define NUM_OF_GENE 4	// 生存可能な数の上限
#define NUM_OF_CHROMOSOME 6	// 各遺伝子が保有する染色体の数 // 並び替える値の個数

int index_1[NUM_OF_GENE][NUM_OF_CHROMOSOME +1];
int index_2[NUM_OF_GENE][NUM_OF_CHROMOSOME +1];

int array_1[NUM_OF_CHROMOSOME +1];
int array_2[NUM_OF_CHROMOSOME +1];
int array_3[NUM_OF_CHROMOSOME +1];
int array_4[NUM_OF_CHROMOSOME +1];

int root_array[NUM_OF_CHROMOSOME];	// ソートしたい配列

int return_rand(int num){
	int s;
	srand(time(NULL));
	s = rand() % num + 1;
	return s;
}

// root_arrayに値を入れる
// 最初に実行される全ての配列(array_1 ~ _4)にroot_arrayの内容をコピーする
void init(){
	input_root_array();
	init_indexes();
#ifdef DEBUG
	for(int i = 0; i < NUM_OF_GENE; i++){
		printf("index_1[%d]\n", i);
		print_array(index_1[i]);
	}
	for(int i = 0; i < NUM_OF_GENE; i++){
		printf("index_2[%d]\n", i);
		print_array(index_1[i]);
	}
#endif
		
}

// 遺伝子に内蔵された要素を全て出力する関数
void print_array(int* array){
	for(int i = 0; i < NUM_OF_CHROMOSOME; i++){
		printf(" %d ",array[i]);
	}
	printf("\n");
}

// インデックスに親配列を全代入する
void init_indexes(void){
	for(int i = 0; i < NUM_OF_GENE; i++){
		for(int j = 0; j < NUM_OF_CHROMOSOME; j++){
			index_1[i][j] = root_array[j];
			index_2[i][j] = root_array[j];
		}
	}
}

// ソートしたい配列そのものを初期化する関数
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

#ifdef DEBUG
	printf("number = %d\n", return_rand(3));
#endif

	return 0;
}

