#include <stdio.h>

struct node {
	int element;
	struct node *next;
};

struct stack {
	int count;
	struct node *first;
};

// function declarations
void push (struct stack*,int);
int pop(struct stack*);
void printStack (struct stack*);
int searchStack (struct stack*,int);
