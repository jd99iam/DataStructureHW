#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>

//초기화 
Node* MakeTree() {
	Node* root = (Node*)malloc(sizeof(Node));
	root->left = NULL;
	root->right = NULL;
	return root;
}

//값 넣기 
void SetData(Node* node, Data data) {
	node->data = data;
}

//값 반환 
Data GetData(Node* node) {
	return node->data;
}

//왼쪽, 오른쪽 서브트리 연결 
void MakeLeftSubTree(Node* root,Node*sub) {
	root->left = sub;
}
void MakeRightSubTree(Node* root, Node* sub) {
	root->right = sub;
}

//왼쪽 오른쪽 서브트리의 루트 주소 얻기 
Node* GetLeftSubTree(Node* node) {
	return node->left;
}
Node* GetRightSubTree(Node* node) {
	return node->right;
}

//순회 

//전위순회 
void PreOrderTraverse(Node* node, Action func) {
	if (node == NULL) {
		return; //재귀 탈출조건 
	}
	func(node);
	PreOrderTraverse(node->left, func);
	PreOrderTraverse(node->right, func);
	

}
//중위순회 
void InOrderTraverse(Node* node, Action func) {
	if (node == NULL) {
		return; //재귀 탈출조건 
	}
	InOrderTraverse(node->left, func);
	func(node);
	InOrderTraverse(node->right, func);

}
//후위순회 
void PostOrderTraverse(Node* node, Action func) {
	if (node == NULL) {
		return; //재귀 탈출조건 
	}
	PostOrderTraverse(node->left, func);
	PostOrderTraverse(node->right, func);
	func(node);
}


//삭제 
void DeleteTree(Node* node) {
	if (node == NULL) {
		return;
	}
	//삭제는 후위로 진행해야함 
	DeleteTree(node->left);
	DeleteTree(node->right);
	printf("%d data 삭제\n", node->data);
	free(node);
}


//문제에서 제시한 모양대로 출력하기 위한 메소드 
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

