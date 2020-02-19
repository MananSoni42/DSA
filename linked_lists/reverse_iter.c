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

    Node *prev=NULL, *curr=ll->head, *next=ll->head;

    while (curr!=NULL) {
        next = curr->next; // save next node for further traversal
        curr->next = prev; // reverse direction of current node
        
        prev = curr; curr = next; // traverse the list
    }
    ll->head = prev;
    printList(ll);
    return 0;
}
