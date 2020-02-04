#include "ll.h"
#include "cycle.h"
#include<sys/time.h>

int main() {
    int n,i;
    double elapsedTime,totalTime=0;
    struct timeval t1,t2;
    for (n=2;n<=200000;n*=2) {
      totalTime=0;
      for (i=0;i<100;i++) {
        List* ll = createCycle(createList(n));
        // start timer
        gettimeofday(&t1, NULL);
        testCyclic(ll);
        // stop timer
        gettimeofday(&t2, NULL);
        // compute and print the elapsed time in millisec
        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
        totalTime += elapsedTime;
        free(ll);
      }
      printf("%d, %1.6f\n",n,totalTime/100);
    }
    return 0;
}
