#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double avr(int* arr, int index)
{
	int sum = 0;
	for (int i = 0; i <= index; i++)
	{
		sum += arr[i];
	}
	return sum / (double)(index + 1);
}




int main()
{
	//�迭 �Է¹ޱ�
	char input[100];
	printf("�迭�� �Է����ּ��� : ");
	gets(input); //gets�� input�� �迭�� ���ڿ� ���·� �Է¹��� 

	int arr[50] = { 0 }; 

	char* temp = strtok(input, " "); //strtok�� �̿��ؼ� input�� �Է¹��� ���ڿ��� " " �������� ����
	int i = 0;
	while (temp != NULL)
	{
		arr[i] = atoi(temp); //atoi�� ������ ����ȯ �ؼ� arr �迭�� ���� 
		i++;
		temp = strtok(NULL, " ");
	}

	printf("AVR ���\n");
	for (int j = 0; j < i; j++)
	{
		printf("AVR[%d] : %.1f\n", j, avr(arr, j));
	}



	return 0;
}