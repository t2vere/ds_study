/*
 * SBTree.h
 *
 *  Created on: 2018. 1. 31.
 *      Author: user
 */

#ifndef TREE_SBTREE_H_
#define TREE_SBTREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tagSbtNode {
	char data;
	struct tagSbtNode* left;
	struct tagSbtNode* right;
} SbtNode;

// 연산 종류 : create, destroy, preorder, inorder, postorder

SbtNode*	SBT_createNode(char data);
void		SBT_destroyNode(SbtNode* node);
void		SBT_destroyTree(SbtNode* root);
void		SBT_preOrderPrint(SbtNode* node);
void		SBT_inOrderPrint(SbtNode* node);
void		SBT_postOrderPrint(SbtNode* node);

#endif /* TREE_SBTREE_H_ */
