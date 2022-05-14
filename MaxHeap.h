//�迭 ����� �ִ� �� ���� 
#define TRUE 1
#define FALSE 0
#define MAX_SIZE 10 //�� ũ�� 

typedef int HData; //���� ������ �ڷ��� 

typedef int(*PriorityCheck)(HData data1, HData data2);
//�������� �켱������ �����ִ� �Լ��������� typedef ���� 

typedef struct __heap {
	PriorityCheck func; //�켱���� ���ϱ� ���� �Լ� 
	HData arr[MAX_SIZE];
	int numOfData;
}Heap;

void HeapInit(Heap* heap); //�� �ʱ�ȭ 

int HIsEmpty(Heap* heap); //������� Ȯ�� 

//�θ�, �ڽ� ��� �ε��� ��ȯ�ϴ� �Լ� 
int GetParent(int index);
int GetLeftChild(int index);
int GetRightChild(int index);

int GetHighPriorityChild(Heap* heap, int index);

//���� 
HData HDelete(Heap* heap);

//���� 
void HInsert(Heap* heap, HData data);



