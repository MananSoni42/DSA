#include<stdio.h>
#include "sort.h"

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: ./sort_test <size of array> <type of array>\n");
        exit(1);
    }

    int size = atoi(argv[1]); 
    DATA* arr = getArr(argv[2], size);
    printf("initial: \n");
    printList(arr,size);
    sort(arr,size);
    printf("sorted: \n");
    printList(arr,size);
    free(arr);

    return 0;
}
