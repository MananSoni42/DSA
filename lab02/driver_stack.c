#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[]) {
	FILE * fileptr = fopen(argv[1], "r");
	struct stack *head = (struct stack *) malloc (sizeof(struct stack));
	if (fileptr == NULL) {
		printf("ERROR: Input file could not be read\n");
		exit(1);
	}
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
	// print the stack to a new file.
	if (argc < 3) {
		printf("No output file provided, not printing final stack to any output file\n");
		exit(0);
	}
	FILE* fp = fopen(argv[2],"w");
	if (fp == NULL) {
		printf("ERROR: Output file could not be read\n");
		exit(1);
	}
	printStackToFile(head,fp);
}
