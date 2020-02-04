#include "stack.h"

void push(struct stack *st, int elem) {
	struct node* new_link = (struct node*)malloc(sizeof(struct node));
	new_link->element = elem;
	new_link->next = st->first;
	st->first = new_link;
	st->count++;
}

int pop(struct stack* st) {
	struct node* ptr = st->first;
	int popped_elem = ptr->element;
	st->first = st->first->next;
	free(ptr);
	return popped_elem;	
}

void printStack(struct stack* st) {
	struct node* ptr = st->first;
	printf("Stack (Top to Bottom): [");
	while(ptr!=NULL) {
		printf("%d, ",ptr->element);	
		ptr = ptr->next;
	}
	printf(" ]\n");
}

void printStackToFile(struct stack* st, FILE* fp) {
	struct node* ptr = st->first;
	fprintf(fp, "Stack (Top to Bottom): [");
	while(ptr!=NULL) {
		fprintf(fp, "%d, ", ptr->element);	
		ptr = ptr->next;
	}
	fprintf(fp, " ]\n");
}

int searchStack(struct stack* st, int elem) {
	int found = 0;
	struct node* ptr = st->first;
	while(ptr!=NULL) {
		if (ptr->element == elem) {
			found = 1;
			break;
		}
		ptr = ptr->next;
	}
	return found;
}


