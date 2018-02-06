/*
 * TestDisjointSet.c
 *
 *  Created on: 2018. 2. 1.
 *      Author: user
 */


#include "DisjointSet.h"

int testDisjointSet(void) {
	int a = 1, b = 2, c = 3, d = 4;

	DisjointSet* set1 = DS_makeSet(&a);
	DisjointSet* set2 = DS_makeSet(&b);
	DisjointSet* set3 = DS_makeSet(&c);
	DisjointSet* set4 = DS_makeSet(&d);

	printf("set1 == set2 : %d\n", DS_findSet(set1) == DS_findSet(set2));

	DS_unionSet(set1, set3);
	printf("set1 == set3 : %d\n", DS_findSet(set1) == DS_findSet(set3));

	DS_unionSet(set3, set4);
	printf("set3 == set4 : %d\n", DS_findSet(set3) == DS_findSet(set4));

	return 0;
}
