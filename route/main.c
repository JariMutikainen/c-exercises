/* This program compares the different routes from the home to the office based on
 * the duration and/or cost. The 3 routes are available are as follows:
 *
 * Route A: Train, hourly, $50, 30minutes
 * Route B: Bus to middle station 20minutes, every 15 minutes + 
 *          Train to destination 10 minutes every 15 minutes. $25+$30.
 * Route D: Walk, anytime, 120 minutes. $0.
 *
 * */
#include <stdio.h>
#include <stdlib.h>

int main()
{

    void routeA(int startTime, int* delay, int* cost);
    void routeB(int startTime, int* delay, int* cost);
    int selectRoute(int aD, int bD, int dD);
    int quickest;
    int aDelay,aCost;
    int bDelay,bCost;
    int dDelay = 120;
    int i ;

    for(i = 1; i < 60; i+=2) {
        routeA(i,&aDelay,&aCost);
        routeB(i,&bDelay,&bCost);
        printf("Route D, Walk. Start time %d minutes over hour ",i);
        printf("-> duration %d minutes, no cost.\n",dDelay);
        quickest = selectRoute(aDelay,bDelay,dDelay);
        if(quickest == 1) {
            printf("You should take the route A = train.\n\n");
        } else if(quickest == 2) {
            printf("You should take the route B = bus + train.\n\n");
        } else {
            printf("Go ahead and walk to the office taking the route D.\n\n");
        }
    }
        



    return 0;
}
//------------------------------ routeA ------------------------------  
void routeA(int startTime, int* delay, int* cost) {
    // This function calculates the total travelling time and cost based
    // on using the route A and starting the commuting startTime minutes
    // after the hour.

    int initialWait = 60 - startTime;
    *delay = initialWait + 30;
    *cost = 50;
    printf("route A. Start time %d minutes after hour ",startTime);
    printf("-> total duration = %d minutes, cost = $%d.\n",*delay,*cost);
    return;
}
//------------------------------ routeB ------------------------------  
void routeB(int startTime, int* delay, int* cost) {
    // This function calculates the total travelling time and cost based
    // on using the route B and starting the commuting startTime minutes
    // after the hour.

    int initialWait;
    if(startTime <= 15) initialWait = 15 - startTime; 
    else if(startTime <= 30) initialWait = 30 - startTime; 
    else if(startTime <= 45) initialWait = 45 - startTime; 
    else initialWait = 60 - startTime; 

    int arrivalAtMidpoint = startTime + initialWait + 20;
    if(arrivalAtMidpoint >= 60) {
        arrivalAtMidpoint -= 60; // substract 1 full hour
    }

    int trainWait;


    if(arrivalAtMidpoint <= 15) trainWait = 15 - arrivalAtMidpoint; 
    else if(arrivalAtMidpoint <= 30) trainWait = 30 - arrivalAtMidpoint; 
    else if(arrivalAtMidpoint <= 45) trainWait = 45 - arrivalAtMidpoint; 
    else trainWait = 60 - arrivalAtMidpoint; 

    *delay = initialWait + 20 + trainWait + 10;
    *cost = 25 + 30;
    printf("route B. Start time %d minutes after hour ",startTime);
    printf("-> total duration = %d minutes, cost = $%d.\n",*delay,*cost);
    return;
}

    
//------------------------------ selectRoute ------------------------------  
int selectRoute(int aD, int bD, int dD) {
    // This function selects the quickest of the 3 alternative routes.

    int min = aD;
    if(bD < min) min = bD;
    if(dD < min) min = dD;

    if(min == aD) return 1;
    if(min == bD) return 2;
    if(min == dD) return 3;
    return 0; // This will never happen, but it makes the compiler happy.
}


