#pragma once
#define TRUE 1
#define FALSE 0
typedef int Data;

//양방향 연결 리스트 
//insert : 맨 끝에 노드 추가 
//delete : data 값을 검색해서 해당 노드 삭제 
//search : data 값의 존재여부 
//circular 형태로도 가능 

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


