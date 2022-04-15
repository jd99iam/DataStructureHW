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
	//배열 입력받기
	char input[100];
	printf("배열을 입력해주세요 : ");
	gets(input); //gets로 input에 배열을 문자열 형태로 입력받음 

	int arr[50] = { 0 }; 

	char* temp = strtok(input, " "); //strtok을 이용해서 input에 입력받은 문자열을 " " 기준으로 나눔
	int i = 0;
	while (temp != NULL)
	{
		arr[i] = atoi(temp); //atoi로 정수로 형변환 해서 arr 배열에 저장 
		i++;
		temp = strtok(NULL, " ");
	}

	printf("AVR 출력\n");
	for (int j = 0; j < i; j++)
	{
		printf("AVR[%d] : %.1f\n", j, avr(arr, j));
	}



	return 0;
}