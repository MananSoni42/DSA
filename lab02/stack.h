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
void printStackToFile (struct stack*,FILE*);
int searchStack (struct stack*,int);
