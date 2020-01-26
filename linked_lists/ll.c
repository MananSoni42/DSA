/*
 * This file provides implementations of the functions defined in ll.h
 * link this file during compilation of your program as:
 * gcc -o file file.c ll.c 
**/

#include "ll.h"

List* newList() {
    List* l = (List*)malloc(sizeof(List));
    l->head = NULL;
    return l;
}

List* addAfter(List* l, int elem, int new) {
    /*
     * addAfter: insert one data elemnt after a given element in the list
     * Arguements:
     *  * l: list object
     *  * elem: An element of the list after which new data needs to be inserted
     *  * new: New data element to be inserted
    **/ 
    
    Node* ptr = l->head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = new;
    newNode->next = NULL;

    if (l->head == NULL) {
        l->head = newNode;
        return l;
    }

    while (ptr->data!=elem && ptr!=NULL) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("ERROR! Unable to find element %d in LL\n",elem);
    }
    else {
        Node* temp = ptr->next;
        ptr->next = newNode;
        newNode->next = temp;
    }
    return l;
}

List* addBefore(List* l, int elem, int new) {
    /*
     * addBefore: insert one data elemnt before a given element in the list
     * Arguements:
     *  * l: list object
     *  * elem: An element of the list before which new data needs to be inserted
     *  * new: New data element to be inserted
    **/ 
    
    Node* ptr = l->head;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = new;
    newNode->next = NULL;

    if (l->head == NULL) {
        l->head = newNode;
        return l;
    }

    while (ptr->next->data!=elem && ptr->next!=NULL) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("ERROR! Unable to find element %d in LL\n",elem);
    }
    else {
        Node* temp = ptr->next;
        ptr->next = newNode;
        newNode->next = temp;
    }
    return l;
}

List* deleteElem(List* l, int elem) {
    /*
     * deleteElem: delete one instance of the given element, if it exists, from the list
     * Arguements:
     *  * l: list object
     *  * elem: Data element that needs to be deleted from the list 
    **/ 
    
    Node* ptr = l->head;

    if (l->head == NULL) {
        return l;
    }
    while (ptr->next->data!=elem && ptr->next!=NULL) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("ERROR! Unable to find element %d in LL\n",elem);
    }
    else {
        Node* temp = ptr->next;
        ptr->next = ptr->next->next;
        free(temp);
    }

    return l;
}

void printList(List* l) {
    /*
     * printList: prints the list in the format: LL: [elem 1, elem 2, ..., elem n] 
     * Arguements:
     * * l: list object
    **/ 

    Node* ptr = l->head;
    printf("\nLL: [");
    while(ptr!=NULL) {
        if (ptr->next == NULL) {
            printf("%d",ptr->data);
        }
        else {
            printf("%d, ",ptr->data);
        }
        ptr = ptr->next;
    }
    printf("]\n");
}
