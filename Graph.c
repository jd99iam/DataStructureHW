#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>


void GraphInit(Graph* graph, int arr[][4]) {
	graph->Vnum = 4;
	graph->adjList = (LinkedList*)malloc(sizeof(LinkedList)*4);
	for (int i = 0; i < 4; i++) {
		ListInit(&graph->adjList[i]);
	}
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr[i][j] == 1) {
				LInsert(&graph->adjList[i], j);
			}
		}
	}
}

void ShowGraph(Graph* graph) {
	int con;
	for (int i = 0; i < 4; i++) {
		printf("%c랑 연결된 정점 : ", i + 65);
		if (LFirst(&graph->adjList[i], &con)) {
			printf("%c  ", con + 65);
		}
		while (LNext(&graph->adjList[i], &con)) {
			printf("%c  ", con + 65);
		}
		printf("\n");
	}
}
