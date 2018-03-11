/* This program asks for a string. It prints all the letters of the given
 * string in the alphabetic order - all letters lower case.
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLENGTH 80

int main()
{
    char s[MAXLENGTH];
    printf("Enter any string of text. Spaces are allowed. Max length 80.:\n");
    fgets(s,MAXLENGTH,stdin);
    // Kill the line feed at the end of the string.
    s[strlen(s) - 1] = '\0';
    int i = 0, j = 0;
    // Remove all the non-alphanumeric characters and make everything lower case.
    printf("The original s contains: %s.\n",s);
    while(s[i] != '\0') {
        if(isalpha(s[i])) {
            s[j++] = tolower(s[i]);
        }
        i++;
    }
    s[j] = '\0';

    printf("The trimmed s contains: %s.\n",s);
    char temp;
    int length = strlen(s);
    // Bubble sort s to put all the characters into the alphanumeric order.
    for(i=0;i<length-1;i++) {
        for(j=i+1;j<length;j++) {
            if(s[j] < s[i]) { // swap
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
    printf("The sorted s contains: %s.\n",s);

    return 0;
}
