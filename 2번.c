#include <stdio.h>

int main()
{
	com_mul(6, 4);
	com_fac(24, 12);
	com_mul(8, 24);
	com_fac(72, 36);
	com_mul(11, 121);
	com_fac(15, 225);

	return 0;
}

int com_mul(int a, int b)
{
	if (a <= 1 || a >= 10000 || b <= 1 || b >= 10000)
	{
		printf("a,b�� 1�� 10000������ ���̾�� �մϴ�.\n");
		return 0;
	}
	
	int max = 0;

	if (a >= b)
	{
		max = a;
	}
	else
	{
		max = b;
	}
	int num = 0;
	for (int i = max; i <= a * b; i++)
	{
		if (i % a == 0 && i % b == 0)
		{
			num += 1;
		}
	}
	printf("%d , %d ����� ���� : %d\n", a, b, num);
	return num;
}

int com_fac(int a, int b)
{
	if (a <= 1 || a >= 10000 || b <= 1 || b >= 10000)
	{
		printf("a,b�� 1�� 10000������ ���̾�� �մϴ�.\n");
		return 0;
	}
	int min = 0;
	if (a >= b)
	{
		min = b;
	}
	else
	{
		min = a;
	}
	int num = 0;
	for (int i = 1; i <= min; i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			num += 1;
		}
	}
	printf("%d , %d ����� ���� : %d\n", a, b, num);
	return num;
}