#define _CRT_SECURE_MO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char text[100];
	fgets(text, 100, stdin);
	
	int textLen = strlen(text);
	char input;
	for (int i = 0; i < textLen; i++)
	{
		printf("%c", text[i]);
		input = getc(stdin);
		rewind(stdin);
		if (input != text[i])
		{
			printf("\a");
		}
	}



	return 0;
}