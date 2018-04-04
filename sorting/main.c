//1.	Design an algorithm for the following to
//a.	Accept data from standard user interface or stored data structure
//b.	Validate the input and store in a data structure
//c.	Sort the data in ascending or descending order using bubble, 
//      insertion and selection sort. Provide user selection for type of sort
//d.	Display the sorted data

#include <stdio.h>
#include <stdlib.h>
#define MAXNUMBERS 100

int main()
{
    void displayNumbers(int* tbl, int elems);
    void selectionSort(int tbl[], int elems, char direction);
    FILE* in;
    in = fopen("numbers.txt","r");
    int num;
    int numbers[MAXNUMBERS];
    int elements = 0;

    while(fscanf(in,"%d",&num) == 1) {
        numbers[elements++] = num;
    }
    printf("The original list of numbers:\n");
    displayNumbers(numbers,elements);
    selectionSort(numbers,elements,'a');

    printf("After ascending selection sort:\n");
    displayNumbers(numbers,elements);

    printf("Hello world!\n");
    return 0;
}
//------------------------------ displayNumbers ------------------------------  
void displayNumbers(int* tbl, int elems) {
    // Display the elements of the array.
    int i;
    printf("\nThe contents of the array are as follows:\n");
    for(i=0;i<elems;i++) {
        printf("%d ",*(tbl+i));
    }
    printf("\n");
    return;
}
//------------------------------ selectionSort ------------------------------  
void selectionSort(int tbl[], int elems, char direction) {
    // This function sorts the elements of the tbl[] into the ascending order
    // ni case the direction ='a'. If the direction is 'd' the elements are
    // sorted into the descending order instead.

    void swap(int *t, int lo, int hi);
    int selectSwapIndex(int* t, int lo, int hi, char dir);
    int i,indx;
    for(i=0;i<elems-1;i++) {
        indx = selectSwapIndex(tbl,i,elems-1,direction);
        swap(tbl,i,indx);
    }
    return;
}
//------------------------------ selectSwapIndex ------------------------------  
int selectSwapIndex(int* t, int lo, int hi, char dir) {
    // When dir == 'a' this function returns the index of the smallest element
    // of t[] in the range of lo - hi for the purposes of sorting the elements 
    // into an ascending order. Otherwise this function returns the index of 
    // the largest element of the array in the range of lo - hi. This is 
    // used when doing a descending sort.

