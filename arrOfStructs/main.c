/* The purpose of this exercise is to learn to sort an array of structs.
 * The program sorts an array of temperature data from the coldest day to
 * the warmest. It prints the temperature data before and after sorting.
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#define MAXDAYNAME 20

typedef struct temp_s {
    char dayName[MAXDAYNAME];
    float dayTemp;
} tempData_t;

int main()
{
    void printWeek(tempData_t* pWeek,int elements);
    tempData_t week[7] = {
        { "Monday",     1.7 },
        { "Tuesday",   -2.2 },
        { "Wednesday", -1.1 },
        { "Thursday",   3.0 },
        { "Friday",     0.5 },
        { "Saturday",  -4.4 },
        { "Sunday",     2.0 }
    };
    int i,j;
    tempData_t temp;

    printWeek(week,7);
    // sort the array from the coldest day to the warmest.
    // This is a bubble sort algorithm
    for(i=0;i<6;i++) {
        for(j=i+1;j<7;j++) {
            if(week[j].dayTemp < week[i].dayTemp) {
                //swap
                temp = week[i];
                week[i] = week[j];
                week[j] = temp;
            }
        }
    }

    printf("After the bubble sort:\n");
    printWeek(week,7);
    return 0;
}
//------------------------------ printWeek ------------------------------  
void printWeek(tempData_t* pWeek, int elements) {
    // This function prints the contents of week's temperature data.
    int i;
    for(i=0;i<elements;i++) {
        printf("%10s : %.1f\n",pWeek[i].dayName,pWeek[i].dayTemp);
    }
    return;
}
