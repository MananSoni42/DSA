#include <stdio.h>

struct node {
	int element;
	struct node *next;
};

struct linkedList {
	int count;
	struct node *first;
};

// function declarations
void insertFirst (struct linkedList*,int);
struct node * deleteFirst(struct linkedList*);
void printList (struct linkedList*);
int search (struct linkedList*,int);
struct node* delete_elem (struct linkedList*,int);
