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
<<<<<<< HEAD
#include <errno.h>
#include <stdio.h>

struct node {
	size_t size;
=======
#include <time.h>
#include <stdio.h>

struct node 
{
	size_t len;
>>>>>>> e6705fa9e01ad5a718e9ed673084997a8124f4fd
	void addr;
	time_t alloc_time;
	time_t free_time;
	char *alloc_location;
	char *free_location;
	int is_free;
	node *next;
};

struct malloc_list {
	node head;
	node tail;
	node curr; /* can be used for traversing the list in for loops */
};

struct malloc_list m_list = malloc(sizeof(struct malloc_list));

/* 
Allocates memory by calling malloc.
Returns address of allocated memory.
Records address, length, current timestamp, and location of the call in an
internal data structure.
WHERE is a string constant that records the filename and line number of caller.
*/
void *slug_malloc ( size_t size, char *WHERE )
{
<<<<<<< HEAD
	if(size <= 0) {
		fprintf(stderr, "%s\n", strerror(errno));
	}
	
	if(size > 134217728) { /* i.e. 128 MB */
		fprintf(stderr, "%s\n", strerror(errno));
		exit(1); /*terminate program*/
	}
	
	struct node tmp = malloc(sizeof(struct node));
	tmp->size = size;
	void *address = tmp->addr = malloc(sizeof(size));
	tmp->alloc_time = time(NULL);
	tmp->free_time = NULL;
	tmp->alloc_location = WHERE;
	tmp->free_location = NULL;
	tmp->is_free = 0;
	tmp->next = NULL;
	m_list->tail->next = tmp;
	m_list->tail = m_list->tail->next;
	
	return address;
=======
    TRACE("slug_malloc\n"); 
    printf("@ %s", WHERE);

	/* if (size <= 0) print to stderr, don't exit
	if( size > 128 MB) print to stderr, exit the program */
	unsigned request = malloc(sizeof(size));
	return request;
    /* LM: this is what I had before can delete */
    /* return malloc(size); */
>>>>>>> e6705fa9e01ad5a718e9ed673084997a8124f4fd
}

void slug_free ( void *addr, char *WHERE )
{
    TRACE("slug_free");    
    printf("@ %s", WHERE);
}

void slug_memstats ( void )
{
<<<<<<< HEAD
}

void alloc_new_node( size_t size )
{
	struct node tmp = malloc(sizeof(node));
	tmp->size = size;
	tmp->addr = malloc(sizeof(size));
	tmp->alloc_time = time(NULL);
	tmp->free_time = NULL;
	tmp->location = 
	m_list->tail->next = tmp;
	m_list->tail = m_list->tail->next;
}
=======
    TRACE("slug_memstats");
}    

>>>>>>> e6705fa9e01ad5a718e9ed673084997a8124f4fd
