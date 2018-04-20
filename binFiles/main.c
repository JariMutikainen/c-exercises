/* This program uses a random number generator to generate 20 random numbers.
 * The random numbers are stored into a binary file. The contents of the binary
 * file are read into the memory and sorted into the ascending order. The
 * sorted numbers are written back into the binary file. The contents of the
 * binary file are read into the memory  one more time and displayed to 
 * verify, that they are indeed in the correct order.
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUMBERS 20

int main()
{
    void display(int* arr, int elems);
    int compare(const void* a, const void* b) {
        return ( *(int*)a - *(int*)b);
    }
    int numArray[NUMBERS] = {0};
    int i;
    FILE* binFile;
    binFile = fopen("binFile.bit", "wb"); // 'write', 'binary'
    if(NULL == binFile) {
        printf("\nFailed to open 'binFile.bin'.\n");
        exit(1);
    }

    srand(time(0)); // Seed the random number generator using system time.
    for(i=0;i<NUMBERS;i++) {
        numArray[i] = rand() % 100; // A random number in the range of 0-99.
    }
    printf("\nAfter the random number generation:\n");
    display(numArray,NUMBERS);

    // Write the contents of numArray[] into the external file in the binary
    // format. The first integer in the file is the number of the numbers
    // stored. In this case that would be 20.

    // First the number of elements:
    int numOfElements = NUMBERS;
    fwrite(&numOfElements,sizeof(int),1,binFile);
    // Then write the contents of numArray[]
    fwrite(numArray,sizeof(int),NUMBERS,binFile);

    fclose(binFile);
    binFile = NULL;

    // Let's clear the numOfElements and numArray[]
    for(i=0;i<numOfElements;i++) {
        numArray[i] = 0;
    }
    printf("\nNumbers stored into binFile.bit. Clear and display internals.\n");
    display(numArray,NUMBERS);
    numOfElements = 0;
    // Now read the values from the external binary file.
    binFile = fopen("binFile.bit", "rb+"); // 'read+write', 'binary'
    if(NULL == binFile) {
        printf("Failed to open 'binFile.bin'.\n");
        exit(2);
    }
    // First the number of elements:
    fread(&numOfElements,sizeof(int),1,binFile);
    // Then the contents of numArray[]
    fread(numArray,sizeof(int),numOfElements,binFile);
    printf("\nInternals after fetcing the contents from binFile.bit.\n");
    display(numArray,numOfElements);
    qsort(numArray,numOfElements,sizeof(int),compare);
    printf("\nInternals after qsort.\n");
    display(numArray,numOfElements);

    // Assume, that the numOfElements is already in the first position of
    // the binary file. Since it has not changed, there is no need to
    // overwrite it. Let's place the file pointer to point at the location
    // AFTER the first interger.
    fseek(binFile,(long)sizeof(int),SEEK_SET);
    // Overwrite the elements of numArray[] in the binary file.
    fwrite(numArray,sizeof(int),numOfElements,binFile);
    fclose(binFile);
    binFile = NULL;

    // Clear the contents of numArray[] and numOfElements
    for(i=0;i<numOfElements;i++) {
        numArray[i] = 0;
    }
    printf("\nSorted numbers were stored into binFile.bit. Internals after clear.\n");
    display(numArray,NUMBERS);
    numOfElements = 0;

    // Now read the values from the external binary file.
    binFile = fopen("binFile.bit", "rb"); // 'read', 'binary'
    if(NULL == binFile) {
        printf("Failed to open 'binFile.bin'.\n");
        exit(2);
    }
    // First the number of elements:
    fread(&numOfElements,sizeof(int),1,binFile);
    // Then the contents of numArray[]
    fread(numArray,sizeof(int),numOfElements,binFile);
    printf("\nInternals after having fetched them from the binFile.bit.\n");
    display(numArray,numOfElements);

    fclose(binFile);
    binFile = NULL;

    return 0;
}
//------------------------------ display ------------------------------   
void display(int* arr, int elems) {
    // Display the contents of arr[].
    int i;
    for(i=0;i<elems;i++) {
        printf("%d ",*(arr + i));
    }
    printf("\n");
    return;
}
