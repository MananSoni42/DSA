#include "sort.h"
#include<stdlib.h>

void sort(DATA* arr, int len) {
    int i,k=0;
    int *ind = (int*)malloc(MAX*sizeof(int));
    DATA out[len];

    
    for (i=0;i<MAX;i++) {
        ind[i] = 0;
    }

    for (i=0;i<len;i++) { // populate indices (store counts)
        ind[arr[i].index]++;
    }

    for (i=1;i<MAX;i++) { // perform cumulative totalling
        ind[i] += ind[i-1];
    }

    for (i=MAX-1;i>=1;i--) { // shift index array right by 1
        ind[i] = ind[i-1];
    }
    ind[0] = 0; // leftmost entry becomes 0

    for (i=0;i<len;i++) { // fill output array
        out[ind[arr[i].index]] = arr[i];
        ind[arr[i].index]++;
    }

    free(ind);
    memcpy(arr,out,len*sizeof(DATA));
}
