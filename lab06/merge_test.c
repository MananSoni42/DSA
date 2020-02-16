#include<stdio.h>
#include<stdlib.h>
#include "merge.h"
#include "read.h"
#include<sys/time.h>

int main() {
    struct timeval t1,t2;
    double elapsedTime;

    char *fname = "lab_sheet/1024.txt";
    int len = 0;
    DATA* arr = read_from_csv(fname,&len);

    //printf("Read %s: length is %d\n",fname,len);

    printf("number, time\n");
    for (int i=1;i<=len;i*=2) {

      // start timer
      gettimeofday(&t1, NULL);

      mergeSort(arr,0,i);

      // stop timer
      gettimeofday(&t2, NULL);

      // compute and print the elapsed time in millisec
      elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
      elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
      printf("%5d, %3.3f\n",i,elapsedTime);

    }
    free(arr);
    return 0;
}
