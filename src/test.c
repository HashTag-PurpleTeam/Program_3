#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "slug_mem.h"

int main (void)
{
	char *string[4];
	int *num[4];
	const char* hello = "Hello, world!\n";
	int i;
	
	for (i = 0; i < 4; i++) {
		string[i] = (char *) malloc(15*sizeof(char));
		num[i] = (int *) malloc(1*sizeof(int));
		strcpy(string[i], hello);
		*num[i] = i;
	}
	
	/*sleep(3); to see the difference in timestamps between allocation and free */
	
	for (i = 0; i < 4; i++) {
		free(string[i]);
		free(num[i]);
	}
 
	/*stats();*/
	
	return 1;

}
