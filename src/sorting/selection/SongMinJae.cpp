#include <iostream>
using namespace std;

void selection_sort(int *a, int n) {
	for (int i = 0; i < n - 1; i++) { // n-1 ���� 
		int min_idx = i;
		int mini = a[i];
		for (int j = i + 1; j < n; j++) {  // ���� idx���� �ּҰ� ã��
			if (mini > a[j]) {
				mini = a[j];  // �ּҰ� �ٲٱ�
				min_idx = j;  // �ּҰ��� idx
			}
		}
		// swap
		int tmp;
		tmp = a[i];
		a[i] = a[min_idx];
		a[min_idx] = tmp;
	}
}

int main() {
	int n = 5;
	int arr[] = { 9,3,8,6,4 };
	selection_sort(arr, n);	// ���� ����
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}