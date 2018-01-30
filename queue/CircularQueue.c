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
	(*queue)->nodes = (Node*) malloc(sizeof(Node) * (capa + 1)); // Node �迭 ���, ���� ��带 ���� ���� ��� �������� +1
}

void CQ_destroyQueue(CircularQueue* queue) {
	free(queue->nodes);
	free(queue);
}

void CQ_enqueue(CircularQueue* queue, int data) {
	int pos = 0;

	if (queue->rear == queue->capa + 1) { // �� ���� ���� ��� rear index�� ó������
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
	} else { // rear index�� �տ� ���� ��
		return (queue->rear + 1) == queue->front; // ���� ��带 �����ؼ� front ��ġ�� ������
	}
}

int CQ_getSize(CircularQueue* queue) {
	if (queue->front <= queue->rear) { // rear index�� �ڿ� ���� ��
		return queue->rear - queue->front;
	} else { // rear index�� �տ� ���� ��, rear + (��ü size���� front�� �� ��ŭ)
		return queue->rear + (queue->capa - queue->front) + 1;
	}
}
