/*
 * ExpTree.h
 *
 *  Created on: 2018. 1. 31.
 *      Author: user
 */

#ifndef TREE_EXPTREE_H_
#define TREE_EXPTREE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagEtNode {
	struct tagEtNode* left;
	struct tagEtNode* right;
	char data; // 한 자리만 처리 가능

} EtNode;
// 연산 종류 : create, destroy, print(3가지 종류), build, evaluate

EtNode* ET_createNode(char data);
void ET_destroyNode(EtNode* node);
void ET_destroyTree(EtNode* node);

void ET_preOrderPrintTree(EtNode* node);
void ET_postOrderPrintTree(EtNode* node);
void ET_inOrderPrintTree(EtNode* node);

void ET_buildExpressionTree(char* postfixExpression, EtNode** node);
double ET_evaluate(EtNode* tree);

#endif /* TREE_EXPTREE_H_ */
