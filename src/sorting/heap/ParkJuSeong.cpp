/*
�� ����
�ð����⵵ nlogn
*/

#include<iostream>
using namespace std;

typedef struct Node {	// ���. ������ ���� ����.
	int data;
}Node;

typedef struct minHeap {	// maxHeap �ݴ�... maxHeap �����ϸ� �� �ε�ȣ�� �ٲ��ָ� ���̴�..!
	Node* arr;
	int maxSize;
	int rear;
	minHeap(int size = 8) {
		arr = new Node[size];
		maxSize = size - 1;
		rear = 1;
	}
	int findParent(int index) {
		return index >> 1;
	}
	int findLeftChild(int index) {
		return index * 2;
	}
	int findRightChild(int index) {
		return index * 2 + 1;
	}
	bool isRoot(int index) {
		if (index == 1) return true;
		return false;
	}
	void swap(int index1, int index2) {
		Node temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
	void reSize() {
		Node* newArr = new Node[maxSize << 1];
		for (int i = 1; i < maxSize; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		maxSize <<= 1;
	}
	void add(int data) {
		Node newNode = { data };
		int index = rear;
		arr[index] = newNode;
		while (!isRoot(index)) {
			int parent = findParent(index);
			if (arr[parent].data > arr[index].data) {
				swap(parent, index);
				index = parent;
			}
			else break;
		}
		rear++;
		if (rear == maxSize) reSize();
	}
	bool isEmpty() {
		if (rear == 1) return true;
		return false;
	}
	int remove() {
		if (isEmpty()) return -9999;
		swap(1, --rear);
		int index = 1;
		while (true) {
			int lChild = findLeftChild(index);
			int rChild = findRightChild(index);
			if (lChild<rear&&arr[lChild].data<arr[index].data) {
				if (rChild<rear&&arr[rChild].data<arr[lChild].data) {
					swap(rChild, index);
					index = rChild;
				}
				else {
					swap(lChild, index);
					index = lChild;
				}
			}
			else if (rChild<rear&&arr[rChild].data<arr[index].data) {
				swap(rChild, index);
				index = rChild;
			}
			else break;
		}
		return arr[rear].data;
	}


}minHeap;

void print(int* arr, int n) {	// �迭 ��� �Լ�
	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
	printf("\n");
}

void heapSort(int* arr, int n) {
	minHeap heap;
	for (int i = 0; i < n; i++) heap.add(arr[i]);
	for (int i = 0; i < n; i++) arr[i] = heap.remove();
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
	heapSort(arr, n);
	printf("���� �� : ");
	print(arr, n);

	return 0;
}