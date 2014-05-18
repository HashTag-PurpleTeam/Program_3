#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
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
	unsigned *addr;
	time_t alloc_time;
	time_t free_time;
	char *alloc_location;
	char *free_location;
	int is_free;
	node_ref next;
};

typedef struct malloc_list *m_list = malloc(sizeof(struct malloc_list));


