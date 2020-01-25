#include "multiq.h"

MultiQ* createMQ(int num) {
	MultiQ* mq = (MultiQ*)malloc(sizeof(MultiQ));
	mq->size = num;
	Mq_node* ptr = mq->q_head;
	Mq_node* temp = NULL;
	for (int i=num-1; i>=0; i--) {
		temp = (Mq_node*)malloc(sizeof(sizeof(Mq_node)));
		temp->q_elem = newQ();
		temp->q_pr = i;
		temp->next = NULL;
		if (ptr == NULL) {
			ptr = temp;
			mq->q_head = ptr;
		}
		else {
			ptr->next = temp;
			ptr = ptr->next;
		}

	}
	return mq;
}

MultiQ* addMQ(MultiQ* mq, Element t) {
	if (t.pr >= mq->size) {
		printf("Error! priority %d exceeds multiQueue of size %d", t.pr, mq->size);
		return mq;
	}
	Mq_node* ptr = mq->q_head;

	if (ptr == NULL) {
		printf("Multi Queue is empty");
	}
	while (ptr->q_pr != t.pr && ptr != NULL) {
		ptr = ptr->next;
	}
	if (ptr == NULL) {
		printf("Could not find Queue with priority %d",t.pr);
		return mq;
	}
	ptr->q_elem = addQ(ptr->q_elem,t);
	return mq;
}

Queue* nextMQ(MultiQ* mq) {
	Mq_node* ptr = mq->q_head;
	while (ptr!=NULL) {
		if (ptr->q_elem->size!=0) {
			break;
		}
		ptr=ptr->next;
	}
	return ptr->q_elem;
}
MultiQ* delNextMQ(MultiQ* mq) {
	Mq_node* ptr=mq->q_head;
	while (ptr!=NULL) {
		if (ptr->q_elem->size!=0) {
			break;
		}
		ptr=ptr->next;
	}
	delQ(ptr->q_elem);
	return mq;
}

bool isEmptyMQ(MultiQ* mq) {
	bool a=true;
	Mq_node* ptr=mq->q_head;
	while (ptr!=NULL) {
		if (ptr->q_elem->size!=0) {
			a = false;
			break;
		}
		ptr = ptr->next;
	}
	return a;
}

int sizeMQ(MultiQ* mq) {
	int count=0;
	Mq_node* ptr=mq->q_head;
	while (ptr!=NULL) {
		count += ptr->q_elem->size;
		ptr = ptr->next;
	}
	return count;
}

int sizeMQbyPriority(MultiQ* mq, int p) {
	Mq_node* ptr=mq->q_head;
	while (ptr->q_pr!=p && ptr!=NULL) {
		ptr=ptr->next;
	}
	return ptr->q_elem->size;
}

Queue* getQueueFromMQ(MultiQ* mq, int p) {
	Mq_node* ptr = mq->q_head;
	while (ptr->q_pr!=p && ptr!=NULL) {
		ptr = ptr->next;
	}
	return ptr->q_elem;
}

void printMQ(MultiQ* mq) {
	printf("\n");
	Mq_node* ptr = mq->q_head;
	while (ptr!=NULL) {
		printf("%d: ",ptr->q_pr); printQ(ptr->q_elem);
		ptr = ptr->next;
	}
}
