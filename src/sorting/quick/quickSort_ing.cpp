/*
�� ����
�ð����⵵ ��� nlogn �־� n^2
*/
#include<iostream>
using namespace std;

void print(int* arr, int n) {	// �迭 ��� �Լ�
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
}

int searchPivot(int* arr, int start, int end) {
	int pivot = arr[start];
	int left = start + 1;
	int right = end;
	while (left<right) {
		for (int i = start; i <= end; i++) printf("%d ", arr[i]);
		printf("\n");
		while (left<=end && arr[left] <= arr[pivot]) left++;
		while (right > pivot + 1 &&arr[right] > arr[pivot]) right--;
		if (left < right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}
	if (pivot > arr[right]) {
		arr[start] = arr[right];
		arr[right] = pivot;
	}
	return right;
}

void quickSort(int* arr, int start, int end) {
	printf("A\n");
	if (start >= end) return;
	int pivot = searchPivot(arr, start, end);
	quickSort(arr, start, pivot - 1);
	quickSort(arr, pivot + 1, end);
}

int main() {
	printf("�迭�� ���� N �Է��ϰ� �迭 ���� �Է��ϼ���\n");
	int n;
	scanf("%d", &n);
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	printf("���� �� : ");
	print(arr, n);
	quickSort(arr, 0, n-1);
	printf("���� �� : ");
	print(arr, n);

	return 0;
}