/* Read input from STDIN. Print your output to STDOUT*/

#include<stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLENGTH 81
int main(int argc, char *a[])
{
    char inString[MAXLENGTH];
    char outString[MAXLENGTH];
    char letters[MAXLENGTH];
    char* pI = NULL; // pointer for traversing inString[]
    char* pL = NULL; // pointer for traversing letters[]
    char* pOut = NULL; // pointer for traversing outString[]
    int i;
    // Initialize outString[] to all 'w'
    for(i=0;i<MAXLENGTH;i++) {
        outString[i] = 'w';
    }
    outString[MAXLENGTH-1] = '\0'; // Just a precaution.


    printf("Enter a string of maximum 80 characters: ");
    scanf("%s",inString);

    pI = inString; // Point initially to the 1st char of inString[]
    pL = letters;  // Point initially to the 1st position of letters[]
    pOut = outString; // Point initially to the 1st position of outString[]
    while(*pI != '\0') {
        if(isalpha(*pI)) {
            *pL++ = *pI; // Pick letter into the letter[]. Move pointer pL
                         // to point at the next unused position in letter[]
        } else { // Non-alphabetic characters of inString[] go to the 
                 //same position in the outString[] array.
            *pOut = *pI;
        }
        // pI and pOut step forward in tandem:
        pI++;
        pOut++;
    }
    // We have reached the end of inString[]. Add termination to outString[]
    // and letters[]
    *pOut = '\0';
    *pL = '\0';

//    printf("inString = %s, outString = %s, letters = %s\n",
//            inString,outString,letters);

    // The non alphabetic characters are already in place in outString.
    // Now we have to fill in the letters from letters[] - but in the reverse
    // order.

    // Set pL to point at the last letter in the letters[]
    pL = letters + strlen(letters) - 1; // Pointer arithmetics
    // Set pOut to point at the 1st character of outString
    pOut = outString;
    // We can set the terminating NUL to outString[], because we know,
    // that the length of it matches the length of the inString[]
    outString[strlen(inString)] = '\0';
    while(*pOut != '\0') {
        if(*pOut == 'w') {
            *pOut = *pL--; // Pick a letter and move BACKWARDS in letters[]
        }
        pOut++;
    }

    

//    printf("inString = %s, outString = %s, letters = %s\n",
//            inString,outString,letters);

    if(strlen(letters) == 0) {
        printf("No reversal possible.\n");
    } else {
        printf("%s\n",outString);
    }

    return 0;
}
