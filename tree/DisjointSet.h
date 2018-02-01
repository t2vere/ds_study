/*
 * DisjointSet.h
 *
 *  Created on: 2018. 2. 1.
 *      Author: user
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef TREE_DISJOINTSET_H_
#define TREE_DISJOINTSET_H_

typedef struct tagDisjointSet {
	struct tagDisjointSet* parent;
	void* data;
} DisjointSet;

// 연산 : 합집합, 탐색

void DS_unionSet(DisjointSet* set1, DisjointSet* set2);
DisjointSet* DS_findSet(DisjointSet* set);
DisjointSet* DS_makeSet(void* data);
void DS_destroySet(DisjointSet* set);

#endif /* TREE_DISJOINTSET_H_ */
