
#include "test.h"
#include "ga_sub.h"
#include <stdio.h>

void init_indexes_test(void){
    int NOG = 4;
    int NOC = 6;
    int test_index[NOG][NOC];
    int test_root_array[NOC];

    for(int i = 0; i < NOC; i++){
        test_root_array[i] = i;
    }

    init_indexes(NOG, NOC, test_index, test_root_array);

    for(int i = 0; i < NOG; i++){
        for(int j = 0; j < NOC; j++){
            if(test_index[i][j] != test_root_array[j]){
                fprintf(stderr, "init_indexes_test() is failed \n");
            }
        }
    }
}

void init_mutate_test(void){
    int NOG = 4;
    int NOC = 6;
    int test_index[NOG][NOC];
    int flag = 0;

    for(int i = 0 ; i < NOG; i++){
        for(int j = 0; j < NOC ; j++){
            test_index[i][j] = j;
        }
    }

    init_mutate(NOG, NOC, test_index);

    for(int i = 0; i < NOG; i++){
        for(int j = 0; j < NOC; j++){
            if(test_index[i][j] != j)
                flag++;
        }
    }

    if(flag != NOG * 2){
        fprintf(stderr, "init_mutate_test is failed\n");
    }
}
