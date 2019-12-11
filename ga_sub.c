#include <stdio.h>
#include <stdbool.h>
#include "ga_sub.h"
#include <stdlib.h>
#include <time.h>

static unsigned long int next = 1;

int return_rand(int num){
	next = next *1103515245+12345;
	return (unsigned int)(next / 65536) % 32768 % num;
}
