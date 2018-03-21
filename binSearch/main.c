/* 2.	Design an algorithm with a user interface to search a pattern in 
 * a data collected from the standard user interface.
* a.	Collect and intialize the data stream from standard user interface 
*       and store in a data structure or from stored data structure
* b.	Accept search data pattern from standard user interface.
* c.	Search the occurrence of data pattern in the stored data stream.
* d.	Output the result – found/not found.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXWORDS 1000
#define MAXWORD 20



int binarySearch(int lo, int hi, char key[], char** tbl);

int main()
{
    void populateWords(int* elems, char** table);
    void printWords(int elems, char** tbl);
    char* words[MAXWORDS];
    int elements = 0;

    populateWords(&elements,words);
    printWords(elements,words);

    return 0;
}
//------------------------------ populateWords ------------------------------  
void populateWords(int* elems, char** table) {
    // This function reads the contents of the input.txt, converts all the 
    // found words into lower case and remove all the punctuation. The found
    // words are stored into the words[] of main in the alphaebtical order.

    void insertInPlace(char* pWord, int* elems, char** tbl);
    FILE* in;
    char word[MAXWORD];
    char* pWord = NULL;
    char* p = NULL;
    in = fopen("input.txt","r");
    while(fscanf(in,"%s",word) == 1) {
        // Remove the punctuation and make everything lower case.
        p = word;
        while(*p != '\0') {
            if(isalpha(*p)) {
                *p = tolower(*p);
            } else {
                *p = '\0';
            }
            p++;
        }
        printf("%s\n",word);
        // Add the new words into the table
        pWord = (char *) malloc(strlen(word) + 1); // '\0' at the end.
        strcpy(pWord,word);
        if(*elems == 0) { // This will be the 1st element of the table
            table[*elems] = pWord;
            (*elems)++;
        } else if(*elems == 1) { // This will be the 2nd element
            if(strcmp(table[0],pWord) < 0) { // pWord comes after
                table[1] = pWord;
            } else { // pWord becomes the new 1st
                table[1] = table[0];
                table[0] = pWord;
            }
            (*elems)++;
        } else {
            if(binarySearch(0,*elems,word,table) == -1) { // A new word
                //insertInPlace(pWord,elems,table);
            }
        }
    }
    return;
}




//------------------------------ binarySearch ------------------------------  
int binarySearch(int lo, int hi, char key[], char** tbl ) {
    // Search for key from tbl[lo] to tbl[hi]
    // if found return its' location else return -1

    while(lo <= hi) {
        int mid = (lo + hi) / 2;
        int cmp = strcmp(key, tbl[mid]);
        if(cmp == 0) return mid; // found
        if(cmp < 0) hi = mid - 1;
        else lo = mid + 1;
    }
    return -1; // lo and hi have crossed. Key was not found.
}
//------------------------------ printWords ------------------------------  
void printWords(int elems, char** tbl) {
    // This function prints the contents of the tbl[]
    int i;
    for(i=0;i<elems; i++) {
        printf("words[%d] = %s\n",i,tbl[i]);
    }
    return;
}
//------------------------------ insertInPlace ------------------------------  
void insertInPlace(char* pWord, int* elems, char** tbl) {
    // This function inserts the newWord into the tbl[] so, that after the 
    // insertion the tbl[] remains still in the aplhabetical order.

    int k = *elems - 1;
    while(k >= 0 && strcmp(pWord,tbl[k]) < 0) { // pWord must come before tbl[k]
        tbl[k+1] = tbl[k];
        k--;
    }
    tbl[k+1] = pWord;
    (*elems)++;
    return;
}
