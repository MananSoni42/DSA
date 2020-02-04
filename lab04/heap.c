#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
# define M 1000;

int heap_mem_used=0;
int ptr_size=0;

void* myalloc(size_t size) {
    void* ptr = malloc(size);
    if (ptr!=NULL) {
        heap_mem_used += (int)size;
    }
    ptr_size = (int)size;
    return ptr;
}

void myfree(void* ptr) {
  heap_mem_used -= ptr_size;
  free(ptr);
}

int main() {
  int i, rnd, *arr;
  bool stop=false;
  srand(time(NULL));
  while(!stop) {
    rnd = 10000 + rand()%(15000+1);
    arr = myalloc(rnd);
    if (arr == NULL) {
        stop = true;
    }
    printf("Array [ size (%d) from %u to %u ]\n",i,rnd,&arr[0],&arr[rnd-1]);
  }
}
