/* This program asks user for a value. It multiplies the value by 5 and displays
 * the result. Then it multiplies the resulting value by 3 and again it displays
 * the result.
 *
 * Then the program asks for a positive integer. It uses the ternary operator
 * for deciding whether the given integer is even or odd.
 */
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float fVal;
    int iVal;
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
