#include <iostream>
#include <vector>
using namespace std;

int INF = 9999999;
int adj[9999][9999];
void dijkstra(int n) { // start node 0
	vector<int> vertex(n);
	vector<int> dist(n);
	vector<int> prev(n);

	for (int i = 0; i < n; i++) {
		dist[n] = INF;
		vertex[i] = i;
	}

	dist[0] = 0; // start node

	while (!vertex.empty()) {  // vertex �� �� ������
		int mini = vertex[0], minNode = 0;
		for (int i = 0; i < vertex.size(); i++) {  // ���� dist ���� vertex ã��
			if (mini > dist[i]) {
				mini = dist[i];
				minNode = i;
			}
		}
		vertex.erase(vertex.begin() + minNode); // vertex ����
		for (int i = 0; i < n; i++) {
			if (adj[minNode][i] > 0) {  // �������
				int tmp = dist[minNode] + adj[minNode][i];
				if (tmp < dist[i]) { // �� ª�� ���ο� ��� 
					dist[i] = tmp;
					prev[i] = minNode;
				}
			}
		}
	}
	return;
}


int main() {
	dijkstra(10);
	return 0;
}