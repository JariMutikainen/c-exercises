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

int main(int argc, char *argv[])
{
    FILE *in;
    FILE *out;
    char iFileName[MAX] =  "/h/GitHubLocalRepository/c-exercises/fileIO/";
    char oFileName[MAX] =  "/h/GitHubLocalRepository/c-exercises/fileIO/";
    if(argc != 3) {
        printf("Incorrect number of arguments. Try next time fileIO.exe in.txt out.txt.\n");
        return 1;
    }
    strcat(iFileName,argv[1]); // String concatenation
    strcat(oFileName,argv[2]); // String concatenation

    printf("%s --- %s\n",iFileName,oFileName);
    
    printf("Hello world!\n");
    return 0;
}
