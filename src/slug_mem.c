/* slug_mem.c
 *
 * CREATED: Leland Miller (5/14/14)
 */

/* LM: Little trace macro, I couldn't figure out how 
 *     to get it to take variables though, so not
 *     too useful I guess. Can definitely remove 
 *     eventually.
 */
#define __DEBUG_MODE__

#ifdef __DEBUG_MODE__
#define TRACE(s) printf(s)
#else
#define TRACE(s) 
#endif


#include <stdlib.h>
#include <time.h>
#include <stdio.h>

typedef struct node node;
struct node 
{
	size_t len;
	void *addr;
	time_t timestap;
	char *location;
	int is_free;
	node *next;
};

node head;
node tail;

/* 
Allocates memory by calling malloc.
Returns address of allocated memory.
Records address, length, current timestamp, and location of the call in an
internal data structure.
WHERE is a string constant that records the filename and line number of caller.
*/
void *slug_malloc ( size_t size, char *WHERE )
{
    TRACE("slug_malloc\n"); 
    printf("@ %s", WHERE);


    
    return malloc(size);
}

void slug_free ( void *addr, char *WHERE )
{
    TRACE("slug_free");    
    printf("@ %s", WHERE);
}

void slug_memstats ( void )
{
    TRACE("slug_memstats");
}    

