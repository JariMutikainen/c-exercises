/* In this exercise we create a hash table of 21 elements: 1-21. This table
 * is allowed to contain up to 17 elements. We'll write a function, which 
 * searches the hash table for a given number and if it is not there yet it 
 * is added into it. The primary location is calculated using a hash function.
 * The step used for linear pobing in the case of the primary location being
 * occupied is generated by another hash function.
 *
 * Another function is written for removing elements from the hash table.
 * */

#include <stdio.h>
#include <stdlib.h>
#define NUM_OF_LOCATIONS 21
#define MAX_NUM_OF_ELEMENTS 17
#define H1 NUM_OF_LOCATIONS
#define H2 (NUM_OF_LOCATIONS - 2)
#define EMPTY 0
#define DELETED -1

int main()
{
    void initHashTable(int* hTbl, int maxIndex, int* elems);
    void showHashTable(int* hTbl, int maxIndex);
    void searchAndInsert(int* hTbl, int maxIndex, int* elems, int key);
    int hashTable[NUM_OF_LOCATIONS + 1]; // 0 never used. Locations available:
                                         // 1-21.
    int elements = 0; // The number of elements in the hashTable[]

    initHashTable(hashTable,NUM_OF_LOCATIONS,&elements);
    //showHashTable(hashTable,NUM_OF_LOCATIONS);
    int resp = 0;
    while(1) {
        printf("Choose operation: Insert=1, Remove=2, Show=3, Quit=4: ");
        scanf("%d",&resp);
        switch(resp) {
            case 1: printf("Number to be inserted: ");
                    scanf("%d",&resp);
                    searchAndInsert(hashTable,NUM_OF_LOCATIONS,&elements,resp);
                    break;
            case 3: showHashTable(hashTable,NUM_OF_LOCATIONS);
                    break;
            case 4: return 0;
            default: printf("Invalid value. Try again.\n");
                     break;
        }
    }
    return 0;
}
//------------------------------ initHashTable ------------------------------  
void initHashTable(int* hTbl, int maxIndex, int* elems) {
    // Initializes the locations of the hTbl[] to empty.
    int i;
    for(i=0;i<=maxIndex;i++) {
        hTbl[i] = EMPTY;
    }
    *elems = 0;
    return;
}
//------------------------------ showHashTable ------------------------------  
void showHashTable(int* hTbl, int maxIndex) {
    // prints the contents of the hTbl
    int i;
    for(i=1;i<=maxIndex;i++) {
        printf("hashTable[%d] = %d\t",i,hTbl[i]);
        if((i % 3) == 0) {
            printf("\n");
        }
    }
    return;
}
//------------------------------ searchAndInsert ------------------------------  
void searchAndInsert(int* hTbl, int maxIndex, int* elems, int key) {
    // searches hTbl[] for key. If not found inserts it into the first
    // deleted location or if no deleted locations available into the first
    // empty location.
    int loc = (key % H1) + 1; // An integer from 1 to 21
    int step = (key % H2) + 1; // An integer from 1 to 19
    printf("Trying to insert %d. Initial loc = %d, step = %d.\n",
            key,loc,step);
    int firstDeleted = 0;
    while(hTbl[loc] != EMPTY && hTbl[loc] != key) {
        if(firstDeleted == 0 && hTbl[loc] == DELETED) {
            firstDeleted = loc;
        }
        printf("Collision with %d in hashTable[%d].\n",hTbl[loc],loc);
        loc = loc + step;
        if(loc > maxIndex) loc = loc - maxIndex; // loc is always from 1 to 21
    }
    if(hTbl[loc] == EMPTY) { // The key was not in the hTbl[]
        // Insert the key into the 1st deleted location if available else
        // into this empty slot.
        if(*elems < MAX_NUM_OF_ELEMENTS) { 
            if(firstDeleted != 0) {
                hTbl[firstDeleted] = key;
                printf("Inserting %d into the 1st deleted hashTable[%d]\n",
                        key,firstDeleted);
            } else {
                hTbl[loc] = key;
                printf("Inserting %d into the empty hashTable[%d]\n",
                        key,loc);
            }
            (*elems)++;
        } else {
            printf("%d did not fit into the hashTable[].\n",key);
        }
    } else {
        printf("Not inserted. %d is already in the hashTable[%d].\n",key,loc);
    }
    return;
}
