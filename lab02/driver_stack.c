#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[]) {
	FILE * fileptr = fopen(argv[1], "r");
	struct stack *head = (struct stack *) malloc (sizeof(struct stack));
	while (!feof(fileptr)) {
		int temp;
		fscanf(fileptr, "%d ", &temp);
		push(head,temp);
	}
	fclose(fileptr);
	
	// print the stack.
	printStack(head);
	// pop an element.
	int elem = pop(head);
	printf("Popped: %d\n", elem);
	// print the stack.
	printStack(head);
}
