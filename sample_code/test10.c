#include <stdio.h>

void func(int size1, int size2, int arr[size1][size2]) {
  int i, j, result = 0;
  for (i = 0; i < size1; ++i) {
    for (j = 0; j < size2; ++j) {
    //   result += arr[i][j];
    arr[i][j] = 10;
    }
  }
}

int main(void) {
  int arr[3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};

  printf("arr[][] = ");
  for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
          printf(" %d ",arr[i][j]);
      }
  }
  printf("\n");
  
  func(3,3,arr);

  printf("arr[][] = ");
  for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
          printf(" %d ",arr[i][j]);
      }
  }
  printf("\n");

  return 0;
}