/* This program asks the user for a string of text. It reads the text,
 * converts all the letters to uppercase letters and all spaces to underlines.
 * The purpose of this exercise is to learn to use an array as an argument for
 * a function.
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXLENGTH 80

int main()
{
    void modifyString(char* a);
    char s[MAXLENGTH];
    printf("Enter any string of text. Spaces are allowed. Max length 80.:\n");
    fgets(s,MAXLENGTH,stdin);
    // Kill the line feed at the end of the string.
    s[strlen(s) - 1] = '\0';
    printf("The original s contains: %s.\n",s);
    modifyString(s);
    printf("The modified s contains: %s.\n",s);
    return 0;
}
//------------------------------ modifyString ------------------------------  
void modifyString(char* a) {
    // This function converts all the letters of a to uppercase and all the
    // spaces into underlines.
    int i = 0;
    while(*(a+i) != '\0') {
        if(*(a+i) == ' ') {
            *(a+i) = '_';
        } else {
            *(a+i) = toupper(*(a+i));
        }
        i++;
    }
    // When we get here we are pointing at the terminating '\0' already.
    return;
}
