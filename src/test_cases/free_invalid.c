#include <stdio.h>
#include "slug_mem.h"

int main(void){
	int *pointer, *pointer2;
	pointer = malloc(1024);
	if (pointer == 0){ printf("error\n"); return 1; }
	*pointer = 24;
	printf("%d\n", *pointer);
	pointer2 = pointer - (sizeof(pointer)/2);
	free(pointer);
	free(pointer2);
	return 1;
	}