#include <stdio.h>
#include "slug_mem.h"

int main(void){
    int *pointer1, *pointer2;
    pointer1 = malloc(1024);
    free(pointer1);

    pointer2 = malloc(1024);
    pointer2++;
    free(pointer2);
    
    return(0);
}
