/* 5) Write a C program to achieve the following
*    a. Read the name of one input file and 1 output file through command line.
*    b. Read all the words from the input file, remove duplicates and then 
*       store the words in the output file one on each line.
*    c. Please think of good method to remove duplicates.
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXWORDS 2000
#define MAXFILENAME 40
#define MAXWORD 20

int main(int argc, char *argv[])
{
    int notSeenBefore(char newWord[], char** table, int elems);
    void addNewWord(char newWord[],char** table, int* pElems);
    char* knownWords[MAXWORDS];
    int elements = 0,i;
    char iFile[MAXFILENAME],oFile[MAXFILENAME];
    char word[MAXWORD];
    FILE* in;
    FILE* out;

    if(argc != 3) {
        printf("Incorrect number of arguments. Must be cmd <infile> <outfile>\n");
        return 1;
    } else {
        strcpy(iFile,argv[1]);
        strcpy(oFile,argv[2]);
    }

    in = fopen(iFile,"r");
    if(in == NULL) {
        printf("Unable to open file %s.\n",iFile);
    }
    out = fopen(oFile,"w");
    if(out == NULL) {
        printf("Unable to open file %s.\n",oFile);
    }

    while(fscanf(in,"%s",word) == 1) {
        if(notSeenBefore(word,knownWords,elements)) {
            addNewWord(word,knownWords,&elements);
            printf("%s\n",word);
            fprintf(out,"%s\n",word);
        }
    }
    printf("The contents of the knownWords is as follows:\n");
    for(i=0;i<elements;i++) {
        printf("knownWords[%d] = %s\n",i,knownWords[i]);
    }
    
    fclose(in);
    fclose(out);

    return 0;
}
//------------------------------ notSeenBefore ------------------------------  
int notSeenBefore(char newWord[], char** table, int elems) {
    // This function returns 1 if word has not been seen before. Otherwise
    // it returns 0.
    int i;
    if(elems == 0) return 1;  // An empty table
    for(i=0;i<elems;i++) {
        if(strcmp(*(table + i),newWord) == 0) { // strcmp returns 0 when match.
        //if(strcmp(table[i],newWord) == 0) { // strcmp returns 0 when match.
            printf("%s was already known.\n",newWord);
            return 0;
        }
    }
    return 1;
}

//------------------------------ addNewWord ------------------------------  
void addNewWord(char newWord[],char** table, int* pElems) {
    // This function adds a new word into the table of the knownWords.
    char* pNew;
    pNew = (char*) malloc(strlen(newWord) + 1); // An extra space for the '\0'
    if(pNew == NULL) {
        printf("malloc failed. Investigate.\n");
        return;
    }

    strcpy(pNew,newWord);
    *(table + *pElems) = pNew;
    //table[*pElems] = pNew;
    (*pElems)++;

    return;
}
