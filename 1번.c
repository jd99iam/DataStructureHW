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
		printf("a,b는 1과 10000사이의 값이어야 합니다.\n");
		return 0;
	}
	
	int temp = b;
	
	for (; temp != 0; temp /= 10) //10으로 나눈 몫을 temp에 저장하며 뒤에 1자리씩 자름 
	{
		printf("%d\n", a * (temp % 10)); //일의자리를 a에 곱해서 출력 
	}
	printf("%d\n", a * b);

}