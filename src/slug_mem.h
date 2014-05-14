/* slug_mem.h
 *
 * Header file for slug_mem.c
 *
 * CREATED: Leland Miller (5/14/14)
 */

#include "slug_mem.c"

void *slug_malloc ( size_t size, char *WHERE );
void slug_free ( void *addr, char *WHERE );
void slug_memstats ( void );
