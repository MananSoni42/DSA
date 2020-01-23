#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char *argv[]) {
	FILE * fileptr = fopen(argv[1], "r");
	struct linkedList *head = (struct linkedList *) malloc (sizeof(struct linkedList));
	while (!feof(fileptr)) {
		int temp;
		fscanf(fileptr, "%d ", &temp);
		insertFirst(head,temp);
	}
	fclose(fileptr);
	// print the linked list.
	printList(head);
	// delete the first element of the linked list.
	deleteFirst(head);
	// print the linked list again to check if delete was successful.
	printList(head);
	// print the linked list to a new file.
}
