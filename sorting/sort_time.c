#include "sort.h"
#include<sys/time.h>

int main(int argc, char** argv) {
    if (argc < 5) {
        printf("Usage: ./sort_time <type of array> <start num> <end num> <step> <name of sort> <outfile>\n");
        exit(0);
    }

    int start=atoi(argv[2]), end=atoi(argv[3]), step=atoi(argv[4]);
    char *outfile=argv[6], *type=argv[1], *sort_name=argv[5];
    struct timeval t1, t2;
    double elapsedTime;
    FILE* fstream = fopen(outfile,"a");
    DATA* arr;

    if (end > MAX) {
        printf("Maximum allowed size is %d!\n. Aborting\n",MAX);
        exit(0);
    }

    for (int i=start;i<=end;i+=step) {

        arr = getArr(type,i);

        // start timer
        gettimeofday(&t1, NULL);

        sort(arr,i);

        // stop timer
        gettimeofday(&t2, NULL);
    
        // compute and print the elapsed time in millisec
        elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
        elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
        fprintf(fstream, "%s,%d,%f\n", sort_name, i, elapsedTime);

        free(arr);
    }
    return 0;
}
