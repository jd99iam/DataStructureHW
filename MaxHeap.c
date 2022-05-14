#include "MaxHeap.h"

void HeapInit(Heap* heap,PriorityCheck func) {
	heap->numOfData = 0;
	heap->func = func; 
} //�� �ʱ�ȭ , �켱������ ������ �Լ��� �����Ѵ� 

int HIsEmpty(Heap* heap) {
	if (heap->numOfData == 0) { return TRUE; }
	else { return FALSE; }
} //������� Ȯ�� 

//�θ�, �ڽ� ��� �ε��� ��ȯ�ϴ� �Լ� 
int GetParent(int index) {
	return index / 2;
}
int GetLeftChild(int index) {
	return index * 2;
}
int GetRightChild(int index) {
	return index * 2 + 1;
}

//�켱������ �� ���� �ڽ� ����� �ε����� ��ȯ�Ѵ� 
int GetHighPriorityChild(Heap * heap, int index) {
	if (HIsEmpty(heap)) { exit(1); }
	if (GetLeftChild(index) > heap->numOfData) {
		return 0; //�ڽ� ��尡 ������ 0 ��ȯ 
	}
	else if (GetLeftChild(index) == heap->numOfData) {
		return GetLeftChild(index); //�ڽĳ�尡 �Ѱ� (����) �� ������ ���� �ε��� ��ȯ 
	}
	else {
		//�ڽĳ�尡 2���� ��� �켱������ �� ���� ���� �ε��� ��ȯ 
		if (heap->func(heap->arr[GetLeftChild(index)], heap->arr[GetRightChild(index)])) {
			return GetLeftChild(index);
		}
		else {
			return GetRightChild(index);
		}
	}
}

//���� : �̻���� 
HData HDelete(Heap* heap) {
	if (HIsEmpty(heap)) { exit(1); }


	/*
	�켱������ ���� ���� ��Ʈ ��带 �����Ѵ� (�� ��ȯ)
	���ϴ� ��带 ��Ʈ ��忡 �ڸ��� ���� �ڽ� ���� ���ϸ� �ڸ��� ���Ѵ�
	*/

	HData retData = heap->arr[1];//��ȯ�� ������ ����


	int spot = 1;
	int spotChild;
	/* spot�� �̿��ؼ� ���ϴ� ��带 ��� ��ġ�� ������ ã�´�
	* spot�� ���� ��Ʈ ����� �ڸ��� 1���� �����ؼ� spotChild (spot �� �ڽ� ����� �켱������ ���� ���)
	* �� �켱������ ���ϸ� �ڸ��� ã�� �ȴ�
	*/
	while (spotChild = GetHighPriorityChild(heap,spot)) { //�ڽ� ��尡 ������ 0 ��ȯ 
		if (heap->func(heap->arr[heap->numOfData], heap->arr[spotChild])) {
			break;
			//spotChild�� �켱�������� ������ �������� �켱������ ������� Ż�� 
		}
		//spotChild�� �켱������ ������ �����ͺ��� ���� ��� 
		heap->arr[spot] = heap->arr[spotChild];

		//spot ��ġ�� spotChild�� ��ġ�Ѵ�. �� �ڽ� ��带 �θ� ��� �ڸ��� �ű�� 
		spot = spotChild; 
		//���ϸ� ��ġ�� ã�� ���� ������ spot�� spotChild�� �ڸ��� ������ (���� 1 ����)
	}

	heap->arr[spot] = heap->arr[heap->numOfData]; //spot�� ���ϴ� ������ ��ġ 

	heap->numOfData -= 1; //������ ���� 1 ���� 
	return retData; //������ ������ ��ȯ 
}



void HInsert(Heap* heap, HData data) {
	/* Heap�� ���ϴܿ� �����͸� �ְ� �θ���� �ڸ��� ���ϸ� ã�ư��� 
	*/
	int spot = heap->numOfData + 1;
	int spotParent;
	while ((spotParent = GetParent(spot)) != 0) { //0�� ��� ���� 1����  spot�� �ö�� 

		if (heap->func(heap->arr[spotParent], data)) {
			//spot�� �켱������ spotParent���� ���� ��� 
			
			break;
		}
		//spot�� �켱������ spotParent���� ���� ��� 
		heap->arr[spot] = heap->arr[spotParent];
		
		//�θ��带 ������ 
		spot = spotParent; 
		//�� ���� �Ʒ��� ������ ���Ѵ� 
	}
	heap->numOfData += 1;
	heap->arr[spot] = data; //������ ��ġ spot�� ������ ���� 

	
}
