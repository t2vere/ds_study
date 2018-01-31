/*
 * TestLCRSTree.c
 *
 *  Created on: 2018. 1. 31.
 *      Author: user
 */


#include "LCRSTree.h"

int main(void) {

	LcrsNode* root = LCRS_createNode('A');
	LcrsNode* b = LCRS_createNode('B');
	LcrsNode* c = LCRS_createNode('C');
	LcrsNode* d = LCRS_createNode('D');
	LcrsNode* e = LCRS_createNode('E');
	LcrsNode* f = LCRS_createNode('F');
	LcrsNode* g = LCRS_createNode('G');
	LcrsNode* h = LCRS_createNode('H');
	LcrsNode* i = LCRS_createNode('I');
	LcrsNode* j = LCRS_createNode('J');
	LcrsNode* k = LCRS_createNode('K');

	LCRS_addChildNode(root, b);
		LCRS_addChildNode(b, c);
		LCRS_addChildNode(b, d);
			LCRS_addChildNode(d, e);
			LCRS_addChildNode(d, f);

	LCRS_addChildNode(root, g);
		LCRS_addChildNode(g, h);

	LCRS_addChildNode(root, i);
		LCRS_addChildNode(i, j);
			LCRS_addChildNode(j, k);

	LCRS_printTree(root, 0);

	LCRS_destroyTree(root);

	return 0;
}
