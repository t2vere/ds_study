/*
 * TestSearch.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: user
 */


#include "SequentialSearch.h"
#include "BinarySearch.h"

void testSearch(void) {

	Node* node1 = createNode(240);
	Node* node2 = createNode(700);
	Node* node3 = createNode(111);
	Node* node4 = createNode(234);
	Node* node5 = createNode(800);
	Node* node6 = createNode(101);
	Node* node7 = createNode(229);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;

	Node* search = SLL_sequentialSearch(node1, 101);
	printf("%d\n", search->data);

}
