/*
 * TestLinkedQueue.c
 *
 *  Created on: 2018. 1. 30.
 */

#include "LinkedQueue.h"

int testLinkedQueue(void) {

	Node* popped = NULL;
	LinkedQueue* queue = NULL;

	LQ_createQueue(&queue);

	LQ_enqueue(queue, LQ_createNode("aaa"));
	LQ_enqueue(queue, LQ_createNode("bba"));
	LQ_enqueue(queue, LQ_createNode("ccc"));
	LQ_enqueue(queue, LQ_createNode("ddx"));
	LQ_enqueue(queue, LQ_createNode("fgg"));

	printf("queue size: %d\n", queue->count);

	printf("dequeue: ");
	while (!LQ_isEmpty(queue)) {
		popped = LQ_dequeue(queue);
		printf("%s\t", popped->data);
	}

	LQ_destroyQueue(queue);

	return 0;
}
