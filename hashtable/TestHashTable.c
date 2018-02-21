/*
 * TestHashTable.c
 *
 *  Created on: 2018. 2. 21.
 *      Author: user
 */


#include "SimpleHashTable.h"

void testSimpleHashTable(void) {
	HashTable* table = SHT_createHashTable(193);

	SHT_set(table, 418, 32114);
	SHT_set(table, 9, 514);
	SHT_set(table, 27, 8917);
	SHT_set(table, 1031, 286);

	printf("key: %d, value: %d\n", 418, SHT_get(table, 418));
	printf("key: %d, value: %d\n", 9, SHT_get(table, 9));
	printf("key: %d, value: %d\n", 27, SHT_get(table, 27));
	printf("key: %d, value: %d\n", 1031, SHT_get(table, 1031));

	printf("key: %d, value: %d\n", 100, SHT_get(table, 100)); // 없는 key

	SHT_destroyHashTable(table);
}
