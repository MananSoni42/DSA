#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include<stdbool.h>
#include "read.h"
#define MAX 100
#define FIELDS 2

DATA *read_from_csv(char* f, int *len) {
    char line[MAX],buffer[MAX];
    char *tok,*lptr;
    bool err=false;
    int k=0,size=10,i;
    DATA *arr = (DATA*)malloc(sizeof(DATA)*size);

    FILE* fstream = fopen(f,"r");

    if (!fstream) {
        printf("ERROR! Could not open file: %s\n",f);
        return NULL;
    }

    while(1) {
        if (err) {
            printf("An error occured\n");
            break;
        }

        if (k == size) {
            size*=2;
            arr = realloc(arr,sizeof(DATA)*size);
        }

        fgets(line,MAX,fstream); // read a line from the text file
        
        lptr = line; // use a ptr to string for easier string manipulations

        tok = strtok(lptr,",");
        for (i=0;i<FIELDS;i++) {
            
            if (tok == NULL) { // catch any unknown errors
                err = true;
                break;
            }

            switch(i) {
                case 0: strcpy(arr[k].name, tok); break;
                case 1: strcpy(buffer,tok); arr[k].cgpa = atof(buffer); break;
            }
            tok = strtok(NULL,",");
        } k++;

        if (feof(fstream)) { break; }
    }

    fclose(fstream);
    *len = (k>1)?k-1:0;
    return arr;
}

