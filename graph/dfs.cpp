#include <iostream>
#include <list>

#define V 4

using namespace std;

list<int> L[V];

void addEdge(int u, int v) {
	L[u].push_back(v);
}

void print() {
	for (int i = 0; i < V; i++) {
		cout << "[" << i << "] ";
		for (auto m : L[i]) {
			cout << "->" << m;
		}
		cout << "\n";
	}
}

void dfsUtil(int s, bool visited[]) {
	visited[s] = true;
	cout << s << " ";
	for (auto m : L[s]) {
		if (!visited[m]) dfsUtil(m, visited);
	}
}
// this dfs function handles for disconnected graph also
// it iterates all nodes as start node
void dfs() {
	cout << "dfs result" << endl;
	bool visited[V] = {false};
	// bool *visited = new bool[V]{false};
	for (int i = 0; i < V; i++) {
		if (!visited[i]) dfsUtil(i, visited);
	}
}
int main() {
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 2);
	addEdge(2, 0);
	addEdge(2, 3);
	addEdge(3, 3);
	print();
	dfs();
}
