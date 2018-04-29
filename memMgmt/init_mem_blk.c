#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/* Global variable to hold the large chunk of memory */
void *memory_chunk;

/* Function to allocate a chunk of memory. This function should be
 * called by the calling module only at initialization time. All further
 * memory allocations for the module will be done from this chunk of memory */

void init_memory_block()
{
    /*Allocate the memory chunk */
    memory_chunk = malloc(MAX_MEMORY);

    if (NULL == memory_chunk)
    {
        printf ("ERROR: Malloc failed\n");
        exit(1);
    }

	printf ("\nMemory chunk of size %u allocated\n", MAX_MEMORY);
    /*Initialize the free memory list */
    insert_free_list(memory_chunk, MAX_MEMORY);

    /* Initialize the busy list*/
    busyblock = NULL;
}
