#include<stdio.h>
#include<stdlib.h>

void merge(int* arr1, int len1, int* arr2, int len2, int* merged_arr) {
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

int main() {
    int a1[] = {1,2,4,6,10}, a2[] = {3,5,7,9}, arr[9];
    merge(a1, 5, a2, 4, arr);

    for (int i=0;i<8;i++) {
        printf("%d ",arr[i]);
    } printf("\n");

    return 0;
}
