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

typedef struct tagNode {
	char* data;
	struct tagNode* next;
} Node;

typedef struct tagLinkedQueue {
	Node* front;
	Node* rear;
	int count;
} LinkedQueue;

void LQ_createQueue(LinkedQueue** queue);
void LQ_destroyQueue(LinkedQueue* queue);
Node* LQ_createNode(char* data);
void LQ_destroyNode(Node* node);
void LQ_enqueue(LinkedQueue* queue, Node* newNode);
Node* LQ_dequeue(LinkedQueue* queue);
int LQ_isEmpty(LinkedQueue* queue);

#endif /* QUEUE_LINKEDQUEUE_H_ */
