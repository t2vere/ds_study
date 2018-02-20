/*
 * TestHeap.c
 *
 *  Created on: 2018. 2. 20.
 *      Author: user
 */


#include "Heap.h"

void testHeap(void) {
	Heap* heap = createHeap(6);
	HeapNode minNode;

	insertHeap(heap, 12);
	insertHeap(heap, 87);
	insertHeap(heap, 111);
	insertHeap(heap, 34);
	insertHeap(heap, 16);
	insertHeap(heap, 75);

	printNodes(heap);

	deleteMinimum(heap, &minNode);
	printNodes(heap);

	deleteMinimum(heap, &minNode);
	printNodes(heap);

	deleteMinimum(heap, &minNode);
	printNodes(heap);

	deleteMinimum(heap, &minNode);
	printNodes(heap);

	deleteMinimum(heap, &minNode);
	printNodes(heap);

	deleteMinimum(heap, &minNode);
	printNodes(heap);

}
