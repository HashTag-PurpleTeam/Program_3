#include <stdio.h>

int main(){
	int *pointer;
	
	pointer = malloc(1024);
	if (pointer == 0){ printf("error\n"); return 1; }
	*pointer = 24;
	printf(%d\n", *pointer);
	free(pointer);
	return 0;
}