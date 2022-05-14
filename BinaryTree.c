#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

//�ʱ�ȭ 
Node* MakeTree() {
	Node* root = (Node*)malloc(sizeof(Node));
	root->left = NULL;
	root->right = NULL;
	return root;
}

//�� �ֱ� 
void SetData(Node* node, Data data) {
	node->data = data;
}

//�� ��ȯ 
Data GetData(Node* node) {
	return node->data;
}

//����, ������ ����Ʈ�� ���� 
void MakeLeftSubTree(Node* root,Node*sub) {
	root->left = sub;
}
void MakeRightSubTree(Node* root, Node* sub) {
	root->right = sub;
}

//���� ������ ����Ʈ���� ��Ʈ �ּ� ��� 
Node* GetLeftSubTree(Node* node) {
	return node->left;
}
Node* GetRightSubTree(Node* node) {
	return node->right;
}

//��ȸ 

//������ȸ 
void PreOrderTraverse(Node* node, Action func) {
	if (node == NULL) {
		return; //��� Ż������ 
	}
	func(node);
	PreOrderTraverse(node->left, func);
	PreOrderTraverse(node->right, func);
	

}
//������ȸ 
void InOrderTraverse(Node* node, Action func) {
	if (node == NULL) {
		return; //��� Ż������ 
	}
	InOrderTraverse(node->left, func);
	func(node);
	InOrderTraverse(node->right, func);

}
//������ȸ 
void PostOrderTraverse(Node* node, Action func) {
	if (node == NULL) {
		return; //��� Ż������ 
	}
	PostOrderTraverse(node->left, func);
	PostOrderTraverse(node->right, func);
	func(node);
}


//���� 
void DeleteTree(Node* node) {
	if (node == NULL) {
		return;
	}
	//������ ������ �����ؾ��� 
	DeleteTree(node->left);
	DeleteTree(node->right);
	printf("%d data ����\n", node->data);
	free(node);
}


//�������� ������ ����� ����ϱ� ���� �޼ҵ� 
void PrintTree(Node* node,int space) {
	if (node == NULL) {
		return;
	}
	for (int i = 1; i <= space; i++) {
		printf(" ");
	}
	printf("%d\n", node->data);
	
	if (node->right != NULL) {
		space += 2;
		for (int i = 1; i <= space; i++) {
			printf(" ");
		}
		printf("\\\n");
		PrintTree(node->right,space);
	}
	if (node->left != NULL) {
		space -= 4;
		for (int i = 1; i <= space; i++) {
			printf(" ");
		}
		printf("/\n");
		PrintTree(node->left, space);
	}

}

