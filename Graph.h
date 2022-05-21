#pragma once

//정점개수 4개라고 가정 

#include "LinkedList.h"

typedef struct __graph {
	int Vnum;
	LinkedList* adjList;
}Graph;

void GraphInit(Graph* graph, int arr[][4]);

void ShowGraph(Graph* graph);



