#include<stdbool.h>
#include "ll.h"

bool testCyclic(List* ll) {
    Node *slowptr=ll->head, *fastptr=ll->head;
    bool cyclic = false;

    if (ll->head == NULL || ll->head->next == NULL) {
      return false;
    }

    while (slowptr != NULL && fastptr !=NULL && fastptr->next != NULL) {
      if (fastptr->next == slowptr || (fastptr == slowptr && slowptr!=ll->head)) {
        cyclic = true;
        break;
      }
      slowptr = slowptr->next;
      fastptr = fastptr->next->next;
    }
    return cyclic;
}
