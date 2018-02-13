/*
 * BinarySearchTree.c
 *
 *  Created on: 2018. 2. 13.
 *      Author: user
 */


#include "BinarySearchTree.h"

BstNode* BST_createNode(ElementType newData) {
	BstNode* node = (BstNode*) malloc(sizeof(BstNode));
	node->data = newData;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void BST_destroyNode(BstNode* node) {
	free(node);
}

void BST_destroyTree(BstNode* tree) {
	if (tree->right != NULL) {
		BST_destroyTree(tree->right);
	}

	if (tree->left != NULL) {
		BST_destroyTree(tree->left);
	}

	tree->left = NULL;
	tree->right = NULL;

	BST_destroyNode(tree);
}

BstNode* BST_searchNode(BstNode* tree, ElementType target) {
	if (tree == NULL) {
		return NULL;
	}

	if (tree->data < target) {
		return BST_searchNode(tree->right, target);
	} else if (tree->data > target) {
		return BST_searchNode(tree->left, target);
	} else {
		return tree;
	}
}

BstNode* BST_searchMinNode(BstNode* tree) {
	if (tree == NULL) {
		return NULL;
	}

	if (tree->left == NULL) {
		return tree;
	} else {
		return BST_searchMinNode(tree->left);
	}
}

void BST_insertNode(BstNode* tree, BstNode* child) {
	if (tree->data < child->data) {
		if (tree->right == NULL) {
			tree->right = child;
		} else {
			BST_insertNode(tree->right, child);
		}
	}

	if (tree->data > child->data) {
		if (tree->left == NULL) {
			tree->left = child;
		} else {
			BST_insertNode(tree->left, child);
		}
	}
}

BstNode* BST_removeNode(BstNode* tree, BstNode* parent, ElementType target) {
	BstNode* removed = NULL;

	if (tree == NULL) {
		return NULL;
	}

	if (tree->data > target) {
		removed = BST_removeNode(tree->left, tree, target);
	} else if (tree->data < target) {
		removed = BST_removeNode(tree->right, tree, target);
	} else {
		removed = tree;

		if (tree->left == NULL && tree->right == NULL) { // 잎 노드는 바로 삭제
			if (parent->left == tree) {
				parent->left = NULL;
			} else {
				parent->right = NULL;
			}
		} else {
			if (tree->left != NULL && tree->right != NULL) { // 양쪽 자식 처리
				BstNode* minNode = BST_searchMinNode(tree->right);
				minNode = BST_removeNode(tree, NULL, minNode->data);
				tree->data = minNode->data;
			} else { // 외자식 처리
				BstNode* temp = NULL;
				if (tree->left != NULL) {
					temp = tree->left;
				} else {
					temp = tree->right;
				}

				if (parent->left == tree) {
					parent->left = temp;
				} else {
					parent->right = temp;
				}
			}
		}

	}

	return removed;
}

void Bst_inorderPrintTree(BstNode* node) {
	if (node == NULL) {
		return;
	}

	Bst_inorderPrintTree(node->left);

	printf("%d ", node->data);

	Bst_inorderPrintTree(node->right);
}
