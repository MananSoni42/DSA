/*
 * Test file to test the basic functions of the linked list
**/ 

#include<stdio.h>
#include<stdlib.h>
#include "ll.h"

int main() {
    List* l = newList();
    printList(l);
    l = addAfter(l,0,1);
    l = addAfter(l,1,3);
    l = addBefore(l,3,2);
    printList(l);
    l = deleteElem(l,2);
    printList(l);
    return 0;
}

