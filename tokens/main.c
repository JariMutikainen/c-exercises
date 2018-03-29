#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLENGTH 81
#define MAXNUMBERS 80
#define MAXDIGITS 10

int main()
{
    char inString[MAXLENGTH];
    int numbers[MAXNUMBERS];
    int tokens = 0; // Total number of tokens found
    int temp;
    int j;

    int getNextNumber(char* string, int firstCall);
    void bubbleSort(int arr[],int elements);

    gets(inString);
    // Strip the '\n' at the end of the inString[]
    inString[strlen(inString)] = '\0';
    printf("%s\n",inString);
    numbers[tokens++] = getNextNumber(inString,1);
    temp = getNextNumber(inString,0);
    while(temp != -1) {
        numbers[tokens++] = temp;
        temp = getNextNumber(inString,0);
    }

//    for(j=0;j<tokens;j++) {
//        printf("numbers[%d] = %d\n",j,numbers[j]);
//    }
    // Let's sort the numbers[] now
    bubbleSort(numbers,tokens);
//    printf("After sorting the numbers are as follows:\n");
//    for(j=0;j<tokens;j++) {
//        printf("numbers[%d] = %d\n",j,numbers[j]);
//    }
    for(j=0;j<tokens;j++) {
        printf("%d ",numbers[j]);
    }
    printf("\n");
    




    return 0;
}
//------------------------------ getNextNumber ------------------------------  
int getNextNumber(char* string, int firstCall) {
    // This function returns the next positive integer it finds in the 
    // input string. It returns -1 when it has reached the end of the string.

    static char* p;
    char digits[MAXDIGITS] = "";
    int i = 0; // index to digits[]
    int foundNumber;
    if(firstCall) p = string; // Make p point at the 1st char at the 1st call.


    // skip non-numbers
    while((isdigit(*p) == 0) && (*p != '\0')) p++;

    // p points at the 1st digit of the next numerical token now.
    while((isdigit(*p)) && (*p != '\0') ) {
        digits[i++] = *p++;
    }
    // p points at the 1st non-digit now after the collected number
    // i points at the 1st unused element in digits[]
    digits[i] = '\0';
    
    if(i == 0) {
        foundNumber = -1; // No digits were found
    } else {
        foundNumber = atoi(digits);
    }
    
    //printf("Found %d, p is now %p.\n",foundNumber,p);
    return foundNumber;
}
//------------------------------ bubbleSort ------------------------------  
void bubbleSort(int arr[],int elements) {
    // Sorts the array in the ascending order

    int i,j;
    int temp;
    for(i=0;i<elements-1;i++) {
        for(j=i+1;j<elements;j++) {
            if(arr[j] < arr[i]) { // swap
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}

