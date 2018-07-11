/*
 * LinkedQueue.h
 *
 *  Created on: 2018. 1. 30.
 */

#ifndef QUEUE_LINKEDQUEUE_H_
#define QUEUE_LINKEDQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagLQNode {
	char* data;
	struct tagLQNode* next;
} LQNode;

typedef struct tagLinkedQueue {
	LQNode* front;
	LQNode* rear;
	int count;
} LinkedQueue;

void LQ_createQueue(LinkedQueue** queue);
void LQ_destroyQueue(LinkedQueue* queue);
LQNode* LQ_createNode(char* data);
void LQ_destroyNode(LQNode* node);
void LQ_enqueue(LinkedQueue* queue, LQNode* newNode);
LQNode* LQ_dequeue(LinkedQueue* queue);
int LQ_isEmpty(LinkedQueue* queue);

#endif /* QUEUE_LINKEDQUEUE_H_ */
