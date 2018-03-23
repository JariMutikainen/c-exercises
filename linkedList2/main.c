/* This program implements a singly linked list. The following operations
 * are supported: append, delete, update and display.
 *
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    int val;
    struct node_s* next;
} node_t;

void displayList(node_t* top);
int main()
{
    void appendNode(int num, node_t** pHead);
    node_t* head = NULL;

    appendNode(12,&head);
    appendNode(13,&head);
    appendNode(14,&head);



    return 0;
}
//------------------------------ appendNode ------------------------------  
void appendNode(int num, node_t** pHead) {
    // This function creates a ne node and appends it into the tail of
    // the linked list.

    node_t* pNew = (node_t*) malloc(sizeof(node_t));
    pNew->val = num;
    pNew->next = NULL;
    if(*pHead == NULL) { // There are no earlier nodes in the list.
        *pHead = pNew;
        printf("Created the first node %d into %p.\n",num,pNew);
    } else {
        node_t* p = *pHead; // p to point at the 1st node
        // Find the last node of the list
        while(p->next != NULL) {
            p = p->next;
        }
        // now p points at the last node of the linked list
        p->next = pNew;
    }
    printf("Appended %d into %p.\n",num,pNew);
    displayList(*pHead);
    return;
}
//------------------------------ displayList ------------------------------  
void displayList(node_t* top) {
    // This function displays the nodes of the linked list from the head
    // into the tail.

    node_t* p = top;
    if(p == NULL) {
        printf("\nThe linked list is empty now.\n\n");
    } else{
        printf("The linked list consists of the following nodes from the head to the tail:\n");
        while(p->next != NULL) {
            printf("%d at %p\n",p->val,p);
            p = p->next;
        }
        // At this point p is pointing at the last node
        printf("%d at %p\n",p->val,p);
    }
    return;
}

