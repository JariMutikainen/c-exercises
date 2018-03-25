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
    void updateNode(int old, int new, node_t* top);
    void deleteNode(int num, node_t** pHead);
    node_t* head = NULL;

    appendNode(12,&head);
    appendNode(13,&head);
    appendNode(14,&head);

    updateNode(13,33,head);
    deleteNode(14,&head);
    deleteNode(13,&head);
    deleteNode(33,&head);
    deleteNode(12,&head);
    deleteNode(77,&head);


    appendNode(42,&head);
    appendNode(43,&head);
    appendNode(44,&head);

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
//------------------------------ updateNode ------------------------------  
void updateNode(int old, int new, node_t* top) {
    // This function updates the contents of the nodes, which have val=old.
    // The new value is substituted for that.

    node_t* p = top;

    
    if(p == NULL) {
        printf("\nUnable to update. The linked list is empty now.\n\n");
    } else{
        while(p->next != NULL) {
            if(p->val == old) {
                p->val = new;
                printf("Substituted %d for %d\n",new,old);
            }
            p = p->next;
        }
        // p is pointing at the last node now.
        if(p->val == old) {
            p->val = new;
            printf("Substituted %d for %d\n",new,old);
        }
    }
    displayList(top);
    return;
}
//------------------------------ deleteNode ------------------------------  
void deleteNode(int num, node_t** pHead) {
    // This function deletes the first node with the val=num from the
    // linked list.
    
    int itWasNotFound = 1;
    node_t* p = *pHead;
    node_t* prev = NULL;
    node_t* temp = NULL;
    if(p == NULL) { // There are no nodes in the list.
        printf("Unable to delete the node %d: the list is empty.\n",num);
    } else {
       while(p->next != NULL) {
           if(p->val == num) {  // This node must be deleted
                temp = p;
                if(prev == NULL) { // delete the 1st node of the list
                    *pHead = p->next;
                    p = p->next;
                    printf("Deleted the 1st node %d at %p.\n",num,temp);
                    free(temp);
                    itWasNotFound = 0;
                } else { // delete a middle node
                    prev->next = p->next;
                    p = p->next;
                    printf("Deleted the middle node %d. at %p\n",num,temp);
                    free(temp);
                    itWasNotFound = 0;
                }
           }
           prev = p;
           p = p->next;
       }
       // p is now pointing at the last node of the list.
       if(p->val == num) {  // This node must be deleted
            temp = p;
            if(prev == NULL) { // delete the 1st node of the list
                *pHead = p->next; // sets *pHead to NULL
                printf("Deleted the only node %d at %p.\n",num,temp);
                free(temp);
                itWasNotFound = 0;
            } else { // delete the last node
                prev->next = p->next; // sets prev->next to NULL
                printf("Deleted the last node %d at %p.\n",num,temp);
                free(temp);
                itWasNotFound = 0;
            }
       }
       if(itWasNotFound) {
           printf("Unable to delete node %d. No such node in the list.\n",num);
       }
    }
    displayList(*pHead);
    return;
}




