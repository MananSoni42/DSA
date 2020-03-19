#include "sort.h"

void sort(DATA* arr, int len) {
    int i,j;
    DATA ind;
    for (i=1;i<len;i++) {
        ind = arr[i];
        j = i-1;
        while (j>=0 && arr[j].index > ind.index) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = ind;
    }
}
