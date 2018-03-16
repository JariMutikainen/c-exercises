/*
 * 6) Write a C program to achieve the following
     a. Read the name of one input file and 2 output files (through user input)
     b. The input file is having text data like (employeeid, employeename, 
        salary, departmentid)
    c. You need to read the data and produce two output files. One output 
       file will be having data sorted on employee name, and another output 
       file will be having data sorted on employee number.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXEMPLOYEES  20
#define MAXNAMELENGTH 30
#define MAXFILENAMELENGTH 20

typedef struct info_s {
    int   id;
    char  name[MAXNAMELENGTH];
    float salary;
    int   deptId;
} info_t;

int main(int argc, char *argv[])
{
    void readInFile(FILE* in, info_t* table,int* elems);
    void printPersonelData(FILE* out, info_t* table, int elems);
    void sortByNumber(info_t* table,int elems);
    void sortByName(info_t* table,int elems);
    FILE *in,*out1,*out2;
    char iFile[MAXFILENAMELENGTH];
    char oFile1[MAXFILENAMELENGTH];
    char oFile2[MAXFILENAMELENGTH];
    info_t personelData[MAXEMPLOYEES];
    int elements = 0;

    if(argc != 4) {
        printf("Incorrect arguments. Must be cmd <iFile> <oFile1> <oFile2>.\n");
        return 1;
    }
    
    strcpy(iFile,argv[1]);
    strcpy(oFile1,argv[2]);
    strcpy(oFile2,argv[3]);
    in = fopen(iFile,"r");
    out1 = fopen(oFile1,"w");
    out2 = fopen(oFile2,"w");
    readInFile(in,personelData,&elements);
    printf("Before any sorting the personelData array was like so:\n");
    printPersonelData(stdout,personelData,elements);
    sortByNumber(personelData,elements);
    printf("\nAfter sorting by the id-number the personelData array was like so:\n");
    printPersonelData(stdout,personelData,elements);
    printPersonelData(out1,personelData,elements);

    sortByName(personelData,elements);
    printf("\nAfter sorting by the name the personelData array was like so:\n");
    printPersonelData(stdout,personelData,elements);
    printPersonelData(out2,personelData,elements);

    fclose(in);
    fclose(out1);
    fclose(out2);

    return 0;
}
//------------------------------ readInFile ------------------------------  
void readInFile(FILE* in, info_t* table,int* elems) {
    // This function reads the input file and polpulates the personelData[]
    // array of main.

    int id,depId;
    char lName[MAXNAMELENGTH],fName[MAXNAMELENGTH],fullName[MAXNAMELENGTH];
    float pay;

    while(fscanf(in,"%d %s %s %f %d",&id,lName,fName,&pay,&depId) == 5) {
        strcpy(fullName,"");
        strcat(fullName,lName);
        strcat(fullName," ");
        strcat(fullName,fName);

        table[*elems].id = id;
        strcpy(table[*elems].name,fullName);
        table[*elems].salary = pay;
        table[*elems].deptId = depId;
        (*elems)++;
    }
    printf("%d employees were processed.\n",*elems);

    return;
}
//------------------------------ printPersonelData -----------------------------  
void printPersonelData(FILE* out, info_t* table, int elems) {
    // This function prints the contents of the table[].
    int i;
    for(i=0;i<elems;i++){
        fprintf(out,"%4d %25s %.1f %4d\n",
                table[i].id,table[i].name,
                table[i].salary,table[i].deptId);
    }
    return;
}
//------------------------------ sortByNumber ------------------------------  

void sortByNumber(info_t* table,int elems) {
    // This function sorts the elements of the table into the order of
    // ascending employee id number.

    int i,j;
    info_t temp;
    for(i=0;i<elems-1;i++) {
        for(j=i+1;j<elems;j++) {
            if(table[j].id < table[i].id) {  // swap
                temp = table[i];
                table[i] = table[j];
                table[j] = temp;
            }
        }
    }

    return;
}
//------------------------------ sortByName ------------------------------  

void sortByName(info_t* table,int elems) {
    // This function sorts the elements of the table into the alphabetic
    // order based on the employee name.

    int i,j;
    info_t temp;
    for(i=0;i<elems-1;i++) {
        for(j=i+1;j<elems;j++) {
            //if(table[j].id < table[i].id) {  // swap
            if(strcmp(table[j].name, table[i].name) < 0) {  // swap
                temp = table[i];
                table[i] = table[j];
                table[j] = temp;
            }
        }
    }

    return;
}
