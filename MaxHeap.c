#include "MaxHeap.h"

void HeapInit(Heap* heap,PriorityCheck func) {
	heap->numOfData = 0;
	heap->func = func; 
} //힙 초기화 , 우선순위를 정해줄 함수도 전달한다 

int HIsEmpty(Heap* heap) {
	if (heap->numOfData == 0) { return TRUE; }
	else { return FALSE; }
} //비었는지 확인 

//부모, 자식 노드 인덱스 반환하는 함수 
int GetParent(int index) {
	return index / 2;
}
int GetLeftChild(int index) {
	return index * 2;
}
int GetRightChild(int index) {
	return index * 2 + 1;
}

//우선순위가 더 높은 자식 노드의 인덱스를 반환한다 
int GetHighPriorityChild(Heap * heap, int index) {
	if (HIsEmpty(heap)) { exit(1); }
	if (GetLeftChild(index) > heap->numOfData) {
		return 0; //자식 노드가 없으면 0 반환 
	}
	else if (GetLeftChild(index) == heap->numOfData) {
		return GetLeftChild(index); //자식노드가 한개 (왼쪽) 만 있으면 왼쪽 인덱스 반환 
	}
	else {
		//자식노드가 2개일 경우 우선순위가 더 높은 쪽의 인덱스 반환 
		if (heap->func(heap->arr[GetLeftChild(index)], heap->arr[GetRightChild(index)])) {
			return GetLeftChild(index);
		}
		else {
			return GetRightChild(index);
		}
	}
}

//삭제 : 이상없음 
HData HDelete(Heap* heap) {
	if (HIsEmpty(heap)) { exit(1); }


	/*
	우선순위가 제일 높은 루트 노드를 삭제한다 (값 반환)
	최하단 노드를 루트 노드에 자리에 놓고 자식 노드와 비교하며 자리를 정한다
	*/

	HData retData = heap->arr[1];//반환할 데이터 저장


	int spot = 1;
	int spotChild;
	/* spot을 이용해서 최하단 노드를 어느 위치에 넣을지 찾는다
	* spot은 원래 루트 노드의 자리인 1부터 시작해서 spotChild (spot 의 자식 노드중 우선순위가 높은 노드)
	* 와 우선순위를 비교하며 자리를 찾게 된다
	*/
	while (spotChild = GetHighPriorityChild(heap,spot)) { //자식 노드가 없으면 0 반환 
		if (heap->func(heap->arr[heap->numOfData], heap->arr[spotChild])) {
			break;
			//spotChild의 우선순위보다 마지막 데이터의 우선순위가 높을경우 탈출 
		}
		//spotChild의 우선순위가 마지막 데이터보다 높을 경우 
		heap->arr[spot] = heap->arr[spotChild];

		//spot 위치에 spotChild를 위치한다. 즉 자식 노드를 부모 노드 자리로 옮긴다 
		spot = spotChild; 
		//비교하며 위치를 찾기 위한 변수인 spot은 spotChild의 자리로 내린다 (레벨 1 증가)
	}

	heap->arr[spot] = heap->arr[heap->numOfData]; //spot에 최하단 데이터 위치 

	heap->numOfData -= 1; //데이터 개수 1 감소 
	return retData; //삭제한 데이터 반환 
}



void HInsert(Heap* heap, HData data) {
	/* Heap의 최하단에 데이터를 넣고 부모노드와 자리를 비교하며 찾아간다 
	*/
	int spot = heap->numOfData + 1;
	int spotParent;
	while ((spotParent = GetParent(spot)) != 0) { //0일 경우 레벨 1까지  spot이 올라옴 

		if (heap->func(heap->arr[spotParent], data)) {
			//spot의 우선순위가 spotParent보다 낮을 경우 
			
			break;
		}
		//spot의 우선순위가 spotParent보다 높을 경우 
		heap->arr[spot] = heap->arr[spotParent];
		
		//부모노드를 내린다 
		spot = spotParent; 
		//한 레벨 아래로 내려가 비교한다 
	}
	heap->numOfData += 1;
	heap->arr[spot] = data; //정해진 위치 spot에 데이터 저장 

	
}
