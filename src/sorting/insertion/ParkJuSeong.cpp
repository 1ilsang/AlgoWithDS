/*
��������
�ð����⵵ O(n^2)
*/
#include<iostream>
using namespace std;

void print(int* arr, int n) {	// �迭 ��� �Լ�
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
}

void insertionSort(int* arr, int n) {
	for (int i = 1; i < n; i++) {
		int key = arr[i];
		int index = i;
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > key) {
				arr[j + 1] = arr[j];
			}
			else {
				index = j + 1;
				break;
			}
		}
		arr[index] = key;
	}
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
	insertionSort(arr, n);
	printf("���� �� : ");
	print(arr, n);

	return 0;
}