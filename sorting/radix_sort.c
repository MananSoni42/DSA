#include<math.h>
#include "sort.h"

int get_bit(int num, int bits) {
    for (int i=1;i<=bits-1;i++) {
        num = num / 10;
    }
    return num%10;
}

void counting_sort(DATA* arr, int len, int range, int bit) {
    int ind[MAX],i,k=0;
    DATA out[len];
    memset(ind,0,range*sizeof(int));
   
    for (i=0;i<len;i++) { // populate indices (store counts)
        ind[get_bit(arr[i].index,bit)]++;
    }

    for (i=1;i<range;i++) { // perform cumulative totalling
        ind[i] += ind[i-1];
    }

    for (i=range-1;i>=1;i--) { // shift index array right by 1
        ind[i] = ind[i-1];
    }
    ind[0] = 0; // leftmost entry becomes 0

    for (i=0;i<len;i++) { // fill output array
        out[ind[get_bit(arr[i].index,bit)]] = arr[i];
        ind[get_bit(arr[i].index,bit)]++;
    }

    memcpy(arr,out,len*sizeof(DATA));
}

void sort(DATA* arr, int len) { 
    for (int i=1;i<=(int)log10(MAX);i++) {
        counting_sort(arr,len,10,i);
    }
}
