/*
 * RedBlackTree.h
 *
 *  Created on: 2018. 2. 13.
 *      Author: user
 */

#ifndef SEARCH_REDBLACKTREE_H_
#define SEARCH_REDBLACKTREE_H_

typedef int ElementType;

typedef struct tagRbtNode {
	struct tagRbtNode* parent;
	struct tagRbtNode* left;
	struct tagRbtNode* right;

	enum {
		RED, BLACK
	} Color;

	ElementType data;
} RbtNode;

#endif /* SEARCH_REDBLACKTREE_H_ */
