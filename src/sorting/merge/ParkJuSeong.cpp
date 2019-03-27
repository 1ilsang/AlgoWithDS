/*
��������
�ð����⵵ O(nlogn)
���� -> ����(����)
*/
#include<iostream>
using namespace std;

void print(int* arr, int n) {	// �迭 ��� �Լ�
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
}

void merge(int* arr, int left, int mid, int right) {
	int lptr = left;
	int rptr = mid + 1;
	int* tarr = new int[right - left + 1];
	int tptr = 0;
	while (lptr <= mid && rptr <= right) {
		tarr[tptr++] = arr[lptr] <= arr[rptr] ? arr[lptr++] : arr[rptr++];
	}
	if (lptr > mid) while (rptr <= right) tarr[tptr++] = arr[rptr++];
	else while (lptr <= mid) tarr[tptr++] = arr[lptr++];
	tptr = 0;
	for (int i = left; i <= right; i++) arr[i] = tarr[tptr++];
}

void mergeSort(int* arr, int left, int right) {
	if (left >= right) return;
	int mid = (left + right) >> 1;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, mid, right);
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
	mergeSort(arr, 0, n-1);
	printf("���� �� : ");
	print(arr, n);

	return 0;
}