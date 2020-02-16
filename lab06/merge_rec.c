#include<stdio.h>
#include<stdlib.h>
#include "merge.h"
#include "read.h"

void merge(DATA* arr1, int len1, DATA* arr2, int len2, DATA* merged_arr) {
    //printf("merge: %p %d %p %d\n",arr1,len1,arr2,len2);
    //DATA* merged_arr = (DATA*)malloc((len1+len2)*sizeof(int));
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
    DATA ptr;
    if (lo < hi) {
        int mid = (lo + hi)/2;
        //printf("%d %d %d %d\n",lo,mid,hi,hi-lo+1);
        mergeSort(arr,lo,mid);
        mergeSort(arr,mid+1,hi);

        DATA* marr = (DATA*)malloc(sizeof(DATA)*(hi-lo+1));
        //printf("merge: %d %d %d %d %d\n",lo,mid,mid-lo+1, mid+1,hi,hi-mid);
        merge(&arr[lo], mid-lo+1, &arr[mid+1], hi-mid, marr);
        //printf("%d\n",hi-lo+1);
        for (int i=0;i<hi-lo+1;i++) {
            arr[lo+i] = marr[i];
            //printf("arr: %d ",arr[lo+i]);
        } //printf("\n");
        free(marr);
    }
}
