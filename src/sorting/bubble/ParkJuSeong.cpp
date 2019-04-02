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

void bubbleSort(int* arr, int n) {
	for (int i = n; i > 0; i--) {	// n-1�� �ݺ� �����ϸ� ���� �Ϸ�
		for (int j = 0; j < i - 1; j++) {	// �� �� ���� �� 0~n-2 ���ұ��� �ݺ�
			if (arr[j] > arr[j + 1]) {	// �� ������ ���� �� ������ �� ���� ũ��
				// Swap
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
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
	bubbleSort(arr, n);
	printf("���� �� : ");
	print(arr, n);

	return 0;
}