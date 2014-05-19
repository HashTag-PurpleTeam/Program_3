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
#include <stdio.h>
#include <errno.h>
#include <time.h>
#include <string.h>

typedef struct node *node_ref;
typedef struct malloc_list *m_list;

struct malloc_list {
	node_ref head;
	node_ref tail;
	node_ref curr; /* can be used for traversing the list in for loops */
};

struct node {
	size_t size;
	void *addr;
	time_t alloc_time;
	time_t free_time;
	char *alloc_location;
	char *free_location;
	int is_free;
	node_ref next;
};

m_list list = NULL;

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
	void *address;
	
	if(size <= 0) {
		fprintf(stderr, "%s\n", strerror(errno));
	}
	
	if(size > 134217728) { /* i.e. 128 MB */
		fprintf(stderr, "%s\n", strerror(errno));
		exit(1); /*terminate program*/
	}
	
	if(list == NULL) { /*allocate new list*/
		list = malloc(sizeof(struct malloc_list));
		list->head = list->tail = list->curr;
	}
	
	/*initialize new list node*/
	tmp->size = size;
	tmp->addr = malloc(sizeof(size));
	tmp->alloc_time = time(NULL);
	tmp->free_time = 0;
	tmp->alloc_location = WHERE;
	tmp->free_location = NULL;
	tmp->is_free = 0;
	tmp->next = NULL;
	
	if(list->tail == NULL){
		list->head = list->tail = tmp;
	}else{
		list->tail->next = tmp;
		list->tail = list->tail->next;
	}
	
	address = list->tail->addr;
	return address;
	
    /*TRACE("slug_malloc\n"); 
    printf("@ %s", WHERE);*/
    /* LM: this is what I had before can delete */
    /* return malloc(size); */
}

/* still need to check if the call is on memory that is not the first byte of
memory allocated by slug_malloc, in which case we'd error and terminate*/
void slug_free ( void *addr, char *WHERE )
{
	int valid = 0;
	
    for(list->curr = list->head; list->curr != NULL; 
	list->curr = list->curr->next){
		if(list->curr->addr == addr){
			if(list->curr->is_free == 1){
				/*already freed, print error and terminate program*/
				fprintf(stderr, "%s\n", strerror(errno));
				exit(1); /*terminate program*/
			}
			valid = 1;
			break;
		}
	}
	
	if(!valid){
		/*address not allocated w/ slug_malloc, error & terminate */
		fprintf(stderr, "%s\n", strerror(errno));
		exit(1); /*terminate program*/
	}
	
	free(addr);
	list->curr->free_time = time(NULL);
	list->curr->free_location = WHERE;
	list->curr->is_free = 1;
	
}

void slug_memstats ( void )
{

} 

/*void stats ( void )
{
	for(list->curr = list->head; list->curr != NULL; 
	list->curr = list->curr->next){
		printf("Size = %d\n", list->curr->size);
		printf(list->curr->is_free ? "Has been freed\n" : "Has not been freed\n");
		printf("Location of allocation: %s\n", list->curr->alloc_location);
		printf("Allocation timestamp: %d\n", list->curr->alloc_time);
		printf("Location of free: %s\n", list->curr->free_location);
		printf("Free timestamp: %d\n", list->curr->free_time);
	}
}*/
