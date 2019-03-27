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

void selectionSort(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		int min = arr[i];
		int index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[index];
		arr[index] = temp;
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
	selectionSort(arr, n);
	printf("���� �� : ");
	print(arr, n);

	return 0;
}