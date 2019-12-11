
#include "test.h"
#include "ga_sub.h"
#include <stdio.h>

void init_indexes_test(){
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