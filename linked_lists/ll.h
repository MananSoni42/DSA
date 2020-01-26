/*
 Header file for the Linked list
 include in any file to get access tto the linked list as:
 #include "ll.h"
*/ 

#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct list {
    Node* head;
} List;

List* newList();
List* addAfter(List*,int,int); // add an element after the provided element
List* addBefore(List*,int,int); // add an element before the provided element
List* deleteElem(List*,int); // Delete provided elemnt from list (once)
void printList(List*); // print the entire list along with it's size    

