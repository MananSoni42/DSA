#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include "ll.h"

bool isLoop(List* ll) { // returns true if the given list has a loop, false otherwise
    if (ll->head == NULL) {
        return false;
    }

    Node *slow = ll->head, *fast = ll->head->next;
    bool loop = false;

    while (slow!=NULL && fast!=NULL && fast->next!=NULL) { //relies on short circuiting for correctness
        if (fast == slow || fast->next == slow) {
            loop = true;
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return loop;
}

void printLoopList(List* ll, int n) { // Only prints the list (looped lists are infinite) till n (= size of LL) and prints cyclic or linear accordingly
    Node* ptr = ll->head;    
    int i=0;
    printf("\nLL: [");
    while(ptr!=NULL && i < n+2) {
        if (ptr->next == NULL) {
            printf("%d",ptr->data);
        }
        else {
            printf("%d, ",ptr->data);
        }
        ptr = ptr->next;
        i++;
    }
    if (ptr == NULL) {
        printf("] linear\n");
    }
    else {
        printf("] cyclic\n");
    }
}

void createLoop(List* ll) { // creates a looped list from a linear list 50% of the time (randomly)
    double rand_num = (double)rand() / (double)RAND_MAX;
    if (rand_num < 0.5) { // creates a loop 50% of the time
        Node *ptr = ll->head, *loop_ptr = ll->head;
        int size=0;

        while (ptr != NULL) { // get the size of the LL
            size+=1;
            ptr = ptr->next;
        } ptr = ll->head;
        
        int ind = rand() % (size+1);
        for (int i=0;i<ind;i++) { // Pointer to a random element in the list
            loop_ptr = loop_ptr->next;
        }
        while(ptr->next != NULL) { // Pointer to the end of a list
            ptr = ptr->next;
        }
        ptr->next = loop_ptr; // point last pointer's next to a random element in the list
    }
}

int main() {
    srand(time(0)); // set a random seed
    List *ll = newList();
    addAfter(ll,0,1);
    addAfter(ll,1,2);
    addAfter(ll,2,3);
    addAfter(ll,3,4);
    addAfter(ll,4,5);
    addAfter(ll,5,6);

    printLoopList(ll,6);
    createLoop(ll);
    printLoopList(ll,6);

    printf("Loop: "); printf(isLoop(ll) ? "true\n" : "false\n");
}
