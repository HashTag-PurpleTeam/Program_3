/* slug_mem.c
 *
 * CREATED: Leland Miller (5/14/14)
 * TODO better error messages (location etc)
 */

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef struct node node;
struct node 
{
    size_t len;
    void *addr;
    time_t timestamp;
    char *location;
    bool active;
    node *next;
};

node *head = NULL;
node *tail = NULL;
int set_exit = 0;

void slug_memstats ( void )
{
    int total_allocations = 0,
        active_allocations = 0,
        total_size = 0;
    double mean = 0,
           std_dev = 0,
           variance = 0,
           curr_var = 0;
    node *curr = head;

    printf("=== slug_memstats() ===\n");
    while (curr != NULL) {
        total_allocations++;
        total_size += curr->len;

        printf("Time: %s", ctime(&(curr->timestamp)));
        printf("Location: %s\n", curr->location);
        printf("Address: %p\n", curr->addr);
        /*size_t is unsigned int in minix */
        printf("Size: %u\n", (unsigned int) curr->len); 
        printf("Active: ");
        if (curr->active) {
            active_allocations++;
            printf("true\n");
        } else {
            printf("false\n");
        }
        printf("***********************\n");

        curr = curr->next;
    }
    mean = (double) total_size / total_allocations;

    /* Now calc std dev. */
    curr = head;
    while (curr != NULL) {
        curr_var = curr->len;
        curr_var -= mean;
        curr_var *= curr_var;
        variance += curr_var;
        curr = curr->next;
    }
    variance /= (double) total_allocations;
    std_dev = sqrt(variance);

    printf("Total allocations: %d\n", total_allocations);
    printf("Active allocations: %d\n", active_allocations);
    printf("Size of all allocations: %d\n", total_size);
    printf("Mean of allocation sizes: %g\n", mean);
    printf("Std. deviation of allocation sizes: %g\n", std_dev);

}

void add_node(node *n)
{
    if (head == NULL) {
        head = tail = n;
    } else {
        tail->next = n;
        tail = n;
    }
}

/* Function that checks if memory
   is still allocated. Then calls
   slug_memstats() to report.
*/
void slug_check ( void )
{
    node *curr = head;
    while (curr != NULL) {
        if (curr->active == true) {
            /* This is not freed */
            fprintf(stderr, "All allocations not freed.\n");
            slug_memstats();
            return;
        }
        curr = curr->next;
    }
    /* All allocations freed */
}

/* 
Allocates memory by calling malloc.
Returns address of allocated memory.
Records address, length, current timestamp, and location of the call in an
internal data structure.
WHERE is a string constant that records the filename and line number of caller.
 * TODO Need to check if malloc returns NULL
*/
void *slug_malloc ( size_t size, char *WHERE )
{
    void* addr; 
    node *new_n;

    if (!set_exit) { /* sets the program to exit with a call to slug_memstats */
        atexit(slug_check);
        set_exit = 1;
    }
    
    if (size <= 0) {
        fprintf(stderr, "Allocation size less than 0.\n");
    }

    if (size > 134217728) { /* i.e. 128 MB */
        fprintf(stderr, "Requested allocation size above 128 MiB.\n");
        exit(1); /*terminate program*/
    }

    /* Do the malloc */
    addr = malloc(size);
   
   /* Make the node */
    new_n = (node *) malloc(sizeof (node));
    new_n->len = size;
    new_n->addr = addr;
    new_n->location = WHERE;
    new_n->active = true;
    new_n->next = NULL;
    time(&(new_n->timestamp)); 

    add_node(new_n);

    return addr;
}

void slug_free ( void *addr, char *WHERE )
{
    node *curr = head;
	/* can't cast void* to size_t, need another workaround */
	size_t *address = (size_t *) *addr;
	
    while (curr != NULL) {
        if (curr->addr == addr) {
            if (curr->active) {
                /* This is a valid free */
                curr->active = false;
                free(addr);
                return;
            } else { /* Tried to free twice */
                fprintf (stderr, "%s: Tried to free an already freed allocation.\n", WHERE);
				return;
            }
        } else {
			if ((curr->addr < addr) && (((size_t *)curr->addr + curr->len) >= address)){
				fprintf(stderr, "%s: Call to free() made on pointer of nonstarting bit.\n", WHERE);
			}
		}
        curr = curr->next;
    }
    /* If we reach this point this is an invalid free */
    fprintf(stderr, "%s: Call to free() made on unallocated address.\n", WHERE);
    exit(1);
}    

