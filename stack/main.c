/* This program implements a linked list based stack with all the typical
 * stack related operations.
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int val;
    struct node_s* next;
} node_t;
typedef struct stack_s {
    node_t* top;
} stack_t;
int main()
{
    void initStack(stack_t** spp);
    void pushStack(int num,stack_t* sp);
    stack_t* pStack;
    initStack(&pStack);

    printf("Initialized a stack entry to %p.\n",pStack);
    pushStack(5,pStack);

    free(pStack);
    return 0;
}
//------------------------------ initStack ------------------------------  
void initStack(stack_t** spp) {
    // This function initializes a stack and makes the pStack pointer in main
    // to point at this new stack entry in the heap.
    *spp = (stack_t*) malloc(sizeof(stack_t));
    (*spp)->top = NULL;
}
//------------------------------ pushStack ------------------------------  
void pushStack(int num,stack_t* sp) {
    // This function creates a new node, sets the value of it to num and
    // pushes it to become the new top node of the stack.

    node_t* pNew;
    pNew = (node_t*) malloc(sizeof(node_t));
    pNew->val = num;


