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

struct node 
{
	size_t len;
	unsigned addr;
	time_t timestap;
	char *location;
	int free;
	void *next;
};

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
