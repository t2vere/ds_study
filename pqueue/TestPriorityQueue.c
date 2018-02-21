/*
 * TestPriorityQueue.c
 *
 *  Created on: 2018. 2. 20.
 *      Author: user
 */


#include "PriorityQueue.h"


void testPriorityQueue(void) {
	PriorityQueue* pq = createQueue(3);
	PQNode popped;

	PQNode nodes[7] = {
			{35, (void*) "CODE"}
			, {13, (void*) "WATER"}
			, {90, (void*) "MEAT"}
			, {48, (void*) "CALL"}
			, {37, (void*) "WORK"}
			, {66, (void*) "PLAY"}
	};

	enqueue(pq, nodes[0]);
	enqueue(pq, nodes[1]);
	enqueue(pq, nodes[2]);
	enqueue(pq, nodes[3]);
	enqueue(pq, nodes[4]);
	enqueue(pq, nodes[5]);

	printf("task count in queue: %d\n\n", pq->usedSize);

	while (!isEmpty(pq)) {
		dequeue(pq, &popped);
		printNode(&popped);
	}
}
