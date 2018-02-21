/*
 * SimpleHashTable.h
 *
 * Division Method
 *
 *  Created on: 2018. 2. 21.
 *      Author: user
 */

#ifndef HASHTABLE_SIMPLEHASHTABLE_H_
#define HASHTABLE_SIMPLEHASHTABLE_H_

#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;
typedef int ValueType;

typedef struct tagNode {
	KeyType key;
	ValueType value;
} Node;

typedef struct tagHashTable {
	int tableSize;
	Node* table;
} HashTable;

HashTable* SHT_createHashTable(int size);
void SHT_set(HashTable* tab, KeyType key, ValueType value);
ValueType SHT_get(HashTable* tab, KeyType key);
void SHT_destroyHashTable(HashTable* tab);
int SHT_hash(KeyType key, int size);

#endif /* HASHTABLE_SIMPLEHASHTABLE_H_ */
