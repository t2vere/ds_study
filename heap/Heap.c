/*
 * Heap.c
 *
 *  Created on: 2018. 2. 20.
 *      Author: user
 */

#include "Heap.h"


Heap* createHeap(int initSize) {
	Heap* heap = (Heap*) malloc(sizeof(Heap));
	heap->capa = initSize;
	heap->usedSize = 0;
	heap->nodes = (HeapNode*) malloc(sizeof(HeapNode) * heap->capa);

	printf("created heap, size: %d\n", sizeof(HeapNode));

	return heap;
}

void destroyHeap(Heap* heap) {
	free(heap->nodes);
	free(heap);
}

void insertHeap(Heap* heap, ElementType newData) {
	int currentPos = heap->usedSize;
	int parentPos = getParent(currentPos);

	if (heap->usedSize == heap->capa) { // heap이 꽉 찬 경우 용량을 2배로 늘이기
		heap->capa *= 2;
		heap->nodes = (HeapNode*) realloc(heap->nodes, sizeof(HeapNode) * heap->capa);
	}

	heap->nodes[currentPos].data = newData;

	while (currentPos > 0
			&& heap->nodes[currentPos].data < heap->nodes[parentPos].data) { // 완전 이진 트리 규칙 만족할 때까지
		swapNodes(heap, currentPos, parentPos);

		currentPos = parentPos;
		parentPos = getParent(currentPos);
	}

	heap->usedSize++;
}

void deleteMinimum(Heap* heap, HeapNode* root) {
	int parentPos = 0;
	int leftPos = 0;
	int rightPos = 0;

	memcpy(root, &heap->nodes[0], sizeof(HeapNode));
	memset(&heap->nodes[0], 0, sizeof(HeapNode));

	heap->usedSize--;
	swapNodes(heap,  0, heap->usedSize);
	
	leftPos = getLeftChild(0);
	rightPos = leftPos + 1;
	
	while (1) {
		int selectedChild = 0;
		
		if (leftPos >= heap->usedSize) {
			break;
		}

		if (rightPos >= heap->usedSize) {
			selectedChild = leftPos;
		} else {
			if (heap->nodes[leftPos].data > heap->nodes[rightPos].data) {
				selectedChild = rightPos;
			} else {
				selectedChild = leftPos;
			}
		}

		if (heap->nodes[selectedChild].data < heap->nodes[parentPos].data) {
			swapNodes(heap, parentPos, selectedChild);
			parentPos = selectedChild;
		} else {
			break;
		}

		leftPos = getLeftChild(parentPos);
		rightPos = leftPos + 1;
	}
}

int getParent(int index) {
	return (int) ((index - 1) / 2);
}

int getLeftChild(int index) {
	return (2 * index) + 1;
}

void swapNodes(Heap* heap, int index1, int index2) {
	int nodeSize = sizeof(HeapNode);
	HeapNode* temp = (HeapNode*) malloc(nodeSize);

	memcpy(temp, &heap->nodes[index1], nodeSize);
	memcpy(&heap->nodes[index1], &heap->nodes[index2], nodeSize);
	memcpy(&heap->nodes[index2], temp, nodeSize);

	free(temp);
}

void printNodes(Heap* heap) {
	int i = 0;

	for (i = 0; i < heap->usedSize; i++) {
		printf("%d ", heap->nodes[i].data);
	}

	printf("\n");
}

