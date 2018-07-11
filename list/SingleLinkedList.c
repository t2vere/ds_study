/*
 * SingleLinkedList.c
 *
 *  Created on: 2018. 7. 11.
 *      Author: user
 */


#include "SingleLinkedList.h"

SLLNode* SLL_createNode(ElementType data) {
	SLLNode* newNode = (SLLNode*) malloc(sizeof(SLLNode));
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

void SLL_appendNode(SLLNode** head, SLLNode* newNode) {
	if ((*head) == NULL) {
		*head = newNode;
		return;
	}

	SLLNode* tail = (*head);
	while (tail->next != NULL) {
		tail  = tail->next;
	}

	tail->next = newNode;
}

void SLL_insertNode(SLLNode* currentNode, SLLNode* newNode) {
	newNode->next = currentNode->next;
	currentNode->next = newNode;
}

void SLL_insertNewHead(SLLNode** head, SLLNode* newNode) {
	if ((*head) == NULL) {
		*head = newNode;
		return;
	}

	newNode->next = (*head)->next;
	(*head) = newNode;
}

void SLL_destroyNode(SLLNode* node) {
	free(node);
}

void SLL_removeNode(SLLNode** head, SLLNode* removeNode) {
	if ((*head) == NULL) {
		return;
	}

	if ((*head) == removeNode) {
		(*head)->next = NULL;
		return;
	}

	SLLNode* current = *head;
	while (current->next != removeNode) {
		current = current->next;
	}

	if (current != NULL) {
		current->next = removeNode->next;
		removeNode->next = NULL;
	}

}

SLLNode* SLL_getNodeAt(SLLNode* head, int location) {
	SLLNode* current = head;

	while (current != NULL && location >= 0) {
		current = current->next;
		location--;
	}

	return current;
}

int SLL_getNodeCount(SLLNode* head) {
	int count = 0;
	SLLNode* current = head;

	while (current->next != NULL) {
		current = current->next;
		count++;
	}

	return count;
}
