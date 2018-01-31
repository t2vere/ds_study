/*
 * ExpTree.c
 *
 *  Created on: 2018. 1. 31.
 *      Author: user
 */


#include "ExpTree.h"

EtNode* ET_createNode(char data) {
	EtNode* node = (EtNode*) malloc(sizeof(EtNode));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void ET_destroyNode(EtNode* node) {
	free(node);
}

void ET_destroyTree(EtNode* node) {
	if (node == NULL) {
		return;
	}

	ET_destroyTree(node->left);
	ET_destroyTree(node->right);
	ET_destroyNode(node);
}

void ET_preOrderPrintTree(EtNode* node) {
	if (node == NULL) {
		return;
	}


}

void ET_postOrderPrintTree(EtNode* node) {
	if (node == NULL) {
		return;
	}


}

void ET_inOrderPrintTree(EtNode* node) {
	if (node == NULL) {
		return;
	}

	printf(" (");
	ET_inOrderPrintTree(node->left);
	printf(" %c", node->data);
	ET_inOrderPrintTree(node->right);
	printf(" )");
}

void ET_buildExpressionTree(char* postfixExpression, EtNode** node) {

}

double ET_evaluate(EtNode* tree) {
	return 0;
}

