#include "multiq.h"

int main() {
  MultiQ* mq = createMQ(5);
  printMQ(mq);
  printf("Empty: %d\n",isEmptyMQ(mq));
  printf("size: %d\n", sizeMQ(mq));

  Element e;
  e.id = 1; e.pr = 1;
  addMQ(mq,e);
  e.id = 2; e.pr = 1;
  addMQ(mq,e);
  e.id = 4; e.pr = 2;
  addMQ(mq,e);
  e.id = 3; e.pr = 2;
  addMQ(mq,e);
  printMQ(mq);
  printf("Empty: %d\n",isEmptyMQ(mq));
  printf("size: %d\n", sizeMQ(mq));

  Queue* q = nextMQ(mq);
  printf("\n"); printQ(q);

  mq = delNextMQ(mq);
  printMQ(mq);
  printf("size: %d\n", sizeMQ(mq));

  printf("\n");
  for (int i=0;i<4;i++) {
    printf("pr: %d - size: %d\n",i,sizeMQbyPriority(mq,i));
  }

  printf("\n");
  for (int i=0;i<4;i++) {
    q = getQueueFromMQ(mq,i);
    printf("pr: %d - Queue: ",i); printQ(q);
  }
}
