/*
 * BubbleSort.c
 *
 *  Created on: 2018. 2. 5.
 *      Author: user
 */

#include "MySort.h"


void bubbleSort(int dataSet[], int length) {
	int cnt = 0;

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
		cnt++;
		}
	}

	printf("bubblesort1 : %d\n", cnt);
}

void bubbleSort2(int dataSet[], int length) {
	int cnt = 0;

	int i = 0;
	int j = 0;
	int temp = 0;
	int flag = 1; // 정렬되었는지 체크

	for (i = 0; i < length - 1 && flag; i++) {
		flag = 0;

		for (j = 0; j < length - (1 + i); j++) {
			if (dataSet[j] > dataSet[j + 1]) {
				temp = dataSet[j + 1];
				dataSet[j + 1] = dataSet[j];
				dataSet[j] = temp;

				flag = 1;
			}

			cnt++;
		}
	}

	printf("bubblesort2 : %d\n", cnt);
}
