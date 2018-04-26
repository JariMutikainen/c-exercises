/* This program inserts integers into a hash table. In the case of collisions
 * it uses:
 * A. The linear probing
 * B. Quadratic probing
 * C. Double hashing
 * for finding the next vacant slot to be used for the insertion. For each case
 * the contents of the hash table are dispalyed.
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define N 11
#define MAXNUMS (N-2)
#define EMPTY 0

int main()
{
    void clearHashTable(int hTbl[],int maxIndex);
    void printHashTable(int hTbl[],int maxIndex);
    void linearProbingAdd(int hTbl[],int maxIndex, int* elems, int key);
    int hashTable[N+1];
    int nums[] = {10,22,31,4,15,28,17,88,58};
    int i;
    int elementsInHashTable = 0;
    printf("Using the linear probing to solve collisions.\n");
    clearHashTable(hashTable,N);
    for(i=0;i<(sizeof(nums)/sizeof(int));i++) {
        linearProbingAdd(hashTable,N,&elementsInHashTable,nums[i]);
    }
    printHashTable(hashTable,N);
    
    return 0;
}
//------------------------------ clearHashTable ------------------------------  
void clearHashTable(int hTbl[],int maxIndex) {
    int i;
    for(i=0;i<=maxIndex;i++) {
        hTbl[i] = EMPTY; // 0 means 'empty'.
    }
    return;
}
//------------------------------ printHashTable ------------------------------  
void printHashTable(int hTbl[],int maxIndex) {

    int i;
    for(i=1;i<=maxIndex;i++) {
        printf("hashTable[%d] = %d\n",i,hTbl[i]);
    }
    printf("\n");
    return;
}
//------------------------------ linearProbingAdd ------------------------------  
void linearProbingAdd(int hTbl[],int maxIndex, int* elems, int key) {
    // This function inserts key into hTbl[] unless it is already there.
    int loc = key % N + 1; // A number from 1 to N
    //printf("Adding %d initial hash is %d\n",key,loc);
    while(hTbl[loc] != EMPTY && hTbl[loc] != key) {
        loc = loc % N + 1; // Linear probing using the step of 1
    }
    if(hTbl[loc] == EMPTY) {
        if(*elems < MAXNUMS) {
            hTbl[loc] = key;
            (*elems)++;
        } else {
            printf("Unable to add %d. The hashTable is already full.\n",key);
        }
    } else {
        printf("No need to add %d. It is already in the hashTable[].\n",key);
    }
    //printHashTable(hTbl,maxIndex);
    return;
}
