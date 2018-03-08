/* This program contains several coding 'challenges' of a c-language course.
 * Since there are many exercises in this one file the file is quite messy.
 * I don't mind though.
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
 *
 * This program asks for an integer, stores it and prints it formatted as a
 * floating point number with the accuracy of one decimal.
 *
 * This program has a function, that returns an int array. The array contains 
 * the values 2,3,5,7 and 11. Main displays those values.
 *
 */
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{
    int *createIntArray(int* elements); // Prototype
    float fVal;
    int iVal;
    int elems;
    int *intArray = createIntArray(&elems);
    int e;

    printf("There are %d elements in the intArray. They are as follows:\n",elems);
    for(e=0;e<elems;e++) {
        printf("intArray[%d] = %d\n",e,intArray[e]);
    }
    
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
    printf("The number %d in the floating point format is %.1f.\n",iVal,(float)iVal);
    return 0;
}
//------------------------------ createIntArray ------------------------------  
int *createIntArray(int* elements) {
    // This function creates an integer array and returns the pointer to
    // the 1st element of it. Notice, that the local array must be defined as
    // static to avoid loosing the contents of the array when returning
    // into the main.
    static int staticArray[] = {2,3,5,7,11};
    *elements = sizeof(staticArray) / sizeof(int);

    return staticArray;
}
