#include <stdio.h>
#include <stdlib.h>
#include "types.h" 

/* Global Variable to hold head of Busy List */
busy_list_node *busyblock = NULL;

/* Function to insert a new node in the busy list
   The node contains newly allocated block's address and size given by the 
   arguments */
   
int insert_busy_list(void *addr, unsigned int size)
{

    busy_list_node *p = busyblock;

    /* Allocate and initialize new node */
    busy_list_node *newnode = NULL;
    newnode  = (busy_list_node *)malloc(sizeof(busy_list_node));

    if (NULL == newnode)
    {
        printf ("ERROR: Malloc failed\n");
        exit(1);
    }

    newnode->addr = addr;
    newnode->size = size;
    newnode->next = NULL;

    /* Add the new node at the head of the linked list */
	
	/* If the busy list is currently empty, make new node the new head */
    if (NULL == p)
    {
        busyblock = newnode;
    }
    else /* Busy list is not empty */
    {
        newnode->next = busyblock;
        busyblock = newnode; 
    }
    return 1;
}

/* Function to display the contents of all the nodes of the busy list */
void display_busy_list()
{
    busy_list_node *p = busyblock;
    int count = 1;

    if (NULL == p)
    {
        printf("Busy list is empty\n");
    }
    
    while (NULL != p)
    {
        printf ("Busy list node : %d\n", count++);
        printf ("Busy block address : 0x%x\n", p->addr);
        printf ("Busy block size : %u\n\n", p->size);
        p = p->next;
    }
}

/* Function to allocate memory based on first fit algorithm */
/* Size of the memory to be allocated is given by the argument n */

void * first_fit_alloc(unsigned int n)
{
    unsigned int s = 0; /* size of the block */
    free_list_node *p = freeblock; /*traversing variable of the free list*/
    void *alloc = NULL;
    free_list_node *q = NULL; /*previous node of the traversing variable p*/

    /* Keep scanning till a block of size equal or greater to the requested
     * size is available */
    while (p != NULL && p->size < n)
    {
        q = p;
        p = p->next;
    }
    
	/* A free block is found with size = or > than the requested size */
    if (NULL != p)
    {
        s = p->size;

		/* alloc contains the address of the allocated block */
		/* If the available block is greater than the requested size then
		 * the block is allocated from the right end of the available block */
		 
        alloc = p->addr + s - n; 

        /* Update the free list */

		/* If the requested size is equal to the available block */
        if (s == n)
        {
            /* Remove the block from the free list */
            if (NULL == q)
            {
                freeblock = p->next;
            }
            else
            {
                q->next = p->next;
            }
            free ((void *)p);
        }
        else
        {
            p->size = s - n;
        }
        /* Update the  busy list */
        insert_busy_list(alloc, n);
    }
	else
	{
	    printf ("\nAllocation unsuccessful: The requested size is not available\n ");
	}
    return alloc;
}
