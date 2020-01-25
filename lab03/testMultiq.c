#include "multiq.h"
#include<sys/time.h>
#define NUM_PR 10


MultiQ* loadData(char fname[]) {
  MultiQ* mq = createMQ(NUM_PR);
  FILE* fptr = fopen(fname,"r");
  if (fptr == NULL) {
    printf("ERROR! Couldn't open file %s\n",fname);
    return mq;
  }
  char ch;
  Element e;
  while (1) {
    int id,pr;
    fscanf(fptr,"%d,%d\n",&e.id,&e.pr);
    e.pr--; // convert priority from [1,10] to [0,9]
    if (feof(fptr)) {
      break;
    }
    addMQ(mq,e);
  }
  return mq;
}

MultiQ* testDel(MultiQ* mq, int num) {
  for (int i=0;i<num;i++) {
    mq = delNextMQ(mq);
  }
  return mq;
}

int main(int argc, char** argv) {
  struct timeval t1,t2;
  double elapsedTime;
  char *fname;
  int num_del = 5;
  if (argc > 1) {
    fname = argv[1];
  }
  else {
    fname = "input10.txt";
  }
  if (argc > 2) {
    num_del = atoi(argv[2]);
  }
  printf("file: %s\n",fname);
  // start timer
  gettimeofday(&t1, NULL);
  MultiQ* mq = loadData(fname);
  // stop timer
  gettimeofday(&t2, NULL);
  // compute and print the elapsed time in millisec
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
  //printMQ(mq);
  printf("\nTotal time taken for add operation: %1.4f ms\n",elapsedTime);
  printf("final size: %d\n",sizeMQ(mq));
  // start timer
  gettimeofday(&t1, NULL);
  mq = testDel(mq,num_del);
  // stop timer
  gettimeofday(&t2, NULL);
  // compute and print the elapsed time in millisec
  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0; // sec to ms
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0; // us to ms
  //printMQ(mq);
  printf("\nTotal time taken for %d delete operations: %1.4f ms\n",num_del,elapsedTime);
  printf("Average time per delete operation: %1.6f ms\n",elapsedTime/num_del);
  return 0;
}
