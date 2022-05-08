#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	List* list = (List*)malloc(sizeof(List));
	LInit(list);
	
	//LIsEmpty 함수 테스트 
	if (LIsEmpty(list)) { printf("List is empty 1\n"); }

	//LInsert함수로 데이터 삽입 
	for (int i = 1; i <= 10; i++) {
		LInsert(list, i);
	}

	//삽입 후 LIsEmpty 함수 테스트 
	if (LIsEmpty(list)) { printf("List is empty 2\n"); }

	if (LSearch(list,5)) { printf("5 is in list\n"); }
	if (LSearch(list,100)) { printf("100 is in list\n"); }

	for (int i = 1; i <= 10; i++) {
		printf("%d\n", LDelete(list, i));
	}

	return 0;
}