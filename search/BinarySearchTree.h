/*
 * BinarySearchTree.h
 *
 *  Created on: 2018. 2. 13.
 *      Author: user
 */

#ifndef SEARCH_BINARYSEARCHTREE_H_
#define SEARCH_BINARYSEARCHTREE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagBSTNode {
	struct tagBSTNode* left;
	struct tagBSTNode* right;

	ElementType data;
} BstNode;

/*
 * 이진 탐색 트리의 기본 연산
 *
 * 1. 탐색
 * 2. 노드 삽입
 * 3. 노드 삭제
 *  - 잎 노드
 *  - 양쪽 자식 노드를 갖고 있는 경우 :
 *  - 한쪽 자식 노드만 갖고 있는 경우 : 자식을 부모에게 연결
 *
 */

BstNode*	BST_createNode(ElementType newData);
void		BST_destroyNode(BstNode* node);
void		BST_destroyTree(BstNode* tree);

BstNode*	BST_searchNode(BstNode* tree, ElementType target);
BstNode*	BST_searchMinNode(BstNode* tree);
void		BST_insertNode(BstNode* tree, BstNode* child);
BstNode*	BST_removeNode(BstNode* tree, BstNode* parent, ElementType target);

void		Bst_inorderPrintTree(BstNode* node);


#endif /* SEARCH_BINARYSEARCHTREE_H_ */
