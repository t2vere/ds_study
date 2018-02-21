/*
 * SimpleHashTable.c
 *
 *  Created on: 2018. 2. 21.
 *      Author: user
 */


#include "SimpleHashTable.h"


HashTable* SHT_createHashTable(int size) {
	HashTable* tab = (HashTable*) malloc(sizeof(HashTable));
	tab->table = (Node*) malloc(sizeof(Node) * size);
	tab->tableSize = size;

	return tab;
}

void SHT_set(HashTable* tab, KeyType key, ValueType value) {
	int address = SHT_hash(key, tab->tableSize);
	tab->table[address].key = key;
	tab->table[address].value = value;
}

ValueType SHT_get(HashTable* tab, KeyType key) {
	int address = SHT_hash(key, tab->tableSize);
	return tab->table[address].value;
}

void SHT_destroyHashTable(HashTable* tab) {
	free(tab->table);
	free(tab);
}

int SHT_hash(KeyType key, int size) {
	return key % size;
}
