/* slug_mem.c
 *
 * CREATED: Leland Miller (5/14/14)
 */

#include <stdlib.h>

struct node {
	size_t len;
	void addr;
	time_t timestap;
	char *location;
	int is_free;
	node *next;
};

struct malloc_list {
	node head;
	node tail;
	node curr; /* can be used for traversing the list in for loops */
};

/* 
Allocates memory by calling malloc.
Returns address of allocated memory.
Records address, length, current timestamp, and location of the call in an
internal data structure.
WHERE is a string constant that records the filename and line number of caller.
*/
void *slug_malloc ( size_t size, char *WHERE )
{
	/* if (size <= 0) print to stderr, don't exit
	if( size > 128 MB) print to stderr, exit the program */
	unsigned request = malloc(sizeof(size));
	return request;
}

void slug_free ( void *addr, char *WHERE )
{
}

void slug_memstats ( void ) 
{
}
