#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int s;
		srand(time(NULL));
		s = rand() % 10 +1;
		printf("%d\n",s);
		srand(time(NULL));
		s = rand() % 10 +1;
		printf("%d\n",s);
		srand(time(NULL));
		s = rand() % 10 +1;
		printf("%d\n",s);
	return 0;
}
