/*
 * BinarySearch.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>
#include "Score.h"


Score* binarySearch(Score scoreList[], int size, double target) {

	int left, right, mid;

	left = 0; // 시작
	right = size - 1; // 끝

	while (left <= right) {
		mid = (left + right) / 2; // 중간 값

		if (target == scoreList[mid].score) {
			return &(scoreList[mid]);
		} else if (target > scoreList[mid].score) {
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return NULL;
}

int compareScore(const void *_elem1, const void *_elem2) {
	Score* elem1 = (Score*) _elem1;
	Score* elem2 = (Score*) _elem2;

	if (elem1->score > elem2->score) {
		return 1;
	} else if (elem1->score < elem2->score) {
		return -1;
	} else {
		return 0;
	}
}

void testBinSearch(void) {
	int length = sizeof DataSet / sizeof DataSet[0];
	Score* found = NULL;

	// 오름차순 정렬
	qsort((void*) DataSet, length, sizeof(Score), compareScore);

	// 검색
	found = binarySearch(DataSet, length, 671.78);

	printf("found: %d %f \n", found->number, found->score);
}
