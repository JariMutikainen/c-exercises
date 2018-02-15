// The assignment:
// 1) Write a C program to achieve the following
// a. Get two file names command line arguments
// b. First file is input file and second is output file
// c. Read input lines by line
// d. Tokenize the line to get tokens (separated by comma(,), space, semicolon(;) etc)
// e. Write line, no. of tokens and the tokens in o/p file
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Max length of the full path name of a given file
#define MAXLINELENGTH 81 // Maximum length of one line in the text file +1 for \0.

int main(int argc, char *argv[])
{
    void tokenizeLine(char* pLine, FILE* ofile);
    FILE *in;
    FILE *out;
    char iFileName[MAX] =  "H:\\GitHubLocalRepository\\c-exercises\\fileIO\\";
    char oFileName[MAX] =  "H:\\GitHubLocalRepository\\c-exercises\\fileIO\\";
    char *completeLine; // A line of text with '\n' '\0' at the end.
    if(argc != 3) {
        printf("Incorrect number of arguments. Try next time fileIO.exe in.txt out.txt.\n");
        return 1;
    }
    strcat(iFileName,argv[1]); // String concatenation
    strcat(oFileName,argv[2]); // String concatenation

    printf("%s --- %s\n",iFileName,oFileName);
    in = fopen(iFileName,"r");
    if(in == NULL) {
        printf("Failed to open %s.\n",iFileName);
    }
    out = fopen(oFileName,"w");
    if(out == NULL) {
        printf("Failed to open %s.\n",oFileName);
    }

    completeLine = (char *) malloc(MAXLINELENGTH * sizeof(char));
    if(completeLine == NULL) {
        printf("malloc() failed to allocate memory for completeLine.\n");
        exit(1);
    }
    // fgets() returns NULL at the end of file.
    while(fgets(completeLine,MAXLINELENGTH,in)) {
        fprintf(out, "%s",completeLine);
        printf("%s",completeLine);
        tokenizeLine(completeLine,out);

    }
    
    printf("Hello world!\n");
    fclose(in);
    fclose(out);
    return 0;
}
//------------------------------ tokenizeLine ------------------------------  
void tokenizeLine(char* pLine, FILE* ofile) {
    /* This function splits the input line into separate tokens (= words)
     * using the non-alphanumeric characters as token separators. It prints
     * these tokens into the output file ofile.
     */
    char *p = pLine; // Point at the 1st character of the line.
    int tokens = 0; // counts the number of the words per line.

    return;
}
