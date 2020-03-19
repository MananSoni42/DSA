#include "sort.h"

void sort(DATA* arr, int len) {
    int i,j;
    for (i=0;i<len-1;i++) {
        for (j=0;j<len-i-1;j++) {
            if (arr[j].index > arr[j+1].index) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}
