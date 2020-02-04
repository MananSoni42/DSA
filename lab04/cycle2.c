#include<stdbool.h>
#include "ll.h"

bool testCyclic(List* ll) {
  Node *prev = NULL, *curr = ll->head, *next = NULL;
  bool cyclic = false;

  if (ll->head == NULL || ll->head->next == NULL) { //rely on short circuiting for correctness
    return false;
  }

  while (curr!=NULL) { // reverse the links
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  if (prev == ll->head) { //we end up where we started => loop exists
    cyclic = true;
  }

  curr = prev;
  prev = NULL;
  while (curr!=NULL) { // reverse the links again, restoring the original LL
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  return cyclic;
}
