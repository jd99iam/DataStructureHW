//배열 기반의 최대 힙 구현 
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 10 //힙 크기 

typedef int HData; //힙에 저장할 자료형 

typedef int(*PriorityCheck)(HData data1, HData data2);
//데이터의 우선순위를 정해주는 함수포인터의 typedef 선언 

typedef struct __heap {
	PriorityCheck func; //우선순위 정하기 위한 함수 
	HData arr[MAX_SIZE];
	int numOfData;
}Heap;

void HeapInit(Heap* heap); //힙 초기화 

int HIsEmpty(Heap* heap); //비었는지 확인 

//부모, 자식 노드 인덱스 반환하는 함수 
int GetParent(int index);
int GetLeftChild(int index);
int GetRightChild(int index);

int GetHighPriorityChild(Heap* heap, int index);

//삭제 
HData HDelete(Heap* heap);

//삽입 
void HInsert(Heap* heap, HData data);



