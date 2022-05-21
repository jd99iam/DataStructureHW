#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Graph* graph = (Graph*)malloc(sizeof(Graph));
	int arr[4][4] = {
		{0,0,0,1},
		{1,1,0,0},
		{0,1,0,1},
		{1,1,1,0},
	};

	GraphInit(graph, arr);
	ShowGraph(graph);



	return 0;
}