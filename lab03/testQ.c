#include "que.h"

int main() {
	Queue* q = newQ();
	printf("Empty: %d\n",isEmptyQ(q));
	Element e;
	e.id = 1; e.pr = 1;
	q = addQ(q,e);
	e.id = 2; e.pr = 2;
	q = addQ(q,e);
	printQ(q);
	q = delQ(q);
	printQ(q);
	return 0;
}
