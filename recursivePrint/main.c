/* This program aska the user for two integers. Then it prints all the numbers
 * between those integers (inclusing the entered values).
 *
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    void printRange(int min, int max);
    int min,max;
    printf("Enter two integers (first min then max) separated by white space: ");
    scanf("%d %d",&min,&max);
    printRange(min,max);       // The call to the recursive function.
    printf("Hello world!\n");
    return 0;
}
//------------------------------ printRange ------------------------------  
void printRange(int min, int max) {
    // This function prints all the numbers between min and max recursively.

    static int cnt = 0;
    printf("Iteration count = %d -> %d\n",++cnt,min);
    if(min == max) {
        return;
    } else {
        printRange(min+1,max);
    }
    return;
}
