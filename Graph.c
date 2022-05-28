#include "graph.h"
#include <stdlib.h>
#include <stdio.h>
void GraphInit(Graph* gp, int vNum) {
	gp->edgeNum = 0;
	gp->vertexNum = vNum;
	//인접행렬 , 비용 0으로 초기화 
	for (int i = 0; i < vNum; i++) {
		for (int j = 0; j < vNum; j++) {
			gp->adjArr[i][j] = FALSE;
			gp->costArr[i][j] = 999;
			//비용은 기본적으로 999(무한)
			if (i == j) {
				gp->costArr[i][j] = 0;
			}
		}
	}
}
void AddEdge(Graph* gp, int from, int to, int cost) {
	//간선 추가, 방향 그래프 
	gp->adjArr[from][to] = TRUE;
	gp->costArr[from][to] = cost;
}
void ShowGraph(Graph* gp) {
	printf("graph 정보 출력\n");
	for (int i = 0; i < gp->vertexNum; i++) {
		for (int j = 0; j < gp->vertexNum; j++) {
			if (gp->adjArr[i][j] == TRUE) {
				printf("[%d->%d : 비용 %d]  ",i, j, gp->costArr[i][j]);
			}
		}
		printf("\n");
	}
}

//최소비용을 전부 찾았는지 확인하기 위한 함수 
int findAll(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		if (arr[i] == FALSE) {
			return FALSE;
		}
	}
	return TRUE;
}

//distance 배열에서 최소값을 가지는 정점을 찾아오기 위한 함수 
int findMin(int * found,int* distance, int length) {
	int min = 999;
	int minIndex = 0;
	for (int i = 0; i < length; i++) {
		if (distance[i] <= min&&found[i]==FALSE) {
			//아직 found되지 않은 노드중에 비용이 최소인 노드 찾기 
			min = distance[i];
			minIndex = i;
		}
	}
	return minIndex;
}


//더 작은값을 반환하는 함수 
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
		//모든 정점에 대해 최소비용을 찾을 때까지 반복 
		visit = findMin(found,distance, 6);
		found[visit] = TRUE; 
		//최소비용인 곳을 방문한것으로 처리 

		for (int i = 0; i < 6; i++) {
			if (found[i] == FALSE) {
				//visit 정점을 거쳐 가는것과 기존 경로 중 어느것이 최소인지 판별 
				distance[i] = minValue(distance[i], distance[visit] + gp->costArr[visit][i]);
			}
		}
	}


	//표 출력 
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