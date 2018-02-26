/*
 * Chaining.h
 *
 *  Created on: 2018. 2. 26.
 *      Author: user
 */

#ifndef HASHTABLE_CHAINING_H_
#define HASHTABLE_CHAINING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef char* KeyType;
typedef char* ValueType;

typedef struct tagNode {
	KeyType key;
	ValueType value;

	struct tagNode* next;
} Node;

typedef Node* List;

typedef struct tagHashTable {
	int tableSize;
	List* table;
} HashTable;

HashTable* CHT_createHashTable(int size);
void CHT_destroyHashTable(HashTable* tab);

Node* CHT_createNode(KeyType key, ValueType value);
void CHT_destroyNode(Node* node);

void CHT_set(HashTable* table, KeyType key, ValueType value);
ValueType CHT_get(HashTable* table, KeyType key);
int CHT_hash(KeyType key, int keyLength, int tableSize);

#endif /* HASHTABLE_CHAINING_H_ */
