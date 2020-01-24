#include "que.h"

Queue newQ() {
	Queue q = (Queue*)malloc(sizeof(Queue));
	q->len = 0;
	q->head = NULL;
	q->head->next = NULL;
	q->tail = NULL;
	q->tail->next = NULL;
	return q;
}

Boolean isEmptyQ(Queue q) {
	if (q->len == 0) {
		return true;
	}
	return false;
}

Queue delQ(Queue q) {
	if (q.isEmptyQ()) {
		return q;
	}
	else {
		node* ptr = NULL;
		ptr = q->head;
		q->head = q->head->next;
		free(ptr);
	}
	q->len--;
	return q;
}

Element Front(Queue q) {
	return q->head;
}

Queue addQ(Queue q, Element e) {
	node* ptr = (node)malloc(sizeof(node));
	ptr->elem = e
	ptr->next = NULL;
	q->tail->next = ptr;
	q->tail = ptr;
	q->len++;
}

int lengthQ(Queue q) {
	return q->len;
}
