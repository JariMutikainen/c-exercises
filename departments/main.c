/*Consider two text files. The first one is having a list of employees and 
 * their department numbers stored (that is empid, ename, deptid, and there 
 * is one record per line). The second one is having the departments along 
 * with their names and location (that is deptid, deptname, dlocation). 
 * Read the files and construct structures having all this data (that is 
 * empid, ename, deptid, dname, dlocation). Display the list of structures 
 * and save this information in another file.
 *
 *
 * */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define MAXNAME 20
#define MAXPERSONS 10 

typedef struct info_s {
    int empid;
    char ename[MAXNAME];
    int deptid;
    char dname[MAXNAME];
    char dlocation[MAXNAME];
} info_t;

int main()
{
    void readFile1(info_t* eArray, int* employees);
    void readFile2(info_t* eArray,int elems);
    void writeFile3(info_t* eArray,int elems);

    info_t personel[MAXPERSONS];
    int employees = 0;
    readFile1(personel,&employees);
    readFile2(personel,employees);
    writeFile3(personel,employees);



    return 0;
}
//------------------------------ readFile1 ------------------------------  
void readFile1(info_t* eArray, int* employees) {
    // This function reads the file1.txt and inserts the data into the
    // personel[] array of main.

    char iFile1[MAX] =  "H:\\GitHubLocalRepository\\c-exercises\\departments\\file1.txt";
    FILE *in;
    int eN,dId; // Employee number, department ID
    char fName[MAXNAME],lName[MAXNAME]; // the first name, the last name
    char fullName[MAXNAME];
    in = fopen(iFile1,"r");
    if(in == NULL) {
        printf("Failed to open %s.\n",iFile1);
    }
    
    while(fscanf(in, "%d %s %s %d",&eN,fName,lName,&dId) == 4) {
        // Construct the full name of the employee
        strcpy(fullName,"");
        strcat(fullName,fName);
        strcat(fullName," ");
        strcat(fullName,lName);

        //printf("%d %s %d\n",eN,fullName,dId);
        eArray[*employees].empid = eN;
        strcpy(eArray[*employees].ename,fullName);
        eArray[*employees].deptid = dId;
        (*employees)++;
    }
    printf("%d employees were processed.\n",*employees);
    fclose(in);
    
    return;
}
//------------------------------ readFile2 ------------------------------  
void readFile2(info_t* eArray, int elems) {
    // This function reads the file2.txt and inserts the data into the
    // personel[] array of main.

    char iFile2[MAX] =  "H:\\GitHubLocalRepository\\c-exercises\\departments\\file2.txt";
    FILE *in;
    int dId,i;
    int lines = 0;
    char dName[MAXNAME],dLocation[MAXNAME];
    in = fopen(iFile2,"r");
    if(in == NULL) {
        printf("Failed to open %s.\n",iFile2);
    }
    while(fscanf(in, "%d %s %s",&dId,dName,dLocation) == 3) {
        //printf("%d %s %s\n",dId,dName,dLocation);
        // Update the correct elements in the personel[] array.
        for(i=0;i<elems;i++) {
            if(eArray[i].deptid == dId) {
                strcpy(eArray[i].dname,dName);
                strcpy(eArray[i].dlocation,dLocation);
            }
        }
        lines++;
    }
    printf("%d deprtment IDs were processed.\n\n",lines);
    fclose(in);
    return;
}
//------------------------------ writeFile3 ------------------------------  
void writeFile3(info_t* eArray, int elems) {
    // This function writes the contents of the personel[] array of main
    // into the file3.txt and on the screen.

    char oFile[MAX] =  "H:\\GitHubLocalRepository\\c-exercises\\departments\\file3.txt";
    FILE *out;
    out = fopen(oFile,"w");
    if(out == NULL) {
        printf("Failed to open %s.\n",oFile);
    }

    int i;
    for(i=0;i<elems;i++) {
        fprintf(out,"%3d %15s %8d %15s %10s\n",
                eArray[i].empid,
                eArray[i].ename,
                eArray[i].deptid,
                eArray[i].dname,
                eArray[i].dlocation
                );
        printf("%3d %15s %8d %15s %10s\n",
                eArray[i].empid,
                eArray[i].ename,
                eArray[i].deptid,
                eArray[i].dname,
                eArray[i].dlocation
                );
    }
    fclose(out);
}
    
