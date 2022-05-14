#pragma once
#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct __node {
	Data data;
	struct __node* left;
	struct __node* right;

}Node;

typedef void(*Action)(Node* node);

//초기화 
Node* MakeTree();

//값 넣기 
void SetData(Node* node, Data data);

//값 반환 
Data GetData(Node* node);

//왼쪽, 오른쪽 서브트리 연결 
void MakeLeftSubTree(Node* root,Node*sub);
void MakeRightSubTree(Node* root,Node*sub);

//왼쪽 오른쪽 서브트리의 루트 주소 얻기 
Node* GetLeftSubTree(Node* node);
Node* GetRightSubTree(Node* node);

//순회 

void PreOrderTraverse(Node* node, Action func);
void InOrderTraverse(Node* node, Action func);
void PostOrderTraverse(Node* node, Action func);


//삭제 
void DeleteTree(Node* node);

//트리모양 출력 
void PrintTree(Node* node);
