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
    void insertionSort(int tbl[], int elems, char direction);
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
    printf("\nAfter ascending selection sort:\n");
    displayNumbers(numbers,elements);

    insertionSort(numbers,elements,'d');
    printf("\nAfter decending selection sort:\n");
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

    int (*selectSwapIndex)(int *t, int lo, int hi); // A function pointer.
    void swap(int *t, int lo, int hi);
    int selectSmallest(int* t, int lo, int hi);
    int selectLargest(int* t, int lo, int hi);
    int i,indx;
    if(direction == 'a') { 
        // For the ascending sorting we need to find the index of the smallest
        // unsorted element.
        selectSwapIndex = selectSmallest;
    } else {

        // For the decending sorting we need to find the index of the largest
        // unsorted element.
        selectSwapIndex = selectLargest;
    }
    for(i=0;i<elems-1;i++) {
        indx = selectSwapIndex(tbl,i,elems-1);
        swap(tbl,i,indx);
    }
    return;
}
//------------------------------ selectSmallest ------------------------------  
int selectSmallest(int* t, int lo, int hi) {
    // This function returns the index of the smallest element
    // of t[] in the range of lo - hi for the purposes of sorting the elements 
    // into an ascending order.
    int smallest,k;
    smallest = lo;
    for(k=lo+1;k<=hi;k++) {
        if(t[k] < t[smallest]) smallest = k; // We found a new smallest
    }
    return smallest;
}
//------------------------------ selectLargest  ------------------------------  
int selectLargest(int* t, int lo, int hi) {
    // This function returns the index of the largest element
    // of t[] in the range of lo - hi for the purposes of sorting the elements 
    // into an decending order.
    int largest,k;
    largest = lo;
    for(k=lo+1;k<=hi;k++) {
        if(t[k] > t[largest]) largest = k; // We found a new largest
    }
    return largest;
}
//------------------------------ swap ------------------------------  
void swap(int *t, int lo, int hi) {
    // Swap the two elements of the array.
    int temp;
    temp = *(t+lo);
    *(t+lo) = *(t+hi);
    *(t+hi) = temp;
}
//------------------------------ insertionSort ------------------------------  
void insertionSort(int tbl[], int elems, char direction) {
    // This function sorts the elements of the tbl[] into the ascending order
    // ni case the direction ='a'. If the direction is 'd' the elements are
    // sorted into the descending order instead.

    int (*shiftCondition)(int k,int key,int currElem); // A function pointer
    int shiftForAscendingSort(int k,int key,int currElem);
    int shiftForDecendingSort(int k,int key,int currElem);
    if(direction == 'a') { 
        // For the ascending sort we need to keep shuffling key left
        // until it is smaller than the current element.
        shiftCondition = shiftForAscendingSort;
    } else {
        // For the decending sort we need to keep shuffling key left
        // until it is larger than the current element.
        shiftCondition = shiftForDecendingSort;
    }

