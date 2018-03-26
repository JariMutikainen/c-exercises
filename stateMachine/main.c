/* This program implements a state machine and simulates the operation
 * of it. The machine has the following 4 states: S1,S2,S3 and S2B.
 * The machine has the following 5 inputs: e1,e2,e3,e4 and e5.
 * The state transition diagram cannot be presented here, but it can be
 * figured out by reading the code. For the simulation purposes the idea is
 * to take advantage of a random number generator for producing the input
 * events.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIMSTEPS 20

typedef struct inputs_s{
    int e1;
    int e2;
    int e3;
    int e4;
    int e5;
} inputs_t;

typedef enum { S1,S2,S2B,S3} state_t;

int main()
{
    void setInputs(inputs_t* iV);
    void updateState(inputs_t* iV, state_t* s);
    inputs_t iVector;
    state_t state = S1;
    int i;

    srand(time(0)); // Seed the random number generator
    for(i=0;i<SIMSTEPS;i++) {
        setInputs(&iVector);
        updateState(&iVector,&state);
    }


    return 0;
}
//------------------------------ setInputs ------------------------------  
void setInputs(inputs_t* iV) {
    // This function takes advantage of a random number generator to set
    // arbitrary values for the state machine inputs.

    int randomNumber;
    randomNumber = rand() % 32; // A number in the range of 0-31
    iV->e1 = randomNumber & 0x00000001;
    iV->e2 = (randomNumber >> 1) & 0x00000001;
    iV->e3 = (randomNumber >> 2) & 0x00000001;
    iV->e4 = (randomNumber >> 3) & 0x00000001;
    iV->e5 = (randomNumber >> 4) & 0x00000001;


    return;
}
//------------------------------ updateState ------------------------------  
void updateState(inputs_t* iV, state_t* s) {
    // This function updates the state of the state machine based on the 
    // current state and the inputs.
    
    char *stateNames[4] = {" S1"," S2","SB2"," S3"};
    state_t oldState = *s; 
    state_t newState = oldState; 

    printf("Inputs: e[5:1]=%1d%1d%1d%1d%1d ",iV->e5,iV->e4,iV->e3,iV->e2,iV->e1);
    printf("Old state: %s ",stateNames[(int)(oldState)]);

    switch(oldState) {
        case S1 :
            if(iV->e1) newState = S2;
            else if(iV->e2) newState = S2B;
            break;
        case S2:
            if(iV->e2) newState = S3;
            else if(iV->e4) newState = S1;
            break;
        case S3 :
            if(iV->e3) newState = S2;
            break;
        case S2B :
            if(iV->e1) newState = S3;
            break;
    }
    printf("New state : %s\n",stateNames[(int)(newState)]);
    *s = newState;
   return;
}
