#include <stdio.h>
#include "slug_mem.h"

int main(void){
	int *pointer;
	pointer = malloc(1024);
	if (pointer == 0){ printf("error\n"); return 1; }
	*pointer = 24;
	printf("%d\n", *pointer);
	free(pointer);
	free(pointer);
	return 1;
	}