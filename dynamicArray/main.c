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
    char** allocateMemory(int rows, int columns);
    void populateNameTable(char** tbl,int rows, FILE* inFile);
    void printNameTable(char** tbl,int rows);

    FILE* inFile;
    char iFileName[] =  
    "H:\\GitHubLocalRepository\\c-exercises\\dynamicArray\\listOfNames.txt";
    int names = 0; // Number of names found in the input file
    int longestName = 0; // Number of characters in the longest name
    inFile = fopen(iFileName,"r"); 
    determineArraySize(inFile,&names,&longestName);
    printf("Names = %d, Longest name = %d\n",names,longestName);
    fclose(inFile); // Close and re-open to init the read pointer of the file
    inFile = fopen(iFileName,"r"); // back into the begining

    char** nameTable = allocateMemory(names,longestName+1);
    populateNameTable(nameTable,names,inFile);
    printNameTable(nameTable,names);



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
//------------------------------ allocateMemory ------------------------------  
char** allocateMemory(int rows, int columns) {
    // Allocate memory from the heap for a 2-dimensional array as needed.
    // The elements of the nameTable[] are pointers to char - i.e.
    // pointers to the 1st character of each row (= each name).
    // To avoid some complexity the reservation is (longestName + 1) bytes
    // for all the names. +1 is there to accommodate for the '\0' at the end 
    // of the longestName. I decided not to make the array jagged.
    // The reserved memory is contiguous.
    char **matrix = (char **) malloc(rows * sizeof(char *));
    matrix[0] = (char *) malloc(rows * columns * sizeof(char));
    int i;
    for(i=1;i<rows;i++) {
        matrix[i] = matrix[0] + i * columns;
    }
    return matrix;
}
//------------------------------ populateNameTable --------------------  
void populateNameTable(char** tbl,int rows, FILE* inFile) {
    // This function reads the names from the inFile and writes them into
    // the allocated character arrays in the heap. The pointer to the 1st 
    // char of i:th such character array is tbl[i].
    int r;
    for(r=0;r<rows;r++) {
        fscanf(inFile,"%s",tbl[r]);
    }
    return;
}
//------------------------------ printNameTable --------------------  
void printNameTable(char** tbl,int rows) {
    // This function prints all the names in the nameTable.
    int r;
    for(r=0;r<rows;r++) {
        printf("%s\n",tbl[r]);
    }
    return;
}
