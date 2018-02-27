/* 3) Write a program that reads from an input file (having a set of names) and 
 * store the same in a linked list.
* a. Display the contents of linked list
* b. Traverse the linked list and deleted all nodes having names whose length 
* is less than 10 chars
* c. Display the contents of updated linked list

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXNAMELENGTH 30  /*The max length, that can be read from the input file.*/
#define MINNAMELENGTH 13  /*The min length to survive the pruning phase.*/

typedef struct node_s {
    char* name;
    struct node_s* pNext;
} Node_t, *pNode_t;

int main()
{
    void createLinkedList(pNode_t* head);
    void printLinkedList(const pNode_t head);
    void pruneShortNames(pNode_t* head, int minNameLength);
    pNode_t top = NULL;  // The pointer to the top element of the linked list
    createLinkedList(&top);
    //printf("'top' points at %p now.\n",top);
    printLinkedList(top);
    pruneShortNames(&top,MINNAMELENGTH);
    return 0;
}
//------------------------------ createLinkedList ---------------------------  
void createLinkedList(pNode_t* head) {
    // This function reads a list of names from the input file. It creates
    // a linked list of those names. To learn to use pointers better I decided to
    // manipulate the 'top'-pointer of the main directly from within this
    // function.
    FILE* inFile = 
    fopen("H:\\GitHubLocalRepository\\c-exercises\\linkedList\\names.txt","r");
    char name[MAXNAMELENGTH];
    char* pNewName;
    pNode_t pNew = NULL;
    while(fgets(name,MAXNAMELENGTH,inFile)) { // fgets returns NULL when EOF.
        // Skip the empty lines
        if(strlen(name) > 3)  {
            // Strip '\n' from the end of the name by overwriting it by another '\0'.
            name[strlen(name)-1] = '\0';
            // create a linked list node
            pNew = (pNode_t) malloc(sizeof(Node_t));
            if(pNew == NULL) {
                printf("Error: malloc returned NULL for pNew?!?. Investigate.\n");
                return;
            }
            // Catch the name
            pNewName = (char*) malloc(strlen(name) + 1); // '\0' at the end.
            if(pNewName == NULL) {
                printf("Error: malloc returned NULL for pNewName?!?. Investigate.\n");
                return;
            }
            strcpy(pNewName,name);
            pNew->name = pNewName;

            // Insert the new node in front of all the (possibly) existing nodes of
            // the linked list.
            pNew->pNext = *head; // Make the new 1st to point at whatever used to
                                 // be the 1st node up until now.
            *head = pNew;        // The 'top' in main must point at this new 1st.

        }
    }
    return;
}
//------------------------------ printLinkedList ------------------------------  
void printLinkedList(const pNode_t head) {
    // This function traverses through a linked list and prints all the names
    // in it.
    pNode_t p = head;
    printf("p = %p to start with.\n",p);
    if(p == NULL) {
        printf("The linked list is empty.\n");
    } else {
        printf("The linked list consists of the following names:\n");
        while(p->pNext) { // The last node has NULL as pNext.
            printf("%s\n",p->name);
            p = p->pNext; // Move on to the next node in the chain.
        }
        // p is now pointing at the last node, but that node has not
        // been printed yet - so let's do it now.
        printf("%s\n",p->name);
    }
    return;
}
//------------------------------ minNameLength ------------------------------  
void pruneShortNames(pNode_t* head, int minNameLength) {
    // This function traverses through the linked list and removes all the
    // names, which are shorter than minNameLength.
    pNode_t p = *head; // Point at the 1st element to start with.
    pNode_t pPrev = NULL;
    if(p == NULL) {
        printf("The linked list is already empty.\n");
        return;
    }
    printf("\nPruning out all the names shorter than %d.\n",minNameLength);



    return;
}
