#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSTRING 16


int main()
{
    void push(char* arr, char new, int* top);
    char pop(char* arr, int* top);
    void display(char* arr, int* top);
    char inString[MAXSTRING];
    char charStack[MAXSTRING];
    int  topOfStack = -1; // The index of the top element of the stack
    char *p = NULL; // Pointer to go through the inString character by character.
    printf("Enter a string of max 8 characters: ");
    scanf("%s",inString);
    if(strlen(inString) > 8) {
        printf("Exceeded Limit\n");
        return -1;
    }
    
    // Set p to point at the first character of the inString
    p = inString;
    while(*p != '\0') {
        if(*p == 'Z') {
            push(charStack,'#',&topOfStack);
        } else if(*p == '0') {
            push(charStack,'$',&topOfStack);
        } else if(isalpha(*p) || isdigit(*p)) {
            push(charStack,*p,&topOfStack);
        } else {
            printf("Invalid String\n");
            return -2;
        }
        p++;
    
    }

    // Now we have all the alphabetical characters in the stack.
    // All we need to do is to pop them out one by one to reverse
    // their order.
    //

    //display(charStack,&topOfStack);
    printf("ZZ");
    while(topOfStack >= 0) {
        printf("%c",pop(charStack,&topOfStack));
    }
    printf("0\n");            
    return 0;
}
//------------------------------ push ------------------------------  
void push(char* arr, char new, int* top) {
    // Pushes new into the arr[] and updates top accordingly.
    if(*top == MAXSTRING - 1) {
        printf("Unable to add character. Stack is full.\n");
        return;
    }
    (*top)++;
    arr[*top] = new;
    return;
}
//------------------------------ pop ------------------------------  
char pop(char* arr, int* top) {
    // Pops the top element from the stack and updates top accordingly
    char topElem;
    if(*top == -1) {
        printf("Unable to pop. The stack is empty.\n");
        return 'J';
    }
    topElem = arr[*top];
    (*top)--;
    return topElem;
}
//------------------------------ display ------------------------------  
void display(char* arr, int* top) {
    // Disåplays the contents of the stack.
    int i;
    for(i=0;i<= *top;i++) {
        printf("charStack[%d] = %c\n",i,arr[i]);
    }
    return;
}


