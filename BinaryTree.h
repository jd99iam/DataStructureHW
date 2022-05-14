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

//�ʱ�ȭ 
Node* MakeTree();

//�� �ֱ� 
void SetData(Node* node, Data data);

//�� ��ȯ 
Data GetData(Node* node);

//����, ������ ����Ʈ�� ���� 
void MakeLeftSubTree(Node* root,Node*sub);
void MakeRightSubTree(Node* root,Node*sub);

//���� ������ ����Ʈ���� ��Ʈ �ּ� ��� 
Node* GetLeftSubTree(Node* node);
Node* GetRightSubTree(Node* node);

//��ȸ 

void PreOrderTraverse(Node* node, Action func);
void InOrderTraverse(Node* node, Action func);
void PostOrderTraverse(Node* node, Action func);


//���� 
void DeleteTree(Node* node);

//Ʈ����� ��� 
void PrintTree(Node* node);
