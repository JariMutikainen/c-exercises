/* This exercise is about using a pointer to char for traversing an array
 * of characters.
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[] = "A brown fox jumped over a fence.";
    char* p = text;
    int length = strlen(text);
    int i = 0;
    for(i=0;i<length;i++) {
        putchar(*(p+i));
    }
    putchar('\n');

    printf("Hello world!\n");
    return 0;
}
