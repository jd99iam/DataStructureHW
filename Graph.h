#pragma once
#define TRUE 1
#define FALSE 0
typedef struct __graph {
	int vertexNum;
	int edgeNum;
	//인접행렬 
	int adjArr[6][6];
	//비용 
	int costArr[6][6];
}Graph;

void GraphInit(Graph* gp, int vNum);
void AddEdge(Graph* gp, int from, int to, int cost);
void ShowGraph(Graph* gp);
void Dijkstra(Graph* gp, int start);