#include <stdio.h>

int main()
{
	func(9, 6666);

	return 0;
}

int func(int a, int b) 
{
	if (a <= 1 || a >= 10000 || b <= 1 || b >= 10000)
	{
		printf("a,b�� 1�� 10000������ ���̾�� �մϴ�.\n");
		return 0;
	}
	
	int temp = b;
	
	for (; temp != 0; temp /= 10) //10���� ���� ���� temp�� �����ϸ� �ڿ� 1�ڸ��� �ڸ� 
	{
		printf("%d\n", a * (temp % 10)); //�����ڸ��� a�� ���ؼ� ��� 
	}
	printf("%d\n", a * b);

}