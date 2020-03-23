#include "sort.h"

int parent(int i) {
    return i/2;
} 

int left(int i) {
    return 2*i;
}

int right(int i) {
    return 2*i+1;
}

void max_heapify(DATA* arr, int len, int ind) {
    int n=ind, l=left(n), r=right(n), maxn=ind;
    
    if (l < len && arr[l].index > arr[n].index) {
        maxn = l;
    }
    else if (r < len && arr[r].index > arr[n].index) {
        maxn = r;
    }
    if (arr[maxn].index != arr[n].index && maxn < len) {
        //printf("\t%d:%d %d:%d\n", maxn,arr[maxn].index,n,arr[n].index);
        swap(&arr[n], &arr[maxn]);
        max_heapify(arr, len ,maxn);
    }
}

void build_max_heap(DATA* arr, int len) {
    for (int i=len/2;i>=0;i--) {
        //printf("%d: ",i); 
        max_heapify(arr,len,i);
        //printList(arr,len);
    }
}

void sort(DATA* arr, int len) {
    build_max_heap(arr,len);
    //printList(arr,len);
    for(int i=len-1;i>=0;i--) {
        swap(&arr[0],&arr[i]);
        max_heapify(arr,i,0);
    }
}
