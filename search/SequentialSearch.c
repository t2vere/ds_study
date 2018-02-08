/*
 * SequentialSearch.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: user
 */

#include "SequentialSearch.h"


Node* SLL_sequentialSearch(Node* head, int target) {
	Node* current = head;
	Node* matched = NULL;

	while (current != NULL) {
		if (current->data == target) {
			matched = current;
			break;
		} else {
			current = current->next;
		}

	}

	return matched;
}

Node* SLL_moveToFront(Node** head, int target) {
	Node* curr = (*head);
	Node* prev = NULL;
	Node* matched = NULL;

	while (curr != NULL) {
		if (curr->data == target) {
			matched = curr;

			if (prev != NULL) {
				prev->next = matched->next;
				matched->next = (*head);
			}
			break;
		}

		prev = curr;
		curr = curr->next;
	}

	return matched;
}

Node* SLL_transpose(Node** head, int target) {
	Node* curr = (*head);
	Node* pprev = NULL;
	Node* prev = NULL;
	Node* matched = NULL;

	while (curr != NULL) {
		if (curr->data == target) {
			matched = curr;

			if (prev != NULL) {
				if (pprev != NULL) {
					pprev->next = curr;
				} else {
					(*head) = curr;
				}
				prev->next = curr->next;
				curr->next = prev;
			}

			break;
		}

		if (prev != NULL) {
			pprev = prev;
		}
		prev = curr;
		curr = curr->next;
	}

	return matched;
}

Node* SLL_frequencyCount(Node** head, int target) {
	Node* curr = (*head);
	Node* prev = NULL;
	Node* matched = NULL;

	while (curr != NULL) {
		if (curr->data == target) {
			curr->count++;
			matched = curr;

			if (prev != NULL) {
				prev->next = curr->next;
				SLL_frequencyCountSort(head, curr); // 재배치
			} else {
				(*head) = curr;
			}
			break;
		}

		prev = curr;
		curr = curr->next;
	}

	return matched;
}

void SLL_frequencyCountSort(Node** head, Node* node) {
	Node* curr = (*head);
	Node* prev = NULL;

	while (curr != NULL) {
		if (prev == NULL && curr->count <= node->count) {
			(*head) = curr;
			break;
		} else if (prev != NULL
				&& prev->count > node->count
				&& curr->count <= node->count) {
			node->next = curr;
			prev->next = node;
			break;
		}

		prev = curr;
		curr = curr->next;
	}

	prev->next = node;
}

