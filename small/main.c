/* This program contains several coding 'challenges' of a c-language course.
 *
 * This program asks user for a value. It multiplies the value by 5 and displays
 * the result. Then it multiplies the resulting value by 3 and again it displays
 * the result.
 *
 * Then the program asks for a positive integer. It uses the ternary operator
 * for deciding whether the given integer is even or odd.
 *
 * This program also expects to get one command line argument. It doesn't matter
 * what that argument is. If it is not there the program quits and prints an 
 * error message.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    float fVal;
    int iVal;
    if(argc != 2) {
        printf("Incorrect number of arguments. Must be exectly one.\n");
        return -1;
    } else {
        printf("The input argument is: %s.\n",*(argv+1));
        printf("The character 3 of the argument string should be 's'. It is %c.\n",
                *(*(argv+1) + 3));
    }

    printf("Enter a floating point value: ");
    scanf("%f",&fVal);
    printf("%.3f x 5.0 = %.3f.\n",fVal,5.0*fVal);
    fVal *= 5.0;
    printf("%.3f / 3.0 = %.3f.\n",fVal,fVal/3.0);
    printf("Enter a positive integer: ");
    scanf("%d",&iVal);
    printf("%d is %s number.\n",iVal,(iVal%2) ? "an odd" : "an even");
    return 0;
}
