#include <stdio.h>
#include <stdlib.h>


void showArr(int* arr, int length);
void bubbleSort(int* arr, int length);
void insertionSort(int* arr, int length);
void mergeSort(int* arr, int left, int right);
void merge(int* arr, int left, int mid, int right);
int partition(int* arr, int left, int right);
void quickSort(int* arr, int left, int right);


int main() {

	printf("버블정렬\n");
	int arr1[10] = { 8,10,3,2,1,5,9,4,6,7 };
	showArr(arr1, 10);
	bubbleSort(arr1, 10);
	showArr(arr1, 10);

	printf("삽입정렬\n");
	int arr2[10] = { 8,10,3,2,1,5,9,4,6,7 };
	showArr(arr2, 10);
	insertionSort(arr2, 10);
	showArr(arr2, 10);


	printf("병합정렬\n");
	int arr3[10] = { 8,10,3,2,1,5,9,4,6,7 };
	showArr(arr3, 10);
	mergeSort(arr3, 0, 9);
	showArr(arr3, 10);


	printf("퀵정렬\n");
	int arr4[10] = { 8,10,3,2,1,5,9,4,6,7 };
	showArr(arr4, 10);
	quickSort(arr4, 0, 9);
	showArr(arr4, 10);

	return 0;
}

//배열출력
void showArr(int* arr, int length) {
	for (int i = 0; i < length; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n\n");
}

//버블정렬 
void bubbleSort(int* arr, int length) {
	for (int i = length - 1; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				//swap
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
			showArr(arr, 10);
		}
	}
}
//삽입정렬 
void insertionSort(int* arr, int length) {
	int j = 0;
	for (int i = 1; i < length; i++) {

		int temp = 0;
		j = i;

		while (arr[i] < arr[j - 1]) {
			j--;
			if (j == 0) { break; }

		}
		if (i != j) {
			temp = arr[i];
			for (int k = i - 1; k >= j; k--) {
				arr[k + 1] = arr[k];
			}
			arr[j] = temp;
		}
		showArr(arr, 10);
	}
}
void mergeSort(int* arr, int left, int right) {

	int mid;
	//원소가 1개일 때까지 나눔 
	if (left < right) {
		mid = (left + right) / 2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
		showArr(arr, 10);
	}
}
void merge(int* arr, int left, int mid, int right) {
	int ls = left;
	int rs = mid + 1;
	//정렬해서 임시로 저장할 배열 생성 
	int* tempArr = (int*)malloc(sizeof(int) * (right + 1));
	int index = left;
	while (ls <= mid && rs <= right) {
		if (arr[ls] <= arr[rs]) {
			tempArr[index] = arr[ls++];

		}
		else {
			tempArr[index] = arr[rs++];
		}
		index++;
	}
	if (ls > mid) {
		while (rs <= right) {
			tempArr[index++] = arr[rs++];
		}
	}
	else if (rs > right) {
		while (ls <= mid) {
			tempArr[index++] = arr[ls++];
		}
	}
	for (int i = left; i <= right; i++) {
		arr[i] = tempArr[i];
	}
}
void swap(int* arr, int a, int b) {
	int temp = arr[b];
	arr[b] = arr[a];
	arr[a] = temp;
}
int partition(int* arr, int left, int right) {
	int pivot = left;
	int low = left + 1;
	int high = right;
	while (low <= high) {
		while (arr[low] <= arr[pivot] && low <= right) {
			low++;
		}
		while (arr[high] >= arr[pivot] && high >= left + 1) {
			high--;
		}
		if (low <= high) {
			swap(arr, low, high);
		}
	}
	swap(arr, pivot, high);
	return high;
}
void quickSort(int* arr, int left, int right) {
	if (left <= right) {
		int pivot = partition(arr, left, right);
		showArr(arr, 10);
		quickSort(arr, left, pivot - 1);
		quickSort(arr, pivot + 1, right);
	
	}
}