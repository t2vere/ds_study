/*
 * TestSBTree.c
 *
 *  Created on: 2018. 1. 31.
 *      Author: user
 */

#include "SBTree.h"

int main(void) {

	SbtNode* a = SBT_createNode('A');
	SbtNode* b = SBT_createNode('B');
	SbtNode* c = SBT_createNode('C');
	SbtNode* d = SBT_createNode('D');
	SbtNode* e = SBT_createNode('E');
	SbtNode* f = SBT_createNode('F');
	SbtNode* g = SBT_createNode('G');

	a->left = b;
	b->left = c;
	b->right = d;

	a->right = e;
	e->left = f;
	e->right = g;

	printf("pre-order : ");
	SBT_preOrderPrint(a);
	printf("\n");

	printf("post-order : ");
	SBT_postOrderPrint(a);
	printf("\n");

	printf("in-order : ");
	SBT_inOrderPrint(a);
	printf("\n");

	SBT_destroyTree(a);

	return 0;
}
