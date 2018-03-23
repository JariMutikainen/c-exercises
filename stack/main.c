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

void displayStack(stack_t* sp);
int main()
{
    void initStack(stack_t** spp);
    void pushStack(int num,stack_t* sp);
    void popStack(stack_t* sp);
    stack_t* pStack;
    initStack(&pStack);

    printf("Initialized a stack entry to %p.\n",pStack);
    pushStack(5,pStack);
    pushStack(6,pStack);
    pushStack(7,pStack);

    popStack(pStack);
    popStack(pStack);
    popStack(pStack);
    popStack(pStack);

    pushStack(8,pStack);
    pushStack(9,pStack);
    pushStack(2,pStack);

    free(pStack);
    return 0;
}
//------------------------------ initStack ------------------------------  
void initStack(stack_t** spp) {
    // This function initializes a stack and makes the pStack pointer in main
    // to point at this new stack entry in the heap.
    *spp = (stack_t*) malloc(sizeof(stack_t));
    (*spp)->top = NULL;
    return;
}
//------------------------------ pushStack ------------------------------  
void pushStack(int num,stack_t* sp) {
    // This function creates a new node, sets the value of it to num and
    // pushes it to become the new top node of the stack.

    node_t* pNew;
    pNew = (node_t*) malloc(sizeof(node_t));
    pNew->val = num;
    pNew->next = sp->top;
    sp->top = pNew;
    printf("Pushed %d into %p.\n",num,pNew);
    displayStack(sp);
    return;
}
//------------------------------ popStack ------------------------------  
void popStack(stack_t* sp) {
    // This function pops the top node off the stack.
    
    if(sp->top == NULL) {
        printf("Unable to pop anything from an empty stack.\n\n");
        return;
    }
    node_t* p = sp->top;
    sp->top = p->next;
    printf("Popped %d at %p.\n",p->val,p);
    free(p);
    displayStack(sp);
    return;
}


//------------------------------ displayStack ------------------------------  
void displayStack(stack_t* sp) {
    // This function displays the elements of the stack from the top to
    // bottom.

    node_t* p = sp->top;
    if(p == NULL) {
        printf("The stack is empty.\n\n");
    } else {
        printf("\nThe contents of the stack from the top to the bottom are as follows:\n");
        while(p->next != NULL) {
            printf("%d at %p\n",p->val,p);
            p = p->next; // move on
        }
        // When we get here p is pointing at the last node of the stack
        printf("%d at %p\n\n",p->val,p);
    }
    return;
}
    


