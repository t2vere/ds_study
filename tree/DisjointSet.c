/*
 * DisjointSet.c
 *
 *  Created on: 2018. 2. 1.
 *      Author: user
 */

#include "DisjointSet.h"

void DS_unionSet(DisjointSet* set1, DisjointSet* set2) {
	// 먼저 어떤 집합인지 구분 (parent가 null이면 대표 노드가 됨.)
	set2 = DS_findSet(set2);

	// join
	set2->parent = set1;
}

DisjointSet* DS_findSet(DisjointSet* set) {
	while (set->parent != NULL) {
		set = set->parent;
	}

	return set;
}

DisjointSet* DS_makeSet(void* data) {
	DisjointSet* node = (DisjointSet*) malloc(sizeof(DisjointSet));
	node->parent = NULL;
	node->data = data;

	return node;
}

void DS_destroySet(DisjointSet* set) {
	free(set);
}

