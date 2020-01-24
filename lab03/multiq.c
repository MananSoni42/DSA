#include "multiq.h"

MultiQ createMQ(int num) {
	MultiQ mq = (MultiQ*)malloc(sizeof(MultiQ));
	mq->size = num;
	return mq;
}

MultiQ addMQ(MultiQ mq, Element t) {
	if (t->pri >= mq->size) {
		printf("Error! priority %d exceeds multiQueue of size %d", t->pri, mq->size);
		return mq;
	}
	addQ(mq[t->pr-1],t);
	return mq;
}

Element nextMQ(MultiQ mq) {
	for (int i=mq->size-1;i>=0;i--) {
		if (!mq[i].isEmptyQ()) {
			return mq[i]->head;
		}
	}
	return NULL;
}

MultiQ delNextMQ(MultiQ mq) {
	for (int i=mq->size-1;i>=0;i--) {
		if (!mq[i].isEmptyQ()) {
			mq[i].delQ();
			return mq;
		}
	}
}

Boolean isEmptyMQ(MultiQ mq) {
	bool a=true;
	for (int i=mq->size-1;i>=0;i--) {
		if (!mq[i].isEmptyQ()) {
			a=false;
		}
	}
	return a;
}

int sizeMQ(MultiQ mq) {
	int count=0;
	for (int i=mq->size-1;i>=0;i--) {
		count += mq[i].lengthQ();
	}
	return count;
}

int sizeMQbyPriority(MultiQueue mq, int p) {
	return mq[p-1].lengthQ();
}

Queue getQueueFromMQ(MultiQ, int p) {
	return mq[p-1];
}
