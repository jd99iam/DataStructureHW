#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	List* list = (List*)malloc(sizeof(List));
	LInit(list);
	
	//LIsEmpty �Լ� �׽�Ʈ 
	if (LIsEmpty(list)) { printf("List is empty 1\n"); }

	//LInsert�Լ��� ������ ���� 
	for (int i = 1; i <= 10; i++) {
		LInsert(list, i);
	}

	//���� �� LIsEmpty �Լ� �׽�Ʈ 
	if (LIsEmpty(list)) { printf("List is empty 2\n"); }

	if (LSearch(list,5)) { printf("5 is in list\n"); }
	if (LSearch(list,100)) { printf("100 is in list\n"); }

	for (int i = 1; i <= 10; i++) {
		printf("%d\n", LDelete(list, i));
	}

	return 0;
}