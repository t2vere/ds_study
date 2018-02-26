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


typedef char* ChainKeyType;
typedef char* ChainValueType;

typedef struct tagChainNode {
	ChainKeyType key;
	ChainValueType value;

	struct tagChainNode* next;
} ChainNode;

typedef ChainNode* List;

typedef struct tagChainHashTable {
	int tableSize;
	List* table;
} ChainHashTable;

ChainHashTable* CHT_createHashTable(int size);
void CHT_destroyHashTable(ChainHashTable* tab);

ChainNode* CHT_createNode(ChainKeyType key, ChainValueType value);
void CHT_destroyNode(ChainNode* node);

void CHT_set(ChainHashTable* table, ChainKeyType key, ChainValueType value);
ChainValueType CHT_get(ChainHashTable* table, ChainKeyType key);
int CHT_hash(ChainKeyType key, int tableSize);

#endif /* HASHTABLE_CHAINING_H_ */
