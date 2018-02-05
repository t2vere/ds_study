/*
 * BubbleSort.c
 *
 *  Created on: 2018. 2. 5.
 *      Author: user
 */

#include "MySort.h"


void bubbleSort(int dataSet[], int length) {
	int i = 0;
	int j = 0;
	int temp = 0;

	for (i = 0; i < length - 1; i++) {
		for (j = 0; j < length - (1 + i); j++) {
			if (dataSet[j] > dataSet[j + 1]) {
				temp = dataSet[j + 1];
				dataSet[j + 1] = dataSet[j];
				dataSet[j] = temp;
			}
		}
	}
}

