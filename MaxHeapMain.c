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
		arr[i] = rand() % 30 + 1; //�����ϰ� �� ���� 7ĭ �迭 ���� 
	}

	for (int i = 0; i < 7; i++) {
		HInsert(heap, arr[i]);
		printf("heap�� %d ����\n");
	}

	while (!HIsEmpty(heap)) {
		printf("%d\n", HDelete(heap));
	}
	printf("\n\n");

	for (int i = 0; i < 7; i++) {
		arr[i] = rand() % 30 + 1; //�����ϰ� �� ���� 7ĭ �迭 ���� 
	}

	for (int i = 0; i < 7; i++) {
		HInsert(heap, arr[i]);
		printf("heap�� %d ����\n");
	}

	while (!HIsEmpty(heap)) {
		printf("%d\n", HDelete(heap));
	}
	printf("\n\n");

	for (int i = 0; i < 7; i++) {
		arr[i] = rand() % 30 + 1; //�����ϰ� �� ���� 7ĭ �迭 ���� 
	}

	for (int i = 0; i < 7; i++) {
		HInsert(heap, arr[i]);
		printf("heap�� %d ����\n");
	}

	while (!HIsEmpty(heap)) {
		printf("%d\n", HDelete(heap));
	}
	printf("\n\n");


	return 0;
}


//data 1�� ũ�ų� ������ true �ƴϸ� false ��ȯ 
int checkPriority(HData data1, HData data2) {
	if (data1 >= data2) {
		return TRUE;
	}
	else { return FALSE; }
}