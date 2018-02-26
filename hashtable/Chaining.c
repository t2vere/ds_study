/*
 * Chaining.c
 *
 *  Created on: 2018. 2. 26.
 *      Author: user
 */


#include "Chaining.h"

HashTable* CHT_createHashTable(int size) {
	HashTable* tab = (HashTable*) malloc(sizeof(HashTable));
	tab->table = (List*) malloc(sizeof(Node) * size);

	memset(tab->table, 0, sizeof(List) * size);
	tab->tableSize = size;

	return tab;
}

Node* CHT_createNode(KeyType key, ValueType value) {
	Node* node = (Node*) malloc(sizeof(sizeof(Node)));
	node->key = (char*) malloc(sizeof(char) * (strlen(key) + 1));
	strcpy(node->key, key);

	node->value = (char*) malloc(sizeof(char) * (strlen(value) + 1));
	strcpy(node->value, value);
	node->next = NULL;

	return node;
}

void CHT_destroyNode(Node* node) {
	free(node->key);
	free(node->value);
	free(node);
}

void CHT_destroyHashTable(HashTable* tab) {
	// linked list 제거
	int i = 0;
	for (int i = 0; i < tab->tableSize; i++) {
		List list = tab->table[i];
		CHT_destroyNode(list);
	}

	// hash table 제거
	free(tab->table);
	free(tab);
}

void CHT_set(HashTable* table, KeyType key, ValueType value) {
	int address = hash(key, strlen(key), table->tableSize);
	Node* node = CHT_createNode(key, value);

	if (table->table[address] == NULL) {	// 주소가 비어있는 경우
		table->table[address] = node;
	} else {	// 주소가 비어있지 않은 경우
		List list = table->table[address];
		node->next = list;
		table->table[address] = node;

		printf("Collision occured : Key(%s), Address(%d)\n", key, address);
	}
}

ValueType CHT_get(HashTable* table, KeyType key) {
	int address = CHT_hash(key, strlen(key), table->tableSize);
	List list = table->table[address];
	List target = NULL;

	if (list == NULL) {
		return NULL;
	}

	while (1) {
		if (strcmp(list->key, key) == 0) {
			target = list;
			break;
		}

		if (list->next == NULL) {
			break;
		}

		list = list->next;
	}

	return target->value;
}

int CHT_hash(KeyType key, int keyLength, int tableSize) {
	int i = 0;
	int hashValue = 0;

	for (i = 0; i < keyLength; i++) {
		hashValue = (hashValue << 3) + key[i];
	}

	hashValue %= tableSize;

	return hashValue;
}
