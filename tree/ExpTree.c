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

	printf(" %c", node->data);
	ET_preOrderPrintTree(node->left);
	ET_preOrderPrintTree(node->right);
}

void ET_postOrderPrintTree(EtNode* node) {
	if (node == NULL) {
		return;
	}

	ET_postOrderPrintTree(node->left);
	ET_postOrderPrintTree(node->right);
	printf(" %c", node->data);
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
	// EtNode* newNode = NULL;

	int len = strlen(postfixExpression);
	char token = postfixExpression[len - 1];
	postfixExpression[len - 1] = '\0';

	switch (token) {
		case '+':
		case '-':
		case '*':
		case '/':
			*node = ET_createNode(token);
			ET_buildExpressionTree(postfixExpression, &(*node)->right);
			ET_buildExpressionTree(postfixExpression, &(*node)->left);
			break;

		default:
			*node = ET_createNode(token);
			break;
	}
}

double ET_evaluate(EtNode* tree) {
	char temp[2];

	double left = 0, right = 0, result = 0;

	if (tree == NULL) {
		return 0;
	}

	switch (tree->data) {
		case '+':
		case '-':
		case '*':
		case '/':
			left = ET_evaluate(tree->left);
			right = ET_evaluate(tree->right);

			if (tree->data == '+') result = left + right;
			else if (tree->data == '-') result = left - right;
			else if (tree->data == '*') result = left * right;
			else if (tree->data == '/') result = left / right;

			break;
		default:
			memset(temp, 0, sizeof(temp));
			temp[0] = tree->data;
			result = atof(temp);

			break;
	}

	return result;
}

