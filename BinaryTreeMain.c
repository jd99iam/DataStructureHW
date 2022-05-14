//#include "BinaryTree.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//void showData(Node* node);
//
//
//int main() {
//	//노드 생성 
//	Node* node1 = MakeTree();
//	Node* node2 = MakeTree();
//	Node* node3 = MakeTree();
//	Node* node4 = MakeTree();
//
//	//노드에 값 넣기 
//	SetData(node1, 1);
//	SetData(node2, 2);
//	SetData(node3, 3);
//	SetData(node4, 4);
//
//	//노드간의 연결 (트리구조)
//	MakeLeftSubTree(node1, node2);
//	MakeRightSubTree(node1, node3);
//	MakeLeftSubTree(node2, node4);
//
//	// 트리 모양 출력 
//	PrintTree(node1,10);
//
//	//순회 (데이터를 출력해서 보여주기 때문에 탐색 가능)
//	InOrderTraverse(node1, showData);
//	printf("\n\n");
//	PreOrderTraverse(node1, showData);
//	printf("\n\n");
//	PostOrderTraverse(node1, showData);
//	printf("\n\n");
//
//	//삭제
//	DeleteTree(node1);
//
//	
//
//}
//
//void showData(Node* node) {
//	printf("%d ", node->data);
//}
//
//
//
//
