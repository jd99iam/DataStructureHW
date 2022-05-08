#pragma once
#define MAX_SIZE 10
#define TRUE 1
#define FALSE 0

typedef int SData;

typedef struct __stack {
	SData arr[MAX_SIZE];
	int top;
}Stack;

void stackInit(Stack* s);

void push(Stack* s, SData data);

SData pop(Stack* s);

int isEmpty(Stack* s);

int isFull(Stack* s);
