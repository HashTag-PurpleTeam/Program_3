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
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct node *node_ref;

struct malloc_list {
	node_ref head;
	node_ref tail;
	node_ref curr; /* can be used for traversing the list in for loops */
};

struct node {
	size_t size;
	unsigned addr;
	time_t alloc_time;
	time_t free_time;
	char *alloc_location;
	char *free_location;
	int is_free;
	node_ref next;
};

int main( void )
{
	struct malloc_list *m_list = malloc(sizeof(struct malloc_list));
	m_list->head = m_list->tail = m_list->curr = NULL;
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
	node_ref tmp = malloc(sizeof(struct node));
	
	if(size <= 0) {
		fprintf(stderr, "%s\n", strerror(errno));
	}
	
	if(size > 134217728) { /* i.e. 128 MB */
		fprintf(stderr, "%s\n", strerror(errno));
		exit(1); /*terminate program*/
	}
	
	tmp->size = size;
	tmp->addr = malloc(sizeof(size));
	tmp->alloc_time = time(NULL);
	tmp->free_time = NULL;
	tmp->alloc_location = WHERE;
	tmp->free_location = NULL;
	tmp->is_free = 0;
	tmp->next = NULL;
	m_list->tail->next = tmp;
	m_list->tail = m_list->tail->next;
	free(tmp);
	
	return m_list->tail->addr;
    /*TRACE("slug_malloc\n"); 
    printf("@ %s", WHERE);*/
    /* LM: this is what I had before can delete */
    /* return malloc(size); */
}

void slug_free ( void *addr, char *WHERE )
{
    TRACE("slug_free");    
    printf("@ %s", WHERE);
}

void slug_memstats ( void )
{

}

/*void alloc_new_node( size_t size )
{
	struct node tmp = malloc(sizeof(node));
	tmp->size = size;
	tmp->addr = malloc(sizeof(size));
	tmp->alloc_time = time(NULL);
	tmp->free_time = NULL;
	tmp->location = 
	m_list->tail->next = tmp;
	m_list->tail = m_list->tail->next;
} */   
