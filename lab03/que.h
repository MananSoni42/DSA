#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct element {
	int id;
	int pr;
} Element;

typedef struct node {
	Element elem;
	struct node* next;
} Node;

typedef struct queue {
	int size;
	Node* head;
	Node* tail;
} Queue;

Queue* newQ(); // returns an empty Queue
bool isEmptyQ(Queue*); // tests whether q is empty
Queue* delQ(Queue*); // deletes the element from the front of the Queue;
Element front(Queue*); // returns the element from the front of the Queue;
Queue* addQ(Queue*, Element); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(Queue*); // returns the length of the Queue
void printQ(Queue*); // print the entire Queue
