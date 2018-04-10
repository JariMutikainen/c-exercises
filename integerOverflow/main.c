/*This program contains an experiment of integer overflow.
 * In this particular case the outcome of the integer overflow differed based
 * on the compiler optimisation setting.*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
    int x = INT_MAX;
    printf("x = %d\n",x);
    if(x + 1 < x) {
        printf("I thought we would come here, x + 1 is NEGATIVE due to integer overflow.\n");
    } else {
        printf("For some reason we came here ?!?\n");
    }
    x += 1;
    printf("x += 1 is %d\n",x);
     return 0;
}
