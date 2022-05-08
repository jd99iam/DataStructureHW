#include "CircularQueue.h"
#include <stdio.h>
#include <stdlib.h>

void initQueue(Queue* q) {
	//���� ť�� �� ĭ�� ����� ����Ѵ� ������ 0 �ε����� �ʱ�ȭ 
	q->front = 0;
	q->rear = 0;
}
void enQueue(Queue* q, QData data) {
	if (isFull(q)) {
		printf("Queue is Full\n");
		exit(1);
	}
	else {
		q->rear = (q->rear + 1) % MAX_SIZE;
		q->arr[q->rear] = data;
	}
}
QData deQueue(Queue* q) {
	if (isEmpty(q)) {
		printf("Queue is Empty\n");
		exit(-1);
	}
	else {
		q->front = (q->front + 1) % MAX_SIZE;
		return q->arr[q->front];
	}
}

int QisFull(Queue* q) {
	if (q->front == (q->rear + 1) % MAX_SIZE) {
		return TRUE;
	}
	else { return FALSE; }
}
int QisEmpty(Queue* q) {
	if (q->front == q->rear) {
		return TRUE;
	}
	else {
		return FALSE;
	}
}
