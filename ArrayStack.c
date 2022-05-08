
#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
//±³¾ÈÀÇ CreateS 
void stackInit(Stack* s) {
	s->top = -1;
}

void push(Stack* s, SData data) {
	if (isFull(s)) {
		printf("Stack is Full\n");
		exit(1);
	}
	else {
		s->arr[++s->top] = data;
	}
}
SData pop(Stack* s) {
	if (isEmpty(s)) {
		printf("Stack is Empty\n");
		exit(1);
	}
	else {
		SData temp = s->arr[s->top--];
		return temp;
	}
}
int isEmpty(Stack* s) {
	if (s->top == -1) { return TRUE; }
	else { return FALSE; }
}
int isFull(Stack* s) {
	if (s->top >= MAX_SIZE - 1) { return TRUE; }
	else { return FALSE; }
}
