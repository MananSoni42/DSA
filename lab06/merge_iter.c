#include<stdio.h>
#include<stdlib.h>

void merge(int* arr1, int len1, int* arr2, int len2, int* merged_arr) {
    printf("merge: %d %d\n",len1,len2);
    //int* merged_arr = (int*)malloc((len1+len2)*sizeof(int));
    int i,ind1=0,ind2=0,ind=0;

    while (ind1<=len1 || ind2<=len2) {
        if (ind1 == len1  && ind2 < len2) {
            merged_arr[ind] = arr2[ind2];
            ind2++;
        }

        else if (ind2 == len2 && ind1 < len1) {
            merged_arr[ind] = arr1[ind1];
            ind1++;
        }
        
        else {
            if (arr1[ind1] <= arr2[ind2]) {
                merged_arr[ind] = arr1[ind1];
                ind1++;
            }
            else {
                merged_arr[ind] = arr2[ind2];
                ind2++;
            }
        }
        ind++;
    }
}

void mergeSort(int* arr, int lo, int hi) {
    if (lo < hi) {
        int mid = (lo + hi)/2;
        printf("%d %d %d\n",lo,mid,hi);
        mergeSort(arr,lo,mid);
        mergeSort(arr,mid+1,hi);

        int marr[hi-lo+1];
        merge(&arr[lo], mid-lo+1, &arr[mid+1], hi-mid, marr);
        for (int i=0;i<hi-lo+1;i++) {
            printf("%d ",marr[i]);
            arr[lo+i] = marr[i];
        } printf("\n");
    }
}

int main() {
    int a1[] = {1,2,4,6,10}, a2[] = {3,5,7,9}, arr[9], a[] = {8,7,6,5,4,3,2,1,0};
    //merge(a1, 5, a2, 4, arr);
    mergeSort(a,0,8);
    for (int i=0;i<9;i++) {
        printf("%d ",a[i]);
    } printf("\n");

    for (int i=0;i<8;i++) {
        printf("%d ",arr[i]);
    } printf("\n");

    return 0;
}
