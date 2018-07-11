/*
 * SingleLinkedList.h
 *
 *  Created on: 2018. 7. 11.
 *      Author: user
 */

#ifndef LIST_SINGLELINKEDLIST_H_
#define LIST_SINGLELINKEDLIST_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct tagSLLNode {
	ElementType data;
	struct tagSLLNode* next;
} SLLNode;

SLLNode* SLL_createNode(ElementType data);
void SLL_appendNode(SLLNode** head, SLLNode* newNode);
void SLL_insertNode(SLLNode* currentNode, SLLNode* newNode);
void SLL_insertNewHead(SLLNode** head, SLLNode* newNode);
void SLL_destroyNode(SLLNode* node);
void SLL_removeNode(SLLNode** head, SLLNode* removeNode);
SLLNode* SLL_getNodeAt(SLLNode* head, int location);
int SLL_getNodeCount(SLLNode* head);

#endif /* LIST_SINGLELINKEDLIST_H_ */
