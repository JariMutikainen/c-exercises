/* This program converts the boiling point temperature of water 
 * in Celcius (= 100 degrees) and the freezing point of water in Celcius 
 * (0 degrees) into Farenheit and Kelvins. Finally it prints out the converted
 * values.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float cToF(float c);
    float cToK(float c);
    float cFreezing = 0.0;
    float cBoiling = 100.0;
    
    printf("The freezing point of water is %.1f degrees Celcius.\n",cFreezing);
    printf("In Farenheit this is %.1f degrees.\n",cToF(cFreezing));
    printf("In Kelvins this is %.1f degrees.\n",cToK(cFreezing));


    printf("The boiling point of water is %.1f degrees Celcius.\n",cBoiling);
    printf("In Farenheit this is %.1f degrees.\n",cToF(cBoiling));
    printf("In Kelvins this is %.1f degrees.\n",cToK(cBoiling));

    return 0;
}
//------------------------------ cToF ------------------------------  
float cToF(float c) {
    // Convert degrees Celcius into degrees Farenheit.
    return c*9.0/5.0 + 32.0;
}
//------------------------------ cToK ------------------------------  
float cToK(float c) {
    // Convert degrees Celcius into degrees Kelvins.
    return c + 273.0;
}
