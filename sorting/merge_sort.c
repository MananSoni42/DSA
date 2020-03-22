#include "sort.h"

void merge(DATA* arr, int l, int m, int r) { 
    int n=r-l, n_l=m-l, n_r=r-m, i=0, k=l, ri=0, li=0;
    DATA arr_l[n_l], arr_r[n_r];
    /*
    printf("\t\t");
    for (i=l;i<r;i++) {
        printf("%d ",arr[i].index);
    } printf("\n");
    */
    for (i=0;i<n_l;i++) {
        arr_l[i] = arr[l+i];
    }
    for (i=0;i<n_r;i++) {
        arr_r[i] = arr[m+i];
    }
        
    while (li < n_l && ri < n_r) {
        if (arr_l[li].index < arr_r[ri].index) {
            arr[k] = arr_l[li];
            li++;
        }

        else {
            arr[k] = arr_r[ri];
            ri++;
        }
        k++;
    }

    while (li < n_l) {
        arr[k] = arr_l[li];
        li++;
        k++;
    }

    while (ri < n_r) {
        arr[k] = arr_r[ri];
        ri++;
        k++;
    }
    /*
    printf("\t\t");
    for (i=l;i<r;i++) {
        printf("%d ",arr[i].index);
    } printf("\n\n");
    */
}

void merge_sort(DATA* arr, int l, int h) {
    if (h-l > 1) {
        int mid = (l+h)/2;
        //printList(arr,10);
        //printf("\t%d %d %d\n",l,mid,h);
        merge_sort(arr,l,mid);
        merge_sort(arr,mid,h);
        merge(arr,l,mid,h);
    }
}

void sort(DATA* arr, int len) {
    merge_sort(arr,0,len);
}
