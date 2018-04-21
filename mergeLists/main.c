/* This program reads two text files, which contain sorted lists of integers
 * each. The task is to merge these two lists into one sorted list and write
 * the resulting list into an output text file.
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 40


int main()
{
    FILE *pAfile, *pBfile, *pCfile;
    int arrA[MAXNUM],arrB[MAXNUM],arrC[2 * MAXNUM];
    int elemsA = 0,elemsB = 0,elemsC = 0;

    pAfile = fopen("listA.txt","r");
    if(NULL == pAfile) {
        printf("Unable to open listA.txt.\n");
        exit(1);
    }
    pBfile = fopen("listB.txt","r");
    if(NULL == pBfile) {
        printf("Unable to open listB.txt.\n");
        exit(1);
    }
    pCfile = fopen("listC.txt","w");
    if(NULL == pCfile) {
        printf("Unable to open listC.txt.\n");
        exit(1);
    }
    int num;
    while(fscanf(pAfile,"%d",&num) == 1) {
        arrA[elemsA++] = num;
        printf("%d ",num);
    }
    printf("\n");
    while(fscanf(pBfile,"%d",&num) == 1) {
        arrB[elemsB++] = num;
        printf("%d ",num);
    }
    printf("\n");
    int *pA = arrA;
    int *pB = arrB;
    int *pC = arrC;

    // While there are unpicked elements in both arrays:
    while((pA < arrA + elemsA) && (pB < arrB +elemsB)) {
        if(*pA < *pB) { // We pick the smaller of the two.
            *pC++ = *pA++;
        } else {
            *pC++ = *pB++;
        }

    }
    // At this point we have exhausted either listA[] or listB[]
    if(pA == arrA + elemsA) { // If listA[] is already 'empty'
        while(pB < arrB + elemsB) {
            *pC++ = *pB++;
        }
    } else { // In this case listB[] went empty first.
        while(pA < arrA + elemsA) {
            *pC++ = *pA++;
        }
    }

    // Let's see what we have accumulated into arrC[] by now
    pC = arrC;
    elemsC = elemsA + elemsB;
    while(pC < arrC + elemsC) {
        printf("%d ",*pC);
        fprintf(pCfile,"%d ",*pC);
        pC++;
    }
    printf("\n");
    fprintf(pCfile,"\n");





    fclose(pAfile);fclose(pBfile);fclose(pCfile);
    
    return 0;
}
