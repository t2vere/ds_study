/*
 * TestSort.c
 *
 *  Created on: 2018. 2. 5.
 *      Author: user
 */

#include "MySort.h"

int main(void) {
	int bubbleDataSet[] = {6, 4, 2, 3, 1, 5};
	int insertionDataSet[] = {6, 4, 2, 3, 1, 5};
	int quickDataSet[] = {6, 4, 2, 3, 1, 5};

	int bubbleLength = sizeof bubbleDataSet / sizeof bubbleDataSet[0];
	int insertionLength = sizeof insertionDataSet / sizeof insertionDataSet[0];
	int quickLength = sizeof quickDataSet / sizeof quickDataSet[0];

	int i = 0;

	printf("Bubble Sort.\n");
	bubbleSort(bubbleDataSet, bubbleLength);

	for (i = 0; i < bubbleLength; i++) {
		printf("%d ", bubbleDataSet[i]);
	}

	printf("\n");

	printf("Insertion Sort.\n");
	bubbleSort(insertionDataSet, insertionLength);

	for (i = 0; i < insertionLength; i++) {
		printf("%d ", insertionDataSet[i]);
	}

	printf("\n");

	printf("Quick Sort.\n");
	bubbleSort(quickDataSet, quickLength);

	for (i = 0; i < quickLength; i++) {
		printf("%d ", quickDataSet[i]);
	}

	printf("\n");

	return 0;
}
