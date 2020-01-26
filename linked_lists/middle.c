/*
 * Find the middle element of a given list
**/ 

#include<stdio.h>
#include<stdlib.h>
#include "ll.h"

int main() {
    List* l = newList();
    l = addAfter(l,0,1);
    l = addAfter(l,1,2);
    l = addAfter(l,2,3);
    l = addAfter(l,3,4);
    l = addAfter(l,4,5);
    printList(l);

    Node *slow_ptr=l->head, *fast_ptr=l->head;
    while (slow_ptr!=NULL && fast_ptr!=NULL && fast_ptr->next!=NULL) {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }
    if (slow_ptr == NULL) {
        printf("List was empty!\n");
    }
    else {
        if (fast_ptr == NULL) {
            printf("No middle element exists\n");
        }
        else {
            printf("Middle element is: %d\n",slow_ptr->data);
        }
            
    }

    return 0;
}
