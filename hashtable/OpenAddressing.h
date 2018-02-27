/*
 * OpenAddressing.h
 *
 *  Created on: 2018. 2. 26.
 *      Author: user
 */

#ifndef HASHTABLE_OPENADDRESSING_H_
#define HASHTABLE_OPENADDRESSING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* OpenAddrKeyType;
typedef char* OpenAddrValueType;

enum ElementStatus {
	EMPTY = 0
	, OCCUPIED = 1
};

typedef struct tagOpenAddrElementType {
	OpenAddrKeyType key;
	OpenAddrValueType value;

	enum ElementStatus status;
} OpenAddrElementType;

typedef struct tagOpenAddrHashTable {
	int occupiedCount;
	int tableSize;

	OpenAddrElementType* table;
} OpenAddrHashTable;

OpenAddrHashTable* OAHT_createHashTable(int tableSize);
void OAHT_destroyHashTable(OpenAddrHashTable* ht);
void OAHT_clearElement(OpenAddrElementType* element);

void OAHT_set(OpenAddrHashTable** ht, OpenAddrKeyType key, OpenAddrValueType value);
OpenAddrValueType OAHT_get(OpenAddrHashTable* ht, OpenAddrKeyType key);
int OAHT_hash(OpenAddrKeyType key, int tableSize);
int OAHT_hash2(OpenAddrKeyType key, int tableSize);

void OAHT_rehash(OpenAddrHashTable** ht);


#endif /* HASHTABLE_OPENADDRESSING_H_ */
