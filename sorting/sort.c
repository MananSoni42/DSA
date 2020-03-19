#include "sort.h"

DATA* getArr(char* type, int len) {
    DATA* arr = (DATA*)malloc(len*sizeof(DATA));
    int i;

    if (!strcmp(type,"reverse")) {
        for (i=0;i<len;i++) {
            arr[i].index = len-i;
            arr[i].data = i;
        }
    }

    else if (!strcmp(type,"random")) {
        srand(time(0));
        for (i=0;i<len;i++) {
            arr[i].index = rand()%MAX;
            arr[i].data = i;
        }
    }

    return arr;
}

void printList (DATA* arr, int len) { // print the entire array
    for (int i=0;i<len;i++) {
        printf("%d ",arr[i].index);
    } printf("\n");
}

void swap(DATA* elem1, DATA* elem2) { // swap 2 data elements
    DATA temp;
    temp = *elem1;
    *elem1 = *elem2;
    *elem2 = temp;
}
