/*
 * CircualrQueue.h
 *
 *  Created on: 2018. 1. 30.
 */

#ifndef QUEUE_CIRCUALRQUEUE_H_
#define QUEUE_CIRCUALRQUEUE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode {
	int data;
} Node;

typedef struct tagCircularQueue {
	int capa;
	int front;
	int rear;

	Node* nodes;
} CircularQueue;

void CQ_createQueue(CircularQueue** queue, int capa);
void CQ_destroyQueue(CircularQueue* queue);
Node* CQ_createNode(int data);
void CQ_destroyNode(Node* node);
void CQ_enqueue(CircularQueue* queue, Node* newNode);
Node* CQ_dequeue(CircularQueue* queue);
int CQ_isEmpty(CircularQueue* queue);
int CQ_isFull(CircularQueue* queue);

#endif /* QUEUE_CIRCUALRQUEUE_H_ */
