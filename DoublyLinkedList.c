#include "DoublyLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

void LInit(List* l) {
	l->head = (Node*)malloc(sizeof(Node));
	l->head->left = NULL;
	l->head->right = NULL;
}

void LInsert(List* l, Data data) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	
	if (LIsEmpty(l)) {
		l->head->right = newNode;
		newNode->left = l->head;
		newNode->right = NULL;
	}
	else {
		l->head->right->left = newNode;
		newNode->right = l->head->right;
		l->head->right = newNode;
		newNode->left = l->head;
	}
}

int LSearch(List* l, Data data) {
	if (LIsEmpty(l)) { exit(1); }
	else {
		Node* curNode = (Node*)malloc(sizeof(Node));
		curNode = l->head;
		while (curNode->data != data) {
			if ((curNode->right) == NULL) {
				return FALSE;
			}
			curNode = curNode->right;
		}
		return TRUE;
	}
}

Data LDelete(List* l, Data data) {
	if (!LSearch(l, data)) {
		printf("data not exists\n");
		exit(1);
	}
	else {
		Node* curNode = (Node*)malloc(sizeof(Node));
		curNode = l->head;
		while (TRUE) {
			curNode = curNode->right;
			if (curNode->data == data) {
				curNode->left->right = curNode->right;
				if (curNode->right != NULL) {
					curNode->right->left = curNode->left;
				}
				return data;
			}
		}

	}
}

int LIsEmpty(List* l) {
	if (l->head->right == NULL) {
		return TRUE;
	}
	else { return FALSE; }
}