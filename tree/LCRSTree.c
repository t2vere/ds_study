/*
 * LCRSTree.c
 *
 *  Created on: 2018. 1. 31.
 *      Author: user
 */

#include "LCRSTree.h"

LcrsNode* LCRS_createNode(char data) {
	LcrsNode* node = (LcrsNode*) malloc(sizeof(LcrsNode));
	node->leftChild = NULL;
	node->rightSibling = NULL;
	node->data = data;

	return node;
}

void LCRS_destroyNode(LcrsNode* node) {
	free(node);
}

void LCRS_destroyTree(LcrsNode* root) {
	if (root->rightSibling != NULL) {
		LCRS_destroyTree(root->rightSibling);
	}

	if (root->leftChild != NULL) {
		LCRS_destroyTree(root->leftChild);
	}

	root->leftChild = NULL;
	root->rightSibling = NULL;

	LCRS_destroyNode(root);
}

void LCRS_addChildNode(LcrsNode* parent, LcrsNode* child) {
	if (parent->leftChild == NULL) {
		parent->leftChild = child;
	} else {
		LcrsNode* tmpNode = parent->leftChild; // parent의 child부터 시작
		while (tmpNode->rightSibling != NULL) {
			tmpNode = tmpNode->rightSibling;
		}

		tmpNode->rightSibling = child;
	}
}

void LCRS_printTree(LcrsNode* node, int depth) {
	int i = 0;

	for (i = 0; i < depth; i++) {
		printf("____");
	}

	printf("%c\n", node->data);

	if (node->leftChild != NULL) {
		LCRS_printTree(node->leftChild, depth + 1);
	}

	if (node->rightSibling != NULL) {
		LCRS_printTree(node->rightSibling, depth);
	}
}
