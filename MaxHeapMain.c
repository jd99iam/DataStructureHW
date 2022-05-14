#include "MaxHeap.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checkPriority(HData data1, HData data2);

int main() {

	Heap* heap = (Heap*)malloc(sizeof(Heap));
	HeapInit(heap, checkPriority);


	srand(time(NULL));
	HData arr[7];
	
	for (int i = 0; i < 7; i++) {
		arr[i] = rand() % 30 + 1; //랜덤하게 값 넣은 7칸 배열 생성 
	}

	for (int i = 0; i < 7; i++) {
		HInsert(heap, arr[i]);
		printf("heap에 %d 삽입\n");
	}

	while (!HIsEmpty(heap)) {
		printf("%d\n", HDelete(heap));
	}
	printf("\n\n");

	for (int i = 0; i < 7; i++) {
		arr[i] = rand() % 30 + 1; //랜덤하게 값 넣은 7칸 배열 생성 
	}

	for (int i = 0; i < 7; i++) {
		HInsert(heap, arr[i]);
		printf("heap에 %d 삽입\n");
	}

	while (!HIsEmpty(heap)) {
		printf("%d\n", HDelete(heap));
	}
	printf("\n\n");

	for (int i = 0; i < 7; i++) {
		arr[i] = rand() % 30 + 1; //랜덤하게 값 넣은 7칸 배열 생성 
	}

	for (int i = 0; i < 7; i++) {
		HInsert(heap, arr[i]);
		printf("heap에 %d 삽입\n");
	}

	while (!HIsEmpty(heap)) {
		printf("%d\n", HDelete(heap));
	}
	printf("\n\n");


	return 0;
}


//data 1이 크거나 같으면 true 아니면 false 반환 
int checkPriority(HData data1, HData data2) {
	if (data1 >= data2) {
		return TRUE;
	}
	else { return FALSE; }
}