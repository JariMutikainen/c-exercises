#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/* Global variable to hold head of free list */
free_list_node *freeblock = NULL;

/* Function to insert a new node in the free list
   The node contains the freed block's address and size given by the
   arguments */

int  insert_free_list(void *addr, unsigned int size)
{
    free_list_node *p = freeblock;

    /* Allocate and initialize new node */
    free_list_node *newnode = NULL; 
    newnode  = (free_list_node *)malloc(sizeof(free_list_node));
    if (NULL == newnode)
    {
        printf ("ERROR: Malloc failed\n");
        exit(1);
    }
    newnode->addr = addr;
    newnode->size = size;
    newnode->next = NULL;

	/* Add the new node at the head of the linked list */

	/* If the free list is currently empty, make new node the new head
	*/
	if (NULL == p)
    {
        freeblock = newnode;
    }
    else /* Free list is not empty */
    {
        newnode->next = freeblock;
        freeblock = newnode; 
    }
    return 1;
}

/* Function to display the contents of all the nodes of the free list */
void display_free_list()
{
    free_list_node *p = freeblock;
    int count = 1;

    if (NULL == p)
    {
        printf("Free list is empty\n");
    }

    while (NULL != p)
    {
        printf ("Free list node : %d\n", count++);
        printf ("Free block address : 0x%x\n", p->addr);
        printf ("Free block size : %u\n\n", p->size);
        p = p->next;
    }
}

/* Function to de-allocate memory */
/* Address of the memory to be de-allocated is given by the argument */
int my_memfree(void *mem_addr)
{
    unsigned int s = 0; /* size of the block */
    busy_list_node *p = busyblock; /*traversing variable of the linked list*/
    void *alloc = NULL;
    busy_list_node *q = NULL; /*previous node of the traversing variable p*/

    /* Search for this address's node in the busy link list */
    while((NULL != p) && (p->addr != mem_addr))
    {
        q = p;
        p = p->next;
    }

    if (NULL != p)
    { 
        /* Retrieve the size of this block of memory */
        s = p->size;

        /* Add this block to the free list */
        insert_free_list(p->addr, p->size);

        /* Remove this block from the busy list */ 
        if (NULL == q)
        {
            busyblock = p->next;
        }
        else
        {
            q->next = p->next;
        }
        free((void *)p);
        return 1;
    } 
    else
    {
	    printf ("\nMemory deallocation unsuccessful: Invalid address\n");
        return 0;
    }
}
