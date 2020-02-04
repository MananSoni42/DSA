#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

typedef struct ll {
    Node* head;
    int size;
} List;

List* createList(int);
List* createCycle(List*);
void printList(List*,int);
double randf(double,double);
