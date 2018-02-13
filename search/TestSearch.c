/*
 * TestSearch.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: user
 */


#include "SequentialSearch.h"
#include "BinarySearchTree.h"

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

void testBinarySearchTree(void) {
	BstNode* tree = BST_createNode(123);
	BstNode* node = NULL;

	BST_insertNode(tree, BST_createNode(52));
	BST_insertNode(tree, BST_createNode(7322));
	BST_insertNode(tree, BST_createNode(867));
	BST_insertNode(tree, BST_createNode(82));
	BST_insertNode(tree, BST_createNode(43));
	BST_insertNode(tree, BST_createNode(900));
	BST_insertNode(tree, BST_createNode(2));

	BST_insertNode(tree, BST_createNode(90));
	BST_insertNode(tree, BST_createNode(24));

	BST_insertNode(tree, BST_createNode(5112));
	BST_insertNode(tree, BST_createNode(602));
	BST_insertNode(tree, BST_createNode(1));

	Bst_inorderPrintTree(tree);
	printf("\n");

	printf("remove 123.\n");
	node = BST_removeNode(tree, NULL, 123);
	BST_destroyNode(node);

	Bst_inorderPrintTree(tree);
	printf("\n");

	printf("insert 68.\n");
	BST_insertNode(tree, BST_createNode(68));
	Bst_inorderPrintTree(tree);
	printf("\n");

	BST_destroyTree(tree);
}
