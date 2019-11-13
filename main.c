#include <stdio.h>
#include <stdbool.h>
#include "ga_sub.h"
#include <stdlib.h>
#include <time.h>

#ifdef TEST
#include "test.h"
#endif

#define NUM_OF_GENE 4	// 生存可能な数の上限
#define NUM_OF_CHROMOSOME 6	// 各遺伝子が保有する染色体の数 // 並び替える値の個数
#define RAND 30		// 突然変異の発生確率(%)

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

// 適応度の計算		TEST
void calc_fitness_test(void){
	for(int i = 0; i < NUM_OF_CHROMOSOME; i++){
		index_1[0][i] = i;
	}
	index_1[1][0] = 1;
	index_1[1][1] = 2;
	index_1[1][2] = 3;
	index_1[1][3] = 4;
	index_1[1][4] = 6;
	index_1[1][5] = 5;

	index_1[2][0] = 6;
	index_1[2][1] = 2;
	index_1[2][2] = 3;
	index_1[2][3] = 4;
	index_1[2][4] = 5;
	index_1[2][5] = 1;

	index_1[3][0] = 1;
	index_1[3][1] = 2;
	index_1[3][2] = 6;
	index_1[3][3] = 5;
	index_1[3][4] = 4;
	index_1[3][5] = 3;

	calc_fitness();

	if(index_1[0][NUM_OF_CHROMOSOME] != 5){
		fprintf(stderr, "index_1[0] is bad \n");
		exit(1);
	}
	if(index_1[1][NUM_OF_CHROMOSOME] != 4){
		fprintf(stderr, "index_1[1] is bad \n");
		exit(1);
	}
	if(index_1[2][NUM_OF_CHROMOSOME] != 3){
		fprintf(stderr, "index_1[2] is bad \n");
		exit(1);
	}
	if(index_1[3][NUM_OF_CHROMOSOME] != 2){
		fprintf(stderr, "index_1[3] is bad \n");
		exit(1);
	}
	
}

// 交叉			TEST
void crossing_test(void){
	// インデックスの初期化
	// 全ての遺伝子で同じ染色体配列を持つ
	for(int j = 0 ; j < NUM_OF_GENE; j++){
		for(int k = 0; k <= NUM_OF_CHROMOSOME; k++){
			index_1[j][k] = k;
		}
	}
	// テストする
	int tested = crossing();
	int fitness_sum = 0;
	for(int i = 0; i < NUM_OF_GENE; i++){
		fitness_sum += index_1[i][NUM_OF_CHROMOSOME];
	}
	if( tested == true && fitness_sum == index_1[0][NUM_OF_CHROMOSOME] * (NUM_OF_GENE -1) ){
		fprintf(stderr, "crossing() is fault \n");
		exit(1);
	}
	else if( tested == false && fitness_sum != index_1[0][NUM_OF_CHROMOSOME] * (NUM_OF_GENE -1)){
		fprintf(stderr, "crossing() is fault \n");
		exit(1);
	}

}
// 選択			TEST
void select_test_test(void){
}
// インデックスのソート	TEST
void index_sort_test(void){
}
// 置換			TEST
void swap_content_test(void){
}
// テスト全体を実行する
void test(void){
}

// 適応度の計算
void calc_fitness(void){

	for (int i = 0; i < NUM_OF_GENE; i++){
		for (int j = 0; j < NUM_OF_CHROMOSOME - 1; j++){
			if(index_1[i][j] <= index_1[i][j+1]){
				index_1[i][NUM_OF_CHROMOSOME] += 1;
			}
		}
	}
}

// 交叉
// 実行した場合はtrue, そうでない場合はfalse
int crossing(void){
	double probability = return_rand(100);
	if(probability < RAND){
		int a = return_rand(NUM_OF_CHROMOSOME-1);
		int b = return_rand(NUM_OF_CHROMOSOME-1);
		int c = return_rand(NUM_OF_GENE-1);
		int tmp = index_1[c][a];
		index_1[c][a] = index_1[c][b];
		index_1[c][b] = tmp;
		return true;
	}
	else{
		return false;
	}
}

// 選択
void select(void){
	index_sort();
}

// インデックスのソート
void index_sort(void){
	for(int i = 0; i < NUM_OF_GENE -1; i++){
		for(int j = 0; j < NUM_OF_GENE - i + 1; j++){
			swap_content(j, j-1);
		}
	}
}

// 置換
void swap_content(int a, int b){
	int tmp[NUM_OF_CHROMOSOME+1];

	for(int i = 0; i < NUM_OF_CHROMOSOME+1; i++){
		tmp[i] = index_1[a][i];
		index_1[a][i] = index_1[b][i];
		index_1[b][i] = tmp[i];
	}
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

#ifdef TEST
	test();
	return 0;
#endif

	init();

	return 0;
}

