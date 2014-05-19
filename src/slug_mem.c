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
#include <stdbool.h>

typedef struct node node;
struct node 
{
	size_t len;
	void *addr;
	time_t timestamp;
	char *location;
	bool is_free;
	node *next;
};

node *head = NULL;
node *tail = NULL;

void add_node(node *n)
{
    if (head == NULL) {
        head = tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
}

/* 
Allocates memory by calling malloc.
Returns address of allocated memory.
Records address, length, current timestamp, and location of the call in an
internal data structure.
WHERE is a string constant that records the filename and line number of caller.
*/
void *slug_malloc ( size_t size, char *WHERE )
{
    void* addr; 

    TRACE("slug_malloc\n"); 
    printf("@ %s", WHERE);

    /* Do the malloc */
    addr = malloc(size);
   
   /* Make the node */
    node *new_n = (node *) malloc(sizeof (node));
    new_n->len = size;
    new_n->addr = addr;
	new_n->location = WHERE;
	new_n->is_free = false;
	new_n->next = NULL;
    time(&(new_n->timestamp)); 

    return addr;
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

