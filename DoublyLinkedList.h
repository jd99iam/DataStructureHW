#pragma once
#define TRUE 1
#define FALSE 0
typedef int Data;

//����� ���� ����Ʈ 
//insert : �� ���� ��� �߰� 
//delete : data ���� �˻��ؼ� �ش� ��� ���� 
//search : data ���� ���翩�� 
//circular ���·ε� ���� 

typedef struct __node {
	Data data;
	struct __node* left;
	struct __node* right;
}Node;

typedef struct __doublyLinkedList {
	Node* head;
}List;

void LInit(List* l);
void LInsert(List* l, Data data);
int LSearch(List* l, Data data);
Data LDelete(List* l, Data data);
int LIsEmpty(List* l);


