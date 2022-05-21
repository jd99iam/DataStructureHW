#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void ListInit(List* plist) {
	Node* head = (Node*)malloc(sizeof(Node));
	plist->numOfData = 0;
	plist->head = head;
	plist->head->next = NULL;
}
void LInsert(List* plist, LData data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = plist->head->next;
	plist->head->next = newNode;
	plist->numOfData += 1;
}
int LFirst(List* plist, LData* pdata) {
	if (plist->numOfData == 0) {
		return FALSE;
	}
	plist->cur = plist->head->next;
	plist->before = plist->head;

	*pdata = plist->cur->data;
	return TRUE;

}
int LNext(List* plist, LData* pdata) {
	if (plist->cur->next == NULL) {
		return FALSE;
	}
	else {
		plist->before = plist->cur;
		plist->cur = plist->cur->next;
		*pdata = plist->cur->data;
		return TRUE;
	}
}
LData LRemove(List* plist) {
	Node* delNode = plist->cur;
	LData temp = plist->cur->data;
	plist->before->next = plist->cur->next;
	plist->cur = plist->before;
	plist->numOfData -= 1;
	free(delNode);
	return temp;
}
int LCount(List* plist) {
	return plist->numOfData;
}
