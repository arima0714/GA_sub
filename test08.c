#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int s, n, i;

	srand((unsigned)time(NULL));

	printf("サイコロを振る回数 > ");
	scanf("%d", &n);

	for(i = 1; i <= n ; i++){
		s = (rand() %6) + 1;
		printf("%d\n", s);
	}

	return 0;
}

