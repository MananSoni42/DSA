/*
 * Find the kth element from the end of the List
**/

#include<stdio.h>
#include<stdlib.h>
#include "ll.h"

int main() {

    List* l = newList();
    int i,k;

    for(i=1;i<=100;i++) {
        l = addAfter(l,i-1,i);
    }
    printList(l);

    printf("Enter k: "); scanf("%d",&k);

    Node *behind_ptr = l->head, *ahead_ptr = l->head;
    for (i=0;i<k;i++) {
        if (ahead_ptr == NULL) {
            break;
        }
        ahead_ptr = ahead_ptr->next;
    }
    if (i != k) {
        printf("k is bigger than the size of the array!\n");
    }
    else {
        while (ahead_ptr!=NULL) {
            behind_ptr = behind_ptr->next;
            ahead_ptr = ahead_ptr->next;
        }
        printf("%d element from the end is: \n",behind_ptr->data);
    }
    
    return 0;
}
