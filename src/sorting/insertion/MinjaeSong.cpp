#include <iostream>
using namespace std;

void insertion_sort(int *a, int n) {
	// O(n^2)
	for (int i = 1; i < n; i++) { // key 1 ~ n-1
		int key = a[i];
		int pos = i;
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] > key) {
				a[j + 1] = a[j];  // �� ĭ ������ ����
				pos = j;  // �� ĭ�� ��ġ ����
			}
		}
		a[pos] = key;
	}
}

int main() {
	int n = 5;
	int arr[] = { 9,3,8,6,4 };
	insertion_sort(arr, n);	// ���� ����
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}