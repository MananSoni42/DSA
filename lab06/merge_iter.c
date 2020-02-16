#include<stdio.h>
#include<stdlib.h>
#include "merge.h"
#include "read.h"

void merge(DATA* arr1, int len1, DATA* arr2, int len2, DATA* merged_arr) {
    //printf("merge: %p %d %p %d\n",arr1,len1,arr2,len2);
    //int* merged_arr = (int*)malloc((len1+len2)*sizeof(int));
    int i,ind1=0,ind2=0,ind=0;

    while (ind1 < len1 && ind2 < len2) {
        if (arr1[ind1].cgpa < arr2[ind2].cgpa) {
            merged_arr[ind] = arr1[ind1];
            ind1++;
        }
        else {
            merged_arr[ind] = arr2[ind2];
            ind2++;
        }
        ind++;
    }

    while (ind1 < len1) {
        merged_arr[ind] = arr1[ind1];
        ind++; ind1++;
    }

    while (ind2 < len2) {
        merged_arr[ind] = arr2[ind2];
        ind++; ind2++;
    }
}

void mergeSort(DATA* arr, int lo, int hi) {
    int arr_size=1, step_size=2, i, j;
    DATA ptr;
    while (arr_size != hi-lo) {
        for (i=lo;i<hi;i+=step_size) {
            DATA* marr = (DATA*)malloc(sizeof(DATA)*(hi-lo+1));
            //printf("merge: %d %d\n",i,arr_size);
            merge(&arr[i], arr_size, &arr[i+arr_size], arr_size, marr);
            for (j=0;j<step_size;j++) {
                arr[i+j] = marr[j];
                //printf("arr: %d ",arr[i+j]);
              } //printf("\n");
            free(marr);
        }
        arr_size*=2;
        step_size*=2;
    }

    if ((hi-lo)%2 == 0) { // handle special case when the array has an odd length
        DATA* marr = (DATA*)malloc(sizeof(DATA)*(hi-lo+1));
        merge(arr, hi-lo, &arr[hi-lo], 1, marr);
        for (j=0;j<hi-lo+1;j++) {
            arr[j] = marr[j];
            //printf("arr1: %d ",arr[j]);
        } //printf("\n");
        free(marr);
    }
}
