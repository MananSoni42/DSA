#include "sort.h"

void sort(DATA* arr, int len) {
    int i,j,min=0;

    for (i=0;i<len;i++) {
        min = i;
        for (j=i+1;j<len;j++) {
            if (arr[j].index < arr[min].index) {
                min = j;
            }
        }
        swap(&arr[min],&arr[i]);
    }
}
