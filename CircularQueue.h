#pragma once
#define MAX_SIZE 10
#define TRUE 1 
#define FALSE 0 

typedef int QData;

typedef struct __circularQueue {
	QData arr[MAX_SIZE];
	int front;
	int rear;
}Queue;

void initQueue(Queue *q);

void enQueue(Queue* q, QData data);

QData deQueue(Queue* q);

int QisFull(Queue* q);

int QisEmpty(Queue* q);

