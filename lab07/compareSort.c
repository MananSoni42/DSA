#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include "read_csv.h"
#include "sort.h"

double* testRun(DATA* arr1, int len) {
    struct timeval t1, t2;
    double qt,it;
    double* arr = (double*)malloc(2*sizeof(double));    
    DATA* arr2 = (DATA*)malloc(len*sizeof(DATA));
    memcpy(arr2,arr1,len*sizeof(DATA));

    // start timer
    gettimeofday(&t1, NULL);
    
    insertionSort(arr1,len);

    // stop timer
    gettimeofday(&t2, NULL);
    
    // compute and print the elapsed time in millisec
    it = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    it += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
    
    // start timer
    gettimeofday(&t1, NULL);
    
    quickSort(arr2,len);

    // stop timer
    gettimeofday(&t2, NULL);
    
    // compute and print the elapsed time in millisec
    qt = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    qt += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms

    free(arr2);

    arr[0] = it;
    arr[1] = qt;
    
    return arr;
}

int estimateCutoff(DATA* arr, int len) {
    int lo = 0, hi = len, mid;
    double err = 0.001;
    double *tarr;
    DATA* copy_arr = (DATA*)malloc(len*sizeof(DATA));

    do {
        mid = (lo+hi)/2;
        memcpy(copy_arr, arr, mid*sizeof(DATA));
        tarr = testRun(copy_arr, mid);

        if (tarr[0] > tarr[1]) {
            hi = mid;
        }
        else {
            lo = mid;
        }
    } while (abs(tarr[0]-tarr[1] >= err));

    free(copy_arr);
    free(tarr);

    return mid;
}

int main(int argc, char **argv) {

    if (argc < 3) {
        printf("Usage: ./compareSort <inFile> <outFile>\n");
        return 1;
    }

    int len=0;
    DATA* arr = read_from_csv(argv[1], &len);

    int cutoff = estimateCutoff(arr,len);

    struct timeval t1,t2;
    double time;
    
    // start timer
    gettimeofday(&t1, NULL);
    
    quickInsSort(arr,len,cutoff);

    // stop timer
    gettimeofday(&t2, NULL);
    
    // compute and print the elapsed time in millisec
    time = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
    time += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
    printf("n: %10d, cutoff: %3d, time: %f\n", len, cutoff, time);

    FILE* fptr = fopen(argv[2],"w");
    if (fptr == NULL) {
        printf("Could not open file: %s!\n",argv[2]);
    }
    for (int i=0;i<len;i++) {
        fprintf(fptr,"%s,%d\n", arr[i].name, arr[i].empID);
    }
    fclose(fptr);

    return 0;    
}
