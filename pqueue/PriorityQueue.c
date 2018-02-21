/*
 * PriorityQueue.c
 *
 *  Created on: 2018. 2. 20.
 *      Author: user
 */


#include "PriorityQueue.h"


PriorityQueue* createQueue(int initSize) {
	PriorityQueue* pq = (PriorityQueue*) malloc(sizeof(PriorityQueue));
	pq->capa = initSize;
	pq->usedSize = 0;
	pq->nodes = (PQNode*) malloc(sizeof(PQNode) * pq->capa);

	return pq;
}

void destroyQueue(PriorityQueue* pq) {
	free(pq->nodes);
	free(pq);
}

void enqueue(PriorityQueue* pq, PQNode newNode) {
	int currPos = pq->usedSize;
	int parentPos = PQ_getParent(currPos);

	if (pq->usedSize == pq->capa) {
		if (pq->capa == 0) {
			pq->capa = 1;
		}

		pq->capa *= 2;
		pq->nodes = (PQNode*) realloc(pq->nodes, sizeof(PQNode) * pq->capa);
	}

	pq->nodes[currPos] = newNode;

	while (currPos > 0
			&& pq->nodes[currPos].priority < pq->nodes[parentPos].priority) {
		PQ_swapNodes(pq, currPos, parentPos);
		currPos = parentPos;
		parentPos = PQ_getParent(currPos);
	}

	pq->usedSize++;
}

void dequeue(PriorityQueue* pq, PQNode* root) {
	int parentPos = 0;
	int leftPos = 0;
	int rightPos = 0;

	memcpy(root, &pq->nodes[0], sizeof(PQNode));
	memset(&pq->nodes[0], 0, sizeof(PQNode));

	pq->usedSize--;
	PQ_swapNodes(pq, 0, pq->usedSize);

	leftPos =  PQ_getLeftChild(0);
	rightPos = leftPos + 1;

	while (1) {
		int selectedChild = 0;

		if (leftPos >= pq->usedSize) {
			break;
		}

		if (rightPos >= pq->usedSize) {
			selectedChild = leftPos;
		} else {
			if (pq->nodes[leftPos].priority > pq->nodes[rightPos].priority) {
				selectedChild = rightPos;
			} else {
				selectedChild = leftPos;
			}
		}

		if (pq->nodes[selectedChild].priority < pq->nodes[parentPos].priority) {
			PQ_swapNodes(pq, parentPos, selectedChild);
			parentPos = selectedChild;
		} else {
			break;
		}

		leftPos = PQ_getLeftChild(parentPos);
		rightPos = leftPos + 1;
	}

	if (pq->usedSize < pq->capa / 2) {
		pq->capa /= 2;
		pq->nodes = (PQNode*) realloc(pq->nodes, sizeof(PQNode) * pq->capa);
	}
}

int PQ_getParent(int index) {
	return (int) ((index - 1) / 2);
}

int PQ_getLeftChild(int index) {
	return (2 * index) + 1;
}

void PQ_swapNodes(PriorityQueue* pq, int index1, int index2) {
	int copySize = sizeof(PQNode);
	PQNode* temp = (PQNode*) malloc(copySize);

	memcpy(temp, &pq->nodes[index1], copySize);
	memcpy(&pq->nodes[index1], &pq->nodes[index2], copySize);
	memcpy(&pq->nodes[index2], temp, copySize);

	free(temp);
}

int isEmpty(PriorityQueue* pq) {
	return (pq->usedSize == 0);
}

void printNode(PQNode* node) {
	printf("task: %s (priority: %d)\n", node->data, node->priority);
}

