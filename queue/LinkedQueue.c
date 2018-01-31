#include "LinkedQueue.h"

void LQ_createQueue(LinkedQueue** queue) {
	*queue = (LinkedQueue*) malloc(sizeof(LinkedQueue));
	(*queue)->front = NULL;
	(*queue)->rear = NULL;
	(*queue)->count = 0;
}

void LQ_destroyQueue(LinkedQueue* queue) {
	while (!LQ_isEmpty(queue)) {
		Node* popped = LQ_dequeue(queue);
		LQ_destroyNode(popped);
	}

	free(queue);
}

Node* LQ_createNode(char* data) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->data = (char*) malloc(strlen(data) + 1);
	strcpy(newNode->data, data);
	newNode->next = NULL;

	return newNode;
}

void LQ_destroyNode(Node* node) {
	free(node->data);
	free(node);
}

void LQ_enqueue(LinkedQueue* queue, Node* newNode) {
	if (queue->front == NULL) { // empty queue
		queue->front = newNode;
		queue->rear = newNode;
	} else {
		queue->rear->next = newNode;
		queue->rear = newNode;
	}

	queue->count++;
}

Node* LQ_dequeue(LinkedQueue* queue) {
	Node* front = queue->front;
	if (queue->front->next == NULL) { // front 제거하면 빈 큐가 되는 경우
		queue->front = NULL;
		queue->rear = NULL;
	} else {
		queue->front = queue->front->next;
	}
	queue->count--;

	return front;
}

int LQ_isEmpty(LinkedQueue* queue) {
	return (queue->front == NULL);
}
