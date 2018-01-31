/*
 * LCRSTree.h
 *
 *  Created on: 2018. 1. 31.
 */

#ifndef TREE_LCRSTREE_H_
#define TREE_LCRSTREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tagLcrsNode {
	char data;
	struct tagLcrsNode* leftChild;
	struct tagLcrsNode* rightSibling;
} LcrsNode;

LcrsNode* LCRS_createNode(char data);
void LCRS_destroyNode(LcrsNode* node);
void LCRS_destroyTree(LcrsNode* root);
void LCRS_addChildNode(LcrsNode* parent, LcrsNode* child);
void LCRS_printTree(LcrsNode* node, int depth);

#endif /* TREE_LCRSTREE_H_ */
