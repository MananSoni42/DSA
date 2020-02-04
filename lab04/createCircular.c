#include "ll.h"
#include "cycle.h"

void freeList(List*);

int main() {
  int n = 10;
  List* ll = createCycle(createList(n));
  printList(ll,15);

  if (!testCyclic(ll)) {
    Node* ptr = ll->head;
    if (ptr != NULL) {
      while (ptr->next!=NULL) {
        ptr = ptr->next;
      }
      ptr->next = ll->head;
    }
  }

  else {
    freeList(ll);
    Node* ptr = ll->head;
    if (ptr != NULL) {
      while (ptr->next!=NULL) {
        ptr = ptr->next;
      }
      ptr->next = ll->head;
    }
  }

  printList(ll,15);
  return 0;
}

void freeList(List* ll) {
  if (ll->head == NULL || ll->head->next == NULL) {
    return;
  }

  if (testCyclic(ll)) {
    Node* temp = ll->head;
    ll->head = ll->head->next;
    free(temp);
    freeList(ll);
  }
}
