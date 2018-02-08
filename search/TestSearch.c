/*
 * TestSearch.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: user
 */


#include "SequentialSearch.h"

void testSeqSearch(void) {

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

	printf("Sequential Search.\n");
	printList(node1);
	Node* search = SLL_sequentialSearch(node1, 101);
	printf("%d\n", search->data);
	printList(node1);

	printf("\n\nMove to front method.\n");
	printList(node1);
	search = SLL_moveToFront(&node1, 101);
	printf("%d\n", search->data);
	printList(node1);

	printf("\n\nTranspose method.\n");
	printList(node1);
	search = SLL_transpose(&node1, 800);
	printf("%d\n", search->data);
	printList(node1);

	printf("\n\nFrequency count method.\n");
	printList(node1);
	search = SLL_frequencyCount(&node1, 111);
	printList(node1);
	search = SLL_frequencyCount(&node1, 234);
	printList(node1);
	search = SLL_frequencyCount(&node1, 111);
	printList(node1);
	search = SLL_frequencyCount(&node1, 800);
	printList(node1);
	search = SLL_frequencyCount(&node1, 111);
	printList(node1);
	search = SLL_frequencyCount(&node1, 234);
	printList(node1);

	printf("\n\n");
}

