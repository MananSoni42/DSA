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

DATA* ptr_to_base = NULL;

int measure(DATA* ptr) {
    if (ptr_to_base == NULL) {
        ptr_to_base = ptr;
        return 0;
    }
    //printf("%p - %p = %d\n",ptr,ptr_to_base,ptr-ptr_to_base);
    return ptr-ptr_to_base;
}

void insertInOrder(DATA* arr, int len, DATA elem) { //ensure size of DATA arr is atleast len+1
    int i,j;
    DATA temp;
    for (i=0;i<len;i++) {
        if (arr[i].card_num > elem.card_num) {
            temp = arr[i];
            arr[i] = elem;
            for (j=len-1;j>=i+1;j--) {
                arr[j+1] = arr[j];
            }
            arr[i+1] = temp;
            break;
        }
    }
    if (i == len) {
        arr[len] = elem;
    }
}

int insertionSort(DATA* arr, int len) {
    if (len <= 1) {
        return measure(&arr[1]);
    }

    //sort first len-1 elements
    int mem = insertionSort(arr,len-1);

    // insert last element at correct postion
    insertInOrder(arr,len-2,arr[len-2]);

    return mem;
}

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

        if (k == size-1) {
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
    DATA base, *arr;
    int size=0,mem=0;
    long int i;
    char fname[MAX];
    struct timeval t1, t2;
    double elapsedTime;

    measure(&base); // initialize base ptr inside the function

    printf("size of file, time taken ,stack space\n");
    for (i=10;i<=10000;i*=10) {
        sprintf(fname, "lab_sheet/%ld",i);
        free(arr);
        arr = read(fname,&size);

        if (i == 10000) {
          for (int j=30;j<=10000;j*=2) {
            size = j;
            // start timer
            gettimeofday(&t1, NULL);

            mem = insertionSort(arr,size+1);

            // stop timer
            gettimeofday(&t2, NULL);

            // compute and print the elapsed time in millisec
            elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
            elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms

            printf("%d,%3.4f,%ld\n",j,elapsedTime,mem);
          }
        }

        else {
          // start timer
          gettimeofday(&t1, NULL);

          mem = insertionSort(arr,size+1);

          // stop timer
          gettimeofday(&t2, NULL);

          // compute and print the elapsed time in millisec
          elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
          elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms

          printf("%d,%3.4f,%ld\n",size,elapsedTime,mem);
        }
    }


    return 0;
}
