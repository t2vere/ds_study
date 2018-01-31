/*
 * SBTree.c
 *
 *  Created on: 2018. 1. 31.
 *      Author: user
 */

#include "SBTree.h"

SbtNode* SBT_createNode(char data) {
	SbtNode* node = (SbtNode*) malloc(sizeof(SbtNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void SBT_destroyNode(SbtNode* node) {
	free(node);
}

void SBT_destroyTree(SbtNode* root) { // post order로 제거하기
	if (root == NULL) {
		return;
	}

	SBT_destroyTree(root->left);
	SBT_destroyTree(root->right);
	SBT_destroyNode(root);
}

void SBT_preOrderPrint(SbtNode* node) {
	if (node == NULL) {
		return;
	}

	printf("%c ", node->data);
	SBT_preOrderPrint(node->left);
	SBT_preOrderPrint(node->right);
}

void SBT_inOrderPrint(SbtNode* node) {
	if (node == NULL) {
		return;
	}

	SBT_inOrderPrint(node->left);
	printf("%c ", node->data);
	SBT_inOrderPrint(node->right);
}

void SBT_postOrderPrint(SbtNode* node) {
	if (node == NULL) {
		return;
	}

	SBT_postOrderPrint(node->left);
	SBT_postOrderPrint(node->right);
	printf("%c ", node->data);
}

