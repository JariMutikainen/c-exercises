/*****************************************************************************
 * File : types.h
 * Description : This file contains the type definitions
 *
 *****************************************************************************/

/* Size of memory pool from which user can request memory allocations */
#define MAX_MEMORY 64

/* Type of Free list structure */
typedef struct free_list{
    unsigned int size;
    void *addr;
    struct free_list *next;
}free_list_node;

/* Type of Busy list structure */
typedef struct busy_list{
    unsigned int size;
    void *addr;
    struct busy_list *next;
}busy_list_node;

/* Extern declarations of global Variables */
extern busy_list_node *busyblock;
extern free_list_node *freeblock;
extern void *memory_chunk;

/* Prototypes of functions */
void init_memory_block();
void execute_choice(int);
int take_user_input();
void * first_fit_alloc(unsigned int n);
int my_memfree(void *mem_addr);
void display_free_list();
void display_busy_list();
int  insert_free_list(void *addr, unsigned int size); // Jari M.
