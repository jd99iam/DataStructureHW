//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//int main() 
//{
//	char path[100];
//	printf("���� ��� �Է� : ");
//	scanf("%s", path);
//	char toPrint[30];
//	FILE* fp = fopen(path,"rt");
//	int line = 0;
//	int charCount = 0;
//	int length = 0;
//	int countExceptSpace = 0;
//
//	while (feof(fp) == 0)
//	{
//		fgets(toPrint, sizeof(toPrint), fp);
//		fputs(toPrint, stdout);
//		length = strlen(toPrint);
//		if (toPrint[length-1] == '\n') //fgets�� ������ \n���� ���ԵǼ� ���ֱ� (word���� \n�� ���ڼ��� ��ħ)
//		{
//			length -= 1;
//		}
//	
//
//		line += 1;
//		charCount += length;
//		countExceptSpace += length;
//		for (int i = 0; i < length; i++)
//		{
//			if (toPrint[i] == ' ')
//			{
//				countExceptSpace -= 1;
//			}
//		}
//	}
//
//	fclose(fp);
//	printf("\n�� %d�� / �������� %d���� / �������� %d���� \n", line, charCount, countExceptSpace);
//
//	return 0;
//}