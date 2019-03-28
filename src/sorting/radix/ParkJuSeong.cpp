/*
���(Radix) ����
�ð����⵵ ??
*/
#include<iostream>
#include<queue>
using namespace std;

void print(int* arr, int n) {	// �迭 ��� �Լ�
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
}

void radixSort(int* arr, int n) {
	int mul = 10;
	while (true) {
		bool flag = false;
		queue<int> q[10];
		for (int i = 0; i < n; i++) {
			int radix = (arr[i] % mul) / (mul / 10);
			if (radix != 0) flag = true;
			q[radix].push(arr[i]);
		}
		int index = 0;
		for (int i = 0; i < 10; i++) {
			while (!q[i].empty()) {
				int num = q[i].front();
				q[i].pop();
				arr[index++] = num;
			}
		}
		mul *= 10;
		if (!flag) break;
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
	radixSort(arr, n);
	printf("���� �� : ");
	print(arr, n);

	return 0;
}