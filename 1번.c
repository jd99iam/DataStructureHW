//#include <stdio.h>
//void func(int* arr, int size)
//{
//	int sum = 0;
//	for (int i = 0; i < size; i++)
//	{
//		sum += arr[i];
//	}
//	int ave = sum / size;
//	printf("평균 : %d\n", ave);
//	int count = 0;
//	for (int i = 0; i < size; i++)
//	{
//		if (arr[i] < ave)
//		{
//			count += 1;
//		}
//	}
//	printf("평균보다 작은 원소 : %d개\n", count);
//}
//
//int main()
//{
//	int arr[5] = { 1,2,3,4,5 };
//	func(arr, sizeof(arr)/sizeof(int));
//	return 0;
//}