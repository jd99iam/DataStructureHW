#include <stdio.h>

int func(int n)
{
	if (n <= 3)
	{
		return n - 1;
	}
	else
	{
		return func(n - 1) + func(n - 2) + func(n - 3);
	}
}

 
int main()
{
	printf("%d", func(10));
}