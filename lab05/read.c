#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include<stdbool.h>
#define MAX 100
#define FIELDS 5

typedef struct data {
    long long int card_num;
    char bank_code[MAX];
    char exp_date[MAX];
    char fname[MAX];
    char lname[MAX];
} DATA;

DATA *read(char* f, int *len) {
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
            printf("An error occured");
            break;
        }

        if (k == size) {
            size*=2;
            arr = realloc(arr,sizeof(DATA)*size);
        }

        fgets(line,MAX,fstream); // read a line from the text file
        
        lptr = line;
        lptr++;
        lptr[strlen(line)-3] = 0; // remove enclosing double quotes from the file

        tok = strtok(lptr,",");
        for (i=0;i<5;i++) {
            
            if (tok == NULL) { // catch any unknown errors
                err = true;
                break;
            }

            switch(i) {
                case 0: strcpy(buffer,tok); arr[k].card_num = atoll(buffer); break;
                case 1: strcpy(arr[k].bank_code, tok); break;
                case 2: strcpy(arr[k].exp_date, tok); break;
                case 3: strcpy(arr[k].fname, tok); break;
                case 4: strcpy(arr[k].lname, tok); break;
            }
            tok = strtok(NULL,",");
        } k++;

        if (feof(fstream)) { break; }
    }

    fclose(fstream);
    *len = (k>1)?k-1:0;
    return arr;
}

int main() {
    int size=0;
    long int i;
    char fname[MAX];
    struct timeval t1, t2;
    double elapsedTime;

    for (i=10000;i<=10000000;i*=10) {
        sprintf(fname, "lab_sheet/%ld",i);

        // start timer
        gettimeofday(&t1, NULL);    

        DATA *arr = read(fname,&size);
        
        // stop timer
        gettimeofday(&t2, NULL);

        // compute and print the elapsed time in millisec
        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms

        printf("Time taken to read %8d is %3.4f ms\n",i,elapsedTime);
    }

    return 0;
}
