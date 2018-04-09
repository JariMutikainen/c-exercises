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
    void bubbleSort(int tbl[], int elems, char direction);
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
    printf("\nAfter decending insertion sort:\n");
    displayNumbers(numbers,elements);

    bubbleSort(numbers,elements,'a');
    printf("\nAfter ascending bubble sort:\n");
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
    // in case the direction ='a'. If the direction is 'd' the elements are
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
    int k,h;
    int key;
    for(h=1;h<elems;h++) {
        key = tbl[h];
        k = h - 1; // Start comparing with the previous element.
        while(shiftCondition(k,key,tbl[k])) {
            tbl[k+1] = tbl[k]; // Shift right
            k--;
        }
        // By now the correct place for the key has been found
        tbl[k+1] = key;
    }
    return;
}
//------------------------------ shiftForAscendingSort --------------------  
int shiftForAscendingSort(int k,int key,int currElem) {
    // This function returns 1 if right shifting should be continued, 
    // else it returns 0. For the ascending sort the right shifting
    // must continue as long as thr key (to be inserted) is smaller than 
    // the current element.
    return (k >= 0 && key < currElem);
}
//------------------------------ shiftForDecendingSort --------------------  
int shiftForDecendingSort(int k,int key,int currElem) {
    // This function returns 1 if right shifting should be continued, 
    // else it returns 0. For the decending sort the right shifting
    // must continue as long as thr key (to be inserted) is larger than 
    // the current element.
    return (k >= 0 && key > currElem);
}

//------------------------------ bubbleSort ------------------------------  
void bubbleSort(int tbl[], int elems, char direction) {
    // This function sorts the elements of the tbl[] into the ascending order
    // in case the direction ='a'. If the direction is 'd' the elements are
    // sorted into the descending order instead.
    int swapIsNeeded(int elemI, int elemJ, char dir);
    int i,j,temp;
    for(i=0;i<elems-1;i++) {
        for(j=i+1;j<elems;j++) {
            if(swapIsNeeded(tbl[i],tbl[j],direction)) {
                temp = tbl[i];
                tbl[i] = tbl[j];
                tbl[j] = temp;
            }
        }
    }
    return;
}
//------------------------------ swapIsNeeded ------------------------------  
int swapIsNeeded(int elemI, int elemJ, char dir) {
    // This function return a 1 if the two elements need to be swapped,
    // else it returns a 0.
    // In the case of the ascending sort order (dir == 'a') the smaller
    // element must come first. In the case of a descending sort the larger
    // element must come first.
    if(dir == 'a') { // An ascending sort
        if(elemJ < elemI) {
            return 1;
        } else {
            return 0;
        }
    } else { // A descending sort
        if(elemJ > elemI) {
            return 1;
        } else {
            return 0;
        }
    }
    return -1; // This should never happen
}
