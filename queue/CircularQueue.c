/*
 * CircularQueue.c
 *
 *  Created on: 2018. 1. 30.
 */

#include "CircualrQueue.h"

void CQ_createQueue(CircularQueue** queue, int capa) {
	*queue = (CircularQueue*) malloc(sizeof(CircularQueue));
	(*queue)->capa = 0;
	(*queue)->front = 0;
	(*queue)->rear = 0;
	(*queue)->nodes = (Node*) malloc(sizeof(Node) * (capa + 1)); // Node 배열 사용, 구분 노드를 위해 실제 노드 개수보다 +1
}

void CQ_destroyQueue(CircularQueue* queue) {
	free(queue->nodes);
	free(queue);
}

Node* CQ_createNode(int data) {
	return NULL;
}

void CQ_destroyNode(Node* node) {}

void CQ_enqueue(CircularQueue* queue, Node* newNode) {}

Node* CQ_dequeue(CircularQueue* queue) {
	return NULL;
}

int CQ_isEmpty(CircularQueue* queue) {
	return 0;
}

int CQ_isFull(CircularQueue* queue) {
	return 0;
}
