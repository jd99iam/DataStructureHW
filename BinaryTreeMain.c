//#include "BinaryTree.h"
//#include <stdio.h>
//#include <stdlib.h>
//
//void showData(Node* node);
//
//
//int main() {
//	//��� ���� 
//	Node* node1 = MakeTree();
//	Node* node2 = MakeTree();
//	Node* node3 = MakeTree();
//	Node* node4 = MakeTree();
//
//	//��忡 �� �ֱ� 
//	SetData(node1, 1);
//	SetData(node2, 2);
//	SetData(node3, 3);
//	SetData(node4, 4);
//
//	//��尣�� ���� (Ʈ������)
//	MakeLeftSubTree(node1, node2);
//	MakeRightSubTree(node1, node3);
//	MakeLeftSubTree(node2, node4);
//
//	// Ʈ�� ��� ��� 
//	PrintTree(node1,10);
//
//	//��ȸ (�����͸� ����ؼ� �����ֱ� ������ Ž�� ����)
//	InOrderTraverse(node1, showData);
//	printf("\n\n");
//	PreOrderTraverse(node1, showData);
//	printf("\n\n");
//	PostOrderTraverse(node1, showData);
//	printf("\n\n");
//
//	//����
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
