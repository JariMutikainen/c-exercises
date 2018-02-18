/* 2) Write a program that takes an input from a file and read into an array.
 *  Build this array as dynamic array. Find the largest and smallest elements.
 *  Input is a list of names
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNAMELENGTH 40  // Maximum length of the 1st name of a person.

int main()
{
    
    void determineArraySize(FILE* inFile,int* names,int* longestName);

    FILE* inFile;
    char iFileName[] =  
    "H:\\GitHubLocalRepository\\c-exercises\\dynamicArray\\listOfNames.txt";
    int names = 0; // Number of names found in the input file
    int longestName = 0; // Number of characters in the longest name
    inFile = fopen(iFileName,"r"); 
    determineArraySize(inFile,&names,&longestName);
    printf("Names = %d, Longest name = %d",names,longestName);
    fclose(inFile); // Close and re-open to init the read pointer of the file
    inFile = fopen(iFileName,"r"); // back into the begining

    // Allocate memory from the heap for a 2-dimensional array as needed.
    // The elements of the nameTable[] are pointers to char - i.e.
    // pointers to the 1st character of each row (= each name).
    // To avoid some complexity the reservation is (longestName + 1) bytes
    // for all the names. +1 is there to accommodate for the '\0' at the end 
    // of the longestName. I decided not to make the array jagged.
    // The reserved memory is contiguous.
    char **nameTable = (char **) malloc(names * sizeof(char *));
    nameTable[0] = (char *) malloc(names * (longestName+1) * sizeof(char));
    int i;
    for(i=1;i<names;i++) {
        nameTable[i] = nameTable[0] + i * (longestName+1);
    }


    printf("Hello world!\n");
    return 0;
}
//------------------------------ determineArraySize ----------------------------  
void determineArraySize(FILE* inFile,int* names,int* longestName) {
    // This function reads the input file and determines the required size
    // for the dynamic array to accommodate all the names in that file.

    char name[MAXNAMELENGTH];
    while(fscanf(inFile,"%s",name) > 0) {  // fscanf returns a negative at EOF.
        (*names)++; // Increment the number of names in main.
        if(strlen(name) > *longestName) {
            *longestName = strlen(name);  // A new max has been found.
        }
    }
    return;
}
