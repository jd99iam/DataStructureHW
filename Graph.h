#pragma once

//�������� 4����� ���� 

#include "LinkedList.h"

typedef struct __graph {
	int Vnum;
	LinkedList* adjList;
}Graph;

void GraphInit(Graph* graph, int arr[][4]);

void ShowGraph(Graph* graph);



