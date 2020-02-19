#include<stdio.h>
#include<stdlib.h>
#include "ll.h"

Node* reverseList(List* ll, Node* node) {
    if (node->next == NULL) { // base case (list with one node is trivially reversed)
        ll->head = node;
        return node;
    }
    
    Node *revLast = reverseList(ll, node->next); // get back the last node of the reversed list
    node->next = NULL; // this node may be the last node
    revLast->next = node; // add the current node to it 
    return node;

}

int main() {
    List *ll = newList();
    addAfter(ll,0,1);
    addAfter(ll,1,2);
    addAfter(ll,2,3);
    addAfter(ll,3,4);
    addAfter(ll,4,5);
    printList(ll);
    
    reverseList(ll,ll->head);

    printList(ll);
    return 0;
}
