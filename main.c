#include <stdio.h>
#include <stdbool.h>
#include "ga_sub.h"
#include <stdlib.h>
#include <time.h>

#define NUM_OF_GENE 4		// 生存可能な数の上限
#define NUM_OF_CHROMOSOME 6	// 各遺伝子が保有する染色体の数 // 並び替える値の個数
#define RAND 70			// 突然変異の発生確率(%)
#define GENERATION 10000000	// 世代交代の上限値

int GEN = 0;

int index_1[NUM_OF_GENE][NUM_OF_CHROMOSOME +1];

int array_1[NUM_OF_CHROMOSOME +1];
int array_2[NUM_OF_CHROMOSOME +1];
int array_3[NUM_OF_CHROMOSOME +1];
int array_4[NUM_OF_CHROMOSOME +1];

int root_array[NUM_OF_CHROMOSOME];	// ソートしたい配列

static unsigned long int next = 1;

int return_rand(int num){
	next = next *1103515245+12345;
	return (unsigned int)(next / 65536) % 32768 % num;
}

// 交叉		TEST
void crossing(){
	int pos = return_rand(NUM_OF_CHROMOSOME);
	int alpha[NUM_OF_CHROMOSOME];
	int beta[NUM_OF_CHROMOSOME];
	for(int i = 0 ; i < NUM_OF_CHROMOSOME; i++){
		alpha[i] = index_1[0][i];
		beta[i] = index_1[1][i];
	}
	alpha[pos] = index_1[0][pos];
	beta[pos] = index_1[1][pos];
	int fix = index_1[0][pos];
	while(fix != index_1[1][pos]){
		int y = get_index(index_1[1][pos]);
		alpha[y] = index_1[0][y];
		beta[y] = index_1[1][y];
		pos = y;
	}
	for(int i = 0 ; i < NUM_OF_CHROMOSOME ; i++){
		index_1[NUM_OF_GENE -1][i] = alpha[i];
		index_1[NUM_OF_GENE -2][i] = beta[i];
	}
}

// 交叉
void crossing_test(){
	int alpha_before = 0;
	int beta_before = 0;
	int alpha_after = 0;
	int beta_after = 0;
	for(int i = 0; i < NUM_OF_CHROMOSOME; i++){
		index_1[0][i] = i;
		index_1[1][i] = NUM_OF_CHROMOSOME-1-i;
		index_1[NUM_OF_GENE-1][i] = 0;
		index_1[NUM_OF_GENE-2][i] = 0;
	}
	crossing();
	for(int i = 0 ; i < NUM_OF_CHROMOSOME ; i++){
		alpha_before += index_1[0][i];
		beta_before += index_1[1][i];
		alpha_after += index_1[NUM_OF_GENE-2][i];
		beta_after += index_1[NUM_OF_GENE-1][i];
	}
	if(alpha_before != beta_before && beta_before != alpha_after && alpha_after != beta_after)
		fprintf(stderr, "crossing_test() is bad \n");
}

int get_index(int num){
	// 引数numとして与えられた値と同じものを持つindex値を返す
	for ( int i = 0; i < NUM_OF_CHROMOSOME; i++){
		if( index_1[0][i] == num){
			return i;
		}
	}
	return 0;
}

void get_index_test(){
	for(int i = 0 ; i < NUM_OF_CHROMOSOME ; i++){
		index_1[0][i] = i;
	}
	for(int i = 0 ; i < NUM_OF_CHROMOSOME ; i++){
		if(i != get_index(i)){
			fprintf(stderr, "crossing_test() is bad \n");
		}
	}
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

// 突然変異			TEST
void mutating_test(void){
	// インデックスの初期化
	// 全ての遺伝子で同じ染色体配列を持つ
	for(int j = 0 ; j < NUM_OF_GENE; j++){
		for(int k = 0; k <= NUM_OF_CHROMOSOME; k++){
			index_1[j][k] = k;
		}
	}
	// テストする
	int tested = mutating();
	int fitness_sum = 0;
	for(int i = 0; i < NUM_OF_GENE; i++){
		fitness_sum += index_1[i][NUM_OF_CHROMOSOME];
	}
	if( tested == true && fitness_sum == index_1[0][NUM_OF_CHROMOSOME] * (NUM_OF_GENE -1) ){
		fprintf(stderr, "mutating() is fault \n");
		exit(1);
	}
	else if( tested == false && fitness_sum != index_1[0][NUM_OF_CHROMOSOME] * (NUM_OF_GENE -1)){
		fprintf(stderr, "mutating() is fault \n");
		exit(1);
	}

}

// 選択			TEST
void xselect_test(void){
	for(int i = 0; i < NUM_OF_CHROMOSOME; i++){
		index_1[3][i] = i;
	}
	index_1[2][0] = 1;
	index_1[2][1] = 2;
	index_1[2][2] = 3;
	index_1[2][3] = 4;
	index_1[2][4] = 6;
	index_1[2][5] = 5;

	index_1[1][0] = 6;
	index_1[1][1] = 2;
	index_1[1][2] = 3;
	index_1[1][3] = 4;
	index_1[1][4] = 5;
	index_1[1][5] = 1;

	index_1[0][0] = 1;
	index_1[0][1] = 2;
	index_1[0][2] = 6;
	index_1[0][3] = 5;
	index_1[0][4] = 4;
	index_1[0][5] = 3;

	calc_fitness();
	xselect();

	for(int i = 0; i < NUM_OF_GENE-1; i++){
		if(index_1[i][NUM_OF_CHROMOSOME] < index_1[i+1][NUM_OF_CHROMOSOME]){
			fprintf(stderr, "xselect() is bad \n");
			exit(1);
		}
	}
}

// インデックスのソート	TEST
void index_sort_test(void){
	// 選択のテストと同じため省略
}

// 置換			TEST
void swap_content_test(void){
	for(int i = 0 ; i < NUM_OF_CHROMOSOME; i++){
		index_1[0][i] = i;
		index_1[1][i] = NUM_OF_CHROMOSOME -1 -i;
	}
	swap_content(0,1);
	for(int i = 0 ; i < NUM_OF_CHROMOSOME; i++){
		if(index_1[0][i] == i && index_1[1][i] == NUM_OF_CHROMOSOME -1 -i){
			fprintf(stderr, "xselect() is bad \n");
			exit(1);
		}
	}
}

// テスト全体を実行する
void test(void){
	printf("start calc_fitness_test()..... ");
	calc_fitness_test();
	printf("finished\n");

	printf("start crossing_test()..... ");
	crossing_test();
	printf("finished\n");

	printf("start xselect_test()..... ");
	xselect_test();
	printf("finished\n");

	printf("start index_sort_test()..... ");
	index_sort_test();
	printf("finished\n");

	printf("start swap_content_test()..... ");
	swap_content_test();
	printf("finished\n");

	printf("start get_index_test()..... ");
	get_index_test();
	printf("finished\n");

	
	printf("\n\nall tests are finished\n\n");
}

// 適応度の計算
void calc_fitness(void){

	for (int i = 0; i < NUM_OF_GENE; i++){
		for (int j = 0; j < NUM_OF_CHROMOSOME - 1; j++){
			if(index_1[i][j] <= index_1[i][j+1]){
				index_1[i][NUM_OF_CHROMOSOME] += 1+j;
			}
		}
	}
}

// 突然変異
// 実行した場合はtrue, そうでない場合はfalse
int mutating(void){
	double probability = return_rand(100);
	if(probability < RAND){
		int a = return_rand(NUM_OF_CHROMOSOME);
		int b = return_rand(NUM_OF_CHROMOSOME);
		int c = return_rand(NUM_OF_GENE);
		int tmp = index_1[c][a];
#ifdef DEBUG
		printf("before mutate index_1[%d] = ",c);
		for(int i = 0 ; i < NUM_OF_CHROMOSOME ; i++){
			printf("%d", index_1[c][i]);
		}
		printf("\n");
#endif
		index_1[c][a] = index_1[c][b];
		index_1[c][b] = tmp;
#ifdef DEBUG
		printf("after mutate index_1[%d] = ",c);
		for(int i = 0 ; i < NUM_OF_CHROMOSOME ; i++){
			printf("%d", index_1[c][i]);
		}
		printf("\n");
#endif
		return true;
	}
	else{
		return false;
	}
}

// 選択
void xselect(void){
	index_sort();
}

// インデックスのソート
void index_sort(void){
	for(int i = 0; i < NUM_OF_GENE -1; i++){
		for(int j = 0; j < NUM_OF_GENE - i + 1; j++){
			if(index_1[j][NUM_OF_CHROMOSOME] > index_1[j-1][NUM_OF_CHROMOSOME])
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
	init_mutate();
	srand((unsigned)time(NULL));
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
		}
	}
}

// インデックスの要素すべてを突然変異させる関数
int init_mutate(void){
	int a = 0;
	int b = 0;
	int tmp = 0;
	for(int i = 0; i < NUM_OF_GENE; i++){
		while(a == b){
			a = return_rand(NUM_OF_CHROMOSOME);
			b = return_rand(NUM_OF_CHROMOSOME);
		}
#ifdef DEBUG
		printf("before index_1[%d][%d] = %d, index_1[%d][%d] = %d\n",i,a,index_1[i][a], i,b,index_1[i][b]);
#endif
		tmp = index_1[i][a];
		index_1[i][a] = index_1[i][b];
		index_1[i][b] = tmp;
#ifdef DEBUG
		printf("after  index_1[%d][%d] = %d, index_1[%d][%d] = %d\n",i,a,index_1[i][a], i,b,index_1[i][b]);
#endif
		a = 0;
		b = 0;
	}

#ifdef DEBUG
	for(int i = 0 ; i < NUM_OF_GENE ; i++){
		printf("index_1[%d][] = ", i);
		for(int j = 0 ; j < NUM_OF_CHROMOSOME ; j++){
			printf(" %d ", index_1[i][j]);
		}
		printf(" \n");
	}
#endif
}

// ソートしたい配列そのものを初期化する関数
void input_root_array(void){
	root_array[0] = 6;
	root_array[1] = 5;
	root_array[2] = 4;
	root_array[3] = 3;
	root_array[4] = 2;
	root_array[5] = 1;
}

int main(int argc, char *argv[]){

#ifdef TEST
	test();
	return 0;
#endif
	int n = 0;
	printf("世代数を入力してください >> ");
	scanf("%d", &GEN);
	
	init();

	printf("before =");
	for(int i = 0; i < NUM_OF_CHROMOSOME; i++){
		printf(" %d ", index_1[0][i]);
	}
	printf("\n");

	for(; n < GEN; n++){
		calc_fitness();
		xselect();
		crossing();
		mutating();

#ifndef DEMO
		// 結果を出力
		printf("n = %d\n", n);
		printf("result = ");
		for(int i = 0; i < NUM_OF_CHROMOSOME; i++){
			printf(" %d ", index_1[0][i]);
		}
		printf("\n");
#endif
	}
	
	printf("after  =");
	for(int i = 0; i < NUM_OF_CHROMOSOME; i++){
		printf(" %d ", index_1[0][i]);
	}
	printf("\n");

	fflush(stdout);

	return 0;
}

