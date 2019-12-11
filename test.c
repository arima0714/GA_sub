
#include "test.h"
#include "ga_sub.h"
#include <stdio.h>

void init_indexes_test(){
    int NOG = 4;
    int NOC = 6;
    int test_index[NOG][NOC];
    int test_root_array[NOC];

    init_indexes(NOG, NOC, test_index, test_root_array);

    for(int i = 0; i < NOG; i++){
        for(int j = 0; j < NOC; j++){
            if(test_index[NOG][NOC] != NOC -j){
                fprintf(stderr, "crossing_test() is failed \n");
            }
        }
    }
}