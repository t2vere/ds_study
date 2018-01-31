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

void CQ_enqueue(CircularQueue* queue, int data) {
	int pos = 0;

	if (queue->rear == queue->capa + 1) { // 빈 공간 없을 경우 rear index를 처음으로
		queue->rear = 0;
		pos = 0;
	} else {
		pos = queue->rear++;
	}

	queue->nodes[pos].data = data;
}

int CQ_dequeue(CircularQueue* queue) {
	int pos = queue->front;

	if (queue->front == queue->capa) {
		queue->front = 0;
	} else {
		queue->front++;
	}

	return queue->nodes[pos].data;
}

int CQ_isEmpty(CircularQueue* queue) {
	return (queue->front == queue->rear);
}

int CQ_isFull(CircularQueue* queue) {
	if (queue->front < queue->rear) {
		return (queue->rear - queue->front) == queue->capa;
	} else { // rear index가 앞에 있을 때
		return (queue->rear + 1) == queue->front; // 구분 노드를 포함해서 front 위치와 같은지
	}
}

int CQ_getSize(CircularQueue* queue) {
	if (queue->front <= queue->rear) { // rear index가 뒤에 있을 때
		return queue->rear - queue->front;
	} else { // rear index가 앞에 있을 때, rear + (전체 size에서 front를 뺀 만큼)
		return queue->rear + (queue->capa - queue->front) + 1;
	}
}
