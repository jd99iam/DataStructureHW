//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <string.h>
//
//int main() 
//{
//	char path[100];
//	printf("파일 경로 입력 : ");
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
//		if (toPrint[length-1] == '\n') //fgets로 읽으면 \n까지 포함되서 뺴주기 (word기준 \n은 글자수로 안침)
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
//	printf("\n총 %d줄 / 공백포함 %d글자 / 공백제외 %d글자 \n", line, charCount, countExceptSpace);
//
//	return 0;
//}