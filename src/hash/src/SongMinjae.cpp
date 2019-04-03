#include <iostream>
#include <cstring>
#include <malloc.h>
using namespace std;

void _insert(int *a, int m, int key, int size) {
	int tmp = key % m;
	while (a[tmp] != -1)
		tmp = (tmp + 1) % m;  // arr[tmp]�� �̹� �������� ���� index�� ����.
	a[tmp] = key;
}

void _delete(int *a, int m, int key, int size) {
	for (int i = 0; i < size; i++) {
		if (a[key%m] == -1) {	// hash table�� ������ ���� ���Ҵ�.
			cout << "No element" << '\n';
			break;
		}
		if (a[i] == key) {   // key�� ã���� -1�� �ٲ��ش�.
			a[i] = -1;
			cout << "deleted element " << key << '\n';
			break;
		}
	}
}

void _search(int *a, int m, int key, int size) {
	for (int i = 0; i < size; i++) {
		if (a[key%m] == -1) {
			cout << "No element" << '\n';
			break;
		}
		if (a[i] == key) {
			cout << "found elemnt in : " << i << '\n';
			break;
		}
	}
}

int main() {
	int hash_size, m;
	cout << "hash size �Է�: ";
	cin >> hash_size;  // table ũ�� �Է�
	int* arr = new int[hash_size];   // �迭�� hash table ����

	cout << "hash �Լ� �Է� (mod m): ";
	cin >> m;
	for (int i = 0; i < hash_size; i++)
		arr[i] = -1;

	_insert(arr, m, 10, hash_size);
	_insert(arr, m, 234, hash_size);
	_insert(arr, m, 6, hash_size);
	_insert(arr, m, 435, hash_size);
	_insert(arr, m, 322, hash_size);
	_insert(arr, m, 77, hash_size);
	_delete(arr, m, 435, hash_size);
	_delete(arr, m, 32, hash_size);
	_search(arr, m, 435, hash_size);
	_search(arr, m, 77, hash_size);
	_search(arr, m, 10, hash_size);

	for (int i = 0; i < hash_size; i++)
		cout << arr[i] << ' ';

	return 0;
}