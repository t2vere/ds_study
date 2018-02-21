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
void enqueue(PriorityQueue* pq, PQNode newData);
void dequeue(PriorityQueue* pq, PQNode root);
int getParent(int index);
int getLeftChild(int index);
void swapNodes(PriorityQueue* pq, int index1, int index2);
int isEmpty(PriorityQueue* pq);

#endif /* PQUEUE_PRIORITYQUEUE_H_ */
