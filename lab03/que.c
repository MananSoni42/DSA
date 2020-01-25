#include "que.h"

Queue* newQ() {
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->size = 0;
	q->head = NULL;
	q->tail = NULL;
	return q;
}

bool isEmptyQ(Queue* q) {
	if (q->size == 0) {
		return true;
	}
	return false;
}

Queue* delQ(Queue* q) {
	Node* ptr = q->head;
	if (ptr == NULL) {
		q->tail = NULL;
		return q;
	}
	q->head = q->head->next;
	free(ptr);
	q->size--;
	return q;
}

Queue* addQ(Queue* q, Element e) {
	Node* ptr = (Node*)malloc(sizeof(Node));
	ptr->elem = e;
	ptr->next = NULL;
	if (q->tail == NULL) {
		q->tail = ptr;
		q->head = q->tail;
	}
	else {
		q->tail->next = ptr;
	}
	q->size++;
	return q;
}

Element front(Queue* q) {
	Element e;
	e.id = -1; e.pr = -1;
	if (q->head == NULL) {
		return e;
	}
	return q->head->elem;
}

int lengthQ(Queue* q) {
	return q->size;
}

void printQ(Queue* q) {
	Node* ptr = q->head;
	while (ptr!=NULL) {
		printf("[id-%d, pr-%d] ",(ptr->elem).id,(ptr->elem).pr);
		ptr = ptr->next;
	}
	printf("\n");
}
