#include "ll.h"
#include<time.h>

double randf(double low,double high){
    return (random()/(double)(RAND_MAX))*abs(low-high)+low;
}

List* createList(int n) {
    srand(time(NULL));
    int i;
    List* ll = malloc(sizeof(List));
    ll->head = NULL;
    ll->size = n;
    Node* ptr;

    for (i=0;i<n;i++) {
        Node* newNode = malloc(sizeof(Node));
        newNode->next = NULL;
        //newNode->data = random()%100;
        newNode->data = i+1;
        if (ll->head==NULL) {
            ptr = newNode;
            ll->head = ptr;
        }
        else {
            ptr->next = newNode;
            ptr = ptr->next;
        }
    }
    return ll;
}

List* createCycle(List* ll) {
    int ind = (int)(random()%(ll->size));
    Node *ptr = ll->head, *num_ptr=ll->head;

    if (randf(0,1) < 0.5) {
        return ll;
    }

    for (int i=0;i<ind;i++) {
        num_ptr = num_ptr->next;
    }

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }

    ptr->next = num_ptr;

    return ll;
}

void printList(List* ll, int max) {
  Node *ptr = ll->head;
  int i=0;
  printf("\nLL: [");
  while (ptr != NULL && i <= max) {
      if (0 <= ptr->data && ptr->data <= 100) {
        printf("%d ",ptr->data);
      }
      i++;
      ptr = ptr->next;
  }
  printf("] %s\n",(i>max)?"cyclic":"linear");
}
