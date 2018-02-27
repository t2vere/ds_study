/*
 * OpenAddressing.c
 *
 *  Created on: 2018. 2. 26.
 *      Author: user
 */


#include "OpenAddressing.h"

OpenAddrHashTable* OAHT_createHashTable(int tableSize) {
	OpenAddrHashTable* ht = (OpenAddrHashTable*) malloc(sizeof(OpenAddrHashTable));
	ht->table = (OpenAddrElementType*) malloc(sizeof(OpenAddrElementType) * tableSize);
	memset(ht->table, 0, sizeof(OpenAddrElementType) * tableSize);

	ht->occupiedCount = 0;
	ht->tableSize = tableSize;

	return ht;
}

void OAHT_clearElement(OpenAddrElementType* element) {
	if (element->status == EMPTY) {
		return;
	}

	free(element->key);
	free(element->value);
}

void OAHT_destroyHashTable(OpenAddrHashTable* ht) {
	int i = 0;

	for (i = 0; i < ht->tableSize; i++) {
		OAHT_clearElement(&(ht->table[i]));
	}

	free(ht->table);
	free(ht);
}

void OAHT_set(OpenAddrHashTable** ht, OpenAddrKeyType key, OpenAddrValueType value) {
	int keyLength, address, stepSize;
	double usage;

	usage = (double) (*ht)->occupiedCount / (*ht)->tableSize;

	if (usage > 0.5) {
		OAHT_rehash(ht);
	}

	keyLength = strlen(key);
	address = OAHT_hash(key, (*ht)->tableSize);
	stepSize = OAHT_hash2(key, (*ht)->tableSize);

	while ((*ht)->table[address].status != EMPTY
			&& strcmp((*ht)->table[address].key, key) != 0) {
		printf("Collision occured! : Key(%s), Address(%d), StepSize(%d)\n", key, address, stepSize);
		address = (address + stepSize) % (*ht)->tableSize;
	}

	(*ht)->table[address].key = malloc(sizeof(char) * (keyLength + 1));
	strcpy((*ht)->table[address].key, key);

	(*ht)->table[address].value = malloc(sizeof(char) * (strlen(value) + 1));
	strcpy((*ht)->table[address].value, value);

	(*ht)->table[address].status = OCCUPIED;
	(*ht)->occupiedCount++;

	printf("Key(%s) entered at address(%d)\n", key, address);
}

OpenAddrValueType OAHT_get(OpenAddrHashTable* ht, OpenAddrKeyType key) {
	int keyLength = strlen(key);
	int address = OAHT_hash(key, ht->tableSize);
	int stepSize = OAHT_hash2(key, ht->tableSize);

	while (ht->table[address].status != EMPTY
			&& strcmp(ht->table[address].key, key) != 0) {
		address = (address + stepSize) % ht->tableSize;
	}

	return ht->table[address].value;
}

int OAHT_hash(OpenAddrKeyType key, int tableSize) {
	int i = 0;
	int hashValue = 0;
	int keyLength = strlen(key);

	for (i = 0; i < keyLength; i++) {
		hashValue = (hashValue << 3) + key[i];
	}

	hashValue %= tableSize;

	return hashValue;
}

int OAHT_hash2(OpenAddrKeyType key, int tableSize) {
	int i = 0;
	int hashValue = 0;
	int keyLength = strlen(key);

	for (i = 0; i < keyLength; i++) {
		hashValue = (hashValue << 2) + key[i];
	}

	hashValue = hashValue % (tableSize - 3);

	return hashValue + 1;
}

void OAHT_rehash(OpenAddrHashTable** ht) {
	int i = 0;
	OpenAddrElementType* oldTable = (*ht)->table;

	OpenAddrHashTable* newHashTable = OAHT_createHashTable((*ht)->tableSize * 2);
	printf("\nRehashed. New table size: %d\n\n", newHashTable->tableSize);

	for (i = 0; i < (*ht)->tableSize; i++) {
		if (oldTable[i].status == OCCUPIED) {
			OAHT_set(&newHashTable, oldTable[i].key, oldTable[i].value);
		}
	}

	OAHT_destroyHashTable((*ht));

	(*ht) = newHashTable;
}
