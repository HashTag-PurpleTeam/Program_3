#include <stdio.h>
#include "slug_mem.h"

int main(void){
	int *pointer, *middle;
	pointer = malloc(1024);
	if (pointer == 0){ printf("error\n"); return 1; }
	*pointer = 24;
	printf("%d\n", *pointer);
	middle = pointer + (sizeof(pointer)/2);
	free(middle);
	return 0;
}