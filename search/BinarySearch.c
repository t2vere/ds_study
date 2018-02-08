/*
 * BinarySearch.c
 *
 *  Created on: 2018. 2. 8.
 *      Author: user
 */


#include "BinarySearch.h"
#include "Score.h"

Score* binarySearch(Score scoreList[], int size, double target) {

	int left, right, mid;

	left = 0;
	right = size - 1;

	while (left <= right) {
		mid = (left + right) / 2;

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
