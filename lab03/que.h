#include<stdio.h>
#include<stdbool.h>

struct Element {
	int id;
	int pr;
}

struct node {
	Element elem;
	node* next;
}

struct Queue {
	int len;
	node* head;
	node* tail;
}

Queue newQ() // returns an empty Queue
Boolean isEmptyQ(Queue q); // tests whether q is empty
Queue delQ(Queue q); // deletes the element from the front of the Queue;
Element front(Queue q); // returns the element from the front of the Queue;
Queue addQ(Queue q , Element e); // adds e to the rear of the Queue; returns the modified Queue
int lengthQ(Queue q); // returns the length of the Queue
