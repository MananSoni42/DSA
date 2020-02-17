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
    addAfter(ll,5,6);
    addAfter(ll,6,7);
    addAfter(ll,7,8);
    printList(ll);

    int mod = 0;
    Node *ptr = ll->head, *temp;

    while (ptr != NULL && ptr->next != NULL) {
        printf("%d %d\n",mod,ptr->data);
        if (mod == 0) {
            temp = ptr->next;
            ptr->next = ptr->next->next;
            free(temp);
            mod = (mod+1)%2;
        }
        ptr = ptr->next;
        mod = (mod+1)%2;
    }

    printList(ll);
}
