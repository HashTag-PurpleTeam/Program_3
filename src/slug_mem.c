/* slug_mem.c
 *
 * CREATED: Leland Miller (5/14/14)
 */

#include <stdlib.h>

void *slug_malloc ( size_t size, char *WHERE );

void slug_free ( void *addr, char *WHERE );

void slug_memstats ( void );
