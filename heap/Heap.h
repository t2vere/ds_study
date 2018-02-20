/*
 * Heap.h
 *
 *  Created on: 2018. 2. 20.
 *      Author: user
 */

#ifndef HEAP_HEAP_H_
#define HEAP_HEAP_H_

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int ElementType;

typedef struct tagHeapNode {
	ElementType data;
} HeapNode;

typedef struct tagHeap {
	HeapNode* node;
	int capa;
	int usedSize;
} Heap;

Heap* createHeap(int initSize);
void destroyHeap(Heap* heap);
void insertHeap(Heap* heap, ElementType newData);
void deleteMinimum(Heap* heap, HeapNode* root);
int getParent(int index);
int getLeftChild(int index);
void swapNodes(Heap* head, int index1, int index2);
void printNodes(Heap* heap);

#endif /* HEAP_HEAP_H_ */
