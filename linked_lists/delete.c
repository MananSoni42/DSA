#include<stdio.h>
#include<stdlib.h>
#include "ll.h"

int main() {
    List* ll = newList();
    addAfter(ll,0,1);
    addAfter(ll,1,2);
    addAfter(ll,2,3);
    addAfter(ll,3,4);
    addAfter(ll,4,5);
    printList(ll);

    Node *ptr = ll->head, *temp;
    while (ptr!=NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    free(ll);
    return 0;
}
