/*
 * PriorityQueue.h
 *
 *  Created on: 2018. 2. 20.
 *      Author: user
 */

#ifndef PQUEUE_PRIORITYQUEUE_H_
#define PQUEUE_PRIORITYQUEUE_H_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef int PriorityType;

typedef struct tagPQNode {
	PriorityType priority;
	void* data;
} PQNode;

typedef struct tagPriorityQueue {
	PQNode* nodes;
	int capa;
	int usedSize;
} PriorityQueue;

PriorityQueue* createQueue(int initSize);
void destroyQueue(PriorityQueue* pq);
void enqueue(PriorityQueue* pq, PQNode newNode);
void dequeue(PriorityQueue* pq, PQNode* root);
int PQ_getParent(int index);
int PQ_getLeftChild(int index);
void PQ_swapNodes(PriorityQueue* pq, int index1, int index2);
int isEmpty(PriorityQueue* pq);
void printNode(PQNode* node);

#endif /* PQUEUE_PRIORITYQUEUE_H_ */
