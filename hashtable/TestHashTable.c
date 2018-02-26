/*
 * TestHashTable.c
 *
 *  Created on: 2018. 2. 21.
 *      Author: user
 */


#include "SimpleHashTable.h"
#include "Chaining.h"

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

void testChaining(void) {
	ChainHashTable* ht = CHT_createHashTable(12289);

	CHT_set(ht, "MSFT", "Microsoft Corp.");
	CHT_set(ht, "JAVA", "Sun Microsystems");
	CHT_set(ht, "REDH", "Red Hat Linux");
	CHT_set(ht, "APAC", "Apache Org.");
	CHT_set(ht, "ZYMZZ", "Unisys Ops Check"); // APAC와 충돌
	CHT_set(ht, "IBM", "IBM Ltd.");
	CHT_set(ht, "ORCL", "Oracle Corp.");
	CHT_set(ht, "CSCO", "Cisco Systems, Inc.");
	CHT_set(ht, "GOOG", "Google Inc.");
	CHT_set(ht, "YHOO", "Yahoo! Inc.");
	CHT_set(ht, "NOVL", "Novell, Inc.");

	printf("\n");
	printf("Key: %s, Value: %s\n", "MSFT", CHT_get(ht, "MSFT"));
	printf("Key: %s, Value: %s\n", "JAVA", CHT_get(ht, "JAVA"));
	printf("Key: %s, Value: %s\n", "REDH", CHT_get(ht, "REDH"));
	printf("Key: %s, Value: %s\n", "APAC", CHT_get(ht, "APAC"));
	printf("Key: %s, Value: %s\n", "ZYMZZ", CHT_get(ht, "ZYMZZ"));
	printf("Key: %s, Value: %s\n", "IBM", CHT_get(ht, "IBM"));
	printf("Key: %s, Value: %s\n", "ORCL", CHT_get(ht, "ORCL"));
	printf("Key: %s, Value: %s\n", "CSCO", CHT_get(ht, "CSCO"));
	printf("Key: %s, Value: %s\n", "GOOG", CHT_get(ht, "GOOG"));
	printf("Key: %s, Value: %s\n", "YHOO", CHT_get(ht, "YHOO"));
	printf("Key: %s, Value: %s\n", "NOVL", CHT_get(ht, "NOVL"));

	CHT_destroyHashTable(ht);
}
