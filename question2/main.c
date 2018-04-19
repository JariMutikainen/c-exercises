#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING 81
#define ASCII_CHARACTERS 128

int main()
{
    int asciiTbl[ASCII_CHARACTERS] = {0};
    char instring[MAX_STRING];
    char* p = NULL;
    int i;
    printf("Enter string: ");
    scanf("%s",instring);
    
    p = instring;
    // Go through all the characters of the instring and keep track of their
    // occurences in the asciiTbl[]. The character itself is used as the index
    // to this array.
    while(*p != '\0') {
        (asciiTbl[(int)(*p)])++;
        p++;
    }

    for(i=0;i<ASCII_CHARACTERS;i++) {
        if((i>= (int)'a' && i<= (int)'z') ||  (i>= (int)'A' && i<= (int)'Z')) {
                if(asciiTbl[i] != 0) {
                    printf("%c%d",(char)i,asciiTbl[i]);
                }
        }
    }
    printf("\n");
        


    return 0;
}
