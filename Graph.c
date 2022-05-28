#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
void GraphInit(Graph* gp, int vNum) {
	gp->edgeNum = 0;
	gp->vertexNum = vNum;
	//������� , ��� 0���� �ʱ�ȭ 
	for (int i = 0; i < vNum; i++) {
		for (int j = 0; j < vNum; j++) {
			gp->adjArr[i][j] = FALSE;
			gp->costArr[i][j] = 999;
			//����� �⺻������ 999(����)
			if (i == j) {
				gp->costArr[i][j] = 0;
			}
		}
	}
}
void AddEdge(Graph* gp, int from, int to, int cost) {
	//���� �߰�, ���� �׷��� 
	gp->adjArr[from][to] = TRUE;
	gp->costArr[from][to] = cost;
}
void ShowGraph(Graph* gp) {
	printf("graph ���� ���\n");
	for (int i = 0; i < gp->vertexNum; i++) {
		for (int j = 0; j < gp->vertexNum; j++) {
			if (gp->adjArr[i][j] == TRUE) {
				printf("[%d->%d : ��� %d]  ",i, j, gp->costArr[i][j]);
			}
		}
		printf("\n");
	}
}

//�ּҺ���� ���� ã�Ҵ��� Ȯ���ϱ� ���� �Լ� 
int findAll(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == FALSE) {
			return FALSE;
		}
	}
	return TRUE;
}

//distance �迭���� �ּҰ��� ������ ������ ã�ƿ��� ���� �Լ� 
int findMin(int * found,int* distance, int length) {
	int min = 999;
	int minIndex = 0;
	for (int i = 0; i < length; i++) {
		if (distance[i] <= min&&found[i]==FALSE) {
			//���� found���� ���� ����߿� ����� �ּ��� ��� ã�� 
			min = distance[i];
			minIndex = i;
		}
	}
	return minIndex;
}


//�� �������� ��ȯ�ϴ� �Լ� 
int minValue(int a, int b) {
	if (a <= b) { return a; }
	else { return b; }
}



void Dijkstra(Graph* gp, int start) {
	//int vertex[6] = { 0,0,0,0,0,0 };
	int found[6] = { 0,0,0,0,0,0 };
	int distance[6] = { 0,0,0,0,0,0 };

	found[start] = TRUE;
	
	for (int i = 0; i < 6; i++) {
		distance[i] = gp->costArr[start][i];
	}

	int visit = 0;

	while (!findAll(found, 6)) {
		//��� ������ ���� �ּҺ���� ã�� ������ �ݺ� 
		visit = findMin(found,distance, 6);
		found[visit] = TRUE; 
		//�ּҺ���� ���� �湮�Ѱ����� ó�� 

		for (int i = 0; i < 6; i++) {
			if (found[i] == FALSE) {
				//visit ������ ���� ���°Ͱ� ���� ��� �� ������� �ּ����� �Ǻ� 
				distance[i] = minValue(distance[i], distance[visit] + gp->costArr[visit][i]);
			}
		}
	}


	//ǥ ��� 
	for (int i = 0; i < 6; i++) {
		printf("%d\t", i);
	}
	printf("\n");
	for (int i = 0; i < 6; i++) {
		printf("%d\t", distance[i]);
	}
	printf("\n");
	for (int i = 0; i < 6; i++) {
		printf("%d\t", found[i]);
	}
	printf("\n");

	
	



}