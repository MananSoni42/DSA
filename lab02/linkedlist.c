#include "linkedlist.h"

void insertFirst(struct linkedList *list, int elem) {
	struct node* new_link = (struct node*)malloc(sizeof(struct node));
	new_link->element = elem;
	new_link->next = list->first;
	list->first = new_link;
	list->count++;
}

struct node* deleteFirst(struct linkedList* list) {
	struct node* ptr = list->first;
	list->first = list->first->next;
	return ptr;	
}

void printList(struct linkedList* list) {
	struct node* ptr = list->first;
	printf("LL: [");
	while(ptr!=NULL) {
		printf("%d, ",ptr->element);	
		ptr = ptr->next;
	}
	printf(" ]\n");
}

int search(struct linkedList* list, int elem) {
	int found = 0;
	struct node* ptr = list->first;
	while(ptr!=NULL) {
		if (ptr->element == elem) {
			found = 1;
			break;
		}
		ptr = ptr->next;
	}
	return found;
}

struct node* delete_elem(struct linkedList* list, int elem) {
	struct node* ptr1 = list->first;
	struct node* ptr2 = list->first->next;
	while(ptr2!=NULL) {
		if (ptr2->element == elem) {
			ptr1->next = ptr2->next;
			break;
		}
		ptr1 = ptr2;
		ptr2 = ptr2->next;
	}
	return ptr2;
}

