#include<stdio.h>
#include "read.h"

int main() {
    char *fname = "lab_sheet/1024.txt";
    int len = 0;
    DATA* arr = read_from_csv(fname,&len);

    printf("Size of file: %d\n",len);
    for(int i=0;i<len;i++) {
        printf("%d: %s %f\n",i+1,arr[i].name,arr[i].cgpa);
    }

    return 0;
}
