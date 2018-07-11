/*
 * TestLinkedList.c
 *
 *  Created on: 2018. 7. 11.
 *      Author: user
 */


#include "SingleLinkedList.h"

void testSingleLinkedList(void) {

	printf("start\n");

	SLLNode* list;
	SLLNode* newNode;
	SLLNode* current;

	// node 5개 추가
	for (int i = 0; i < 5; i++) {
		printf("appended..%d\n", i);
		newNode = SLL_createNode(i);
		SLL_appendNode(&list, newNode);
	}

	newNode = SLL_createNode(-1);
	SLL_insertNewHead(&list, newNode);

	newNode = SLL_createNode(-2);
	SLL_insertNewHead(&list, newNode);

	int count = SLL_getNodeCount(list);
	printf("count: %d\n", count);

	for (int i = 0; i < count; i++) {
		current = SLL_getNodeAt(list, count);
		printf("List[%d] : %d\n", i, current->data);
	}
}

