/* slug_mem.c
 *
 * CREATED: Leland Miller (5/14/14)
 */

#include <stdlib.h>
#include "slug_mem.h"

struct node {
	size_t len;
	unsigned addr;
	time_t timestap;
	char **location;
	int free;
	node *next;
}

void *slug_malloc ( size_t size, char *WHERE );

void slug_free ( void *addr, char *WHERE );

void slug_memstats ( void );
