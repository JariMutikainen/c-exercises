/* The purpose of this exercise is to learn to pass a struct to a function as
 * an argument. The user inputs his name and age, and then the program prints 
 * these pieces of information on the screen.
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAXNAME 30

typedef struct data_s {
    char name[MAXNAME];
    int age;
} data_t;

int main()
{
    void fillData(data_t* p);
    void displayData(data_t* p);
    data_t* pData = (data_t*) malloc(sizeof(data_t));
    fillData(pData);
    displayData(pData);
    return 0;
}
//------------------------------ fillData ------------------------------  
void fillData(data_t* p) {
    // This function fills in the data fields of the struct.
    char name[MAXNAME];
    printf("Enter name: ");
    fgets(name,MAXNAME,stdin);
    // Kill the line feed at the end of the string.
    name[strlen(name) - 1] = '\0';
    strcpy(p->name,name);
    printf("Enter age: ");
    scanf("%d",&(p->age));
    return;
}
//------------------------------ displayData ------------------------------  
void displayData(data_t* p) {
    // This function displays the contents of the data
    printf("The name is: %s.\n",p->name);
    printf("The age is: %d.\n",p->age);
    return;
}

