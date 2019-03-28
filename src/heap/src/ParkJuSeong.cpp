/*
�ڷᱸ�� : �� (�ִ� ��, �ּ� ��)
*/

#include<iostream>
using namespace std;

typedef struct Node {	// ���. ������ ���� ����.
	int data;
}Node;

typedef struct maxHeap {
	Node* arr ;		// Ʈ��(�迭�� ����)
	int maxSize;	// �迭�� �ִ� ũ��(������ �迭ũ�⸦ ����)
	int rear;		// Ʈ���� ���� �� �ε���
	maxHeap(int size=8) {	// ������?	�ʱ� ������=8, resize�� 2�辿 ����
		arr = new Node[size];	// ���� �Ҵ�
		maxSize = size - 1;		// ũ��8�̸� 0~7�̴ϱ� maxSize=7 (8-1)
		rear = 1;				// Ʈ���� ���� �ε����� 1 (���� ����)
	}
	int findParent(int index) {		// �θ� �ε��� ã��
		return index >> 1;
	}
	int findLeftChild(int index) {	// ���� �ڽ� �ε��� ã��
		return index * 2;
	}
	int findRightChild(int index) {	// ������ �ڽ� �ε��� ã��
		return index * 2 + 1;
	}
	bool isRoot(int index) {		// ���� �ε����� Root���� Ȯ��
		if (index == 1) return true;
		return false;
	}
	void swap(int index1, int index2) {	// �� ��� ����
		Node temp = arr[index1];
		arr[index1] = arr[index2];
		arr[index2] = temp;
	}
	void reSize() {		// �迭 ũ�� �� ���� ũ�� ���� (x2)
		Node* newArr = new Node[maxSize<<1];
		for (int i = 1; i < maxSize; i++) {
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		maxSize <<= 1;
	}
	void add(int data) {			// ��� �߰�
		Node newNode = { data };
		int index = rear;
		arr[index] = newNode;		// Ʈ���� �� ���� ���ο� ��� �߰�
		while (!isRoot(index)) {	// ���� ��� �ö󰣴�.
			int parent = findParent(index);	
			if (arr[parent].data < arr[index].data) {	// �θ��� �����Ͱ��� �ڽĺ��� ������
				swap(parent, index);	// ����
				index = parent;			// �߰��ߴ� ��� �ε��� ��������ֱ� (�ö���)
			}
			else break;
		}
		rear++;		// �� �� �ε��� +1
		if (rear == maxSize) reSize();	// reSize ���� ����(�迭 maxũ�⺸�� �ʰ��Ǵ��� Ȯ��)
	}
	bool isEmpty() {	// ����ֳ�?
		if (rear == 1) return true;
		return false;
	}
	int remove() {		// ��� ���� ( max�� ���� )
		if (isEmpty()) return -9999;
		swap(1, --rear);	// ��Ʈ�� �� �ڷ� ����������. �� �ڶ� ����. 
		int index = 1;		
		while (true) {		// �� ���� �ö� ��� ������ ����. ( maxHeap ���� )
			int lChild = findLeftChild(index);
			int rChild = findRightChild(index);
			if (lChild<rear&&arr[lChild].data>arr[index].data) {	// �ϴ� �����ڽ��̶� ũ�� �� ( ���� �ڽ��� �� ū��? )
				if (rChild<rear&&arr[rChild].data>arr[lChild].data) {	// ������ �ڽİ� �����ڽ� �� (�� ū�ֶ� �ٲ�ߵ�)
					swap(rChild, index);
					index = rChild;
				}
				else {
					swap(lChild, index);
					index = lChild;
				}
			}
			else if (rChild<rear&&arr[rChild].data>arr[index].data) {	// ������ �ڽİ� ��
				swap(rChild, index);
				index = rChild;
			}
			else break;	// �ڽĵ��� �� �۳�. ����.
		}
		return arr[rear].data;	// ó���� �����س��� ��Ʈ�� ����.
	}


}maxHeap;

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

int main() {
	minHeap mheap;
	printf("%d\n", mheap.remove());
	mheap.add(10);
	mheap.add(1);
	mheap.add(4);
	mheap.add(34);
	mheap.add(3);
	mheap.add(2);
	mheap.add(5);
	mheap.add(-1);
	while (!mheap.isEmpty()) {
		printf("%d ", mheap.remove());
	}

	return 0;
}