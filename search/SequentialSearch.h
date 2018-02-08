/*
 * SequentialSearch.h
 *
 *  Created on: 2018. 2. 8.
 *      Author: user
 */


#include <stdio.h>
#include <stdlib.h>

#ifndef SEARCH_SEQUENTIALSEARCH_H_
#define SEARCH_SEQUENTIALSEARCH_H_

typedef struct tagNode {
	int data;
	int count; // 탐색 횟수
	struct tagNode* next;
} Node;

// 단순 연결 리스트를 이용한 순차 탐색
Node* SLL_sequentialSearch(Node* head, int target);


/*
 * 자기 구성 순차 탐색 (Self-Organizing Sequential Search)
 *   - 전진 이동법 (Move to front method)
 *     탐색된 항목을 헤드에 위치
 *
 *   - 전위법 (Transpose method)
 *     탐색된 항목을 바로 이전 항목과 교환
 *
 *   - 계수법 (Frequency count method)
 *     탐색된 횟수를 별도 공간에 저장
 *     탐색 횟수가 높은 순으로 데이터 집합을 재구성
 */

Node* SLL_moveToFront(Node** head, int target);
Node* SLL_transpose(Node** head, int target);
Node* SLL_frequencyCount(Node* head, int target);
void SLL_frequencyCountSort(Node* head);

#endif /* SEARCH_SEQUENTIALSEARCH_H_ */
