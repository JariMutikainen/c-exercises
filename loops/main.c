/* This program prints bars on the screen. User gives the number of bars
 * and the length of a bar is a random number between 1 and MAXLENGTH inclusive.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAXLENGTH 50

int main()
{
    int numberOfBars;
    void printABar(void);

    printf("Enter the number of bars. Min 1, max ?: ");
    scanf("%d",&numberOfBars);
    int i;
    srand(time(0));
    for(i=0;i<numberOfBars;i++) {
        printABar();
    }



    printf("Hello world!\n");
    return 0;
}
//------------------------------ printABar ------------------------------  
void printABar(void) {
    // This function prints a random number of '*':s on a single line.
    int myRandomNumber(int min, int max);
    int j;
    int barLength = myRandomNumber(1,MAXLENGTH);
    for(j=0;j<barLength;j++) {
        putchar('*');
    }
    printf("\n");
    return;
}
//------------------------------ myRandomNumber ------------------------------  
int myRandomNumber(int min, int max) {
    // This function generates one random number between 1-MAXLENGTH inclusive.
    int offset = rand() / (RAND_MAX + 1.0) * (max - min + 1);
    return min + offset;
}
