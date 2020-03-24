#include "sort.h"

void sort(DATA* arr, int len) {
    int ind[MAX],i,k=0;
    DATA out[len];
    memset(ind,0,MAX*sizeof(int));
    
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

    memcpy(arr,out,len*sizeof(DATA));
}
