#include <iostream>
#include <list>
#include <queue>

#define V 4


using namespace std;
list<int> l[V];

void addEdge(int v, int w) {
	l[v].push_back(w);
}

void bfs(int s) {
	bool visited[V] = {false};
	queue<int>q;
	q.push(s);
	visited[s] = true;
	while( !q.empty()) {
		s = q.front();
		cout << s  << " ";
		q.pop();
		for (auto m : l[s]) {
			if (!visited[m]) {
				q.push(m);
				visited[m] = true;
			}
		}
	}
}
void printList() {
	for (int i = 0; i < V; i++) {
		cout << "printing node for " << i << endl;
		for (auto m : l[i]) {
			cout << "->" << m;
		}
		cout << "\n";
	}
}

int main() {
	addEdge(0, 1);	
	addEdge(0, 2);	
	addEdge(2, 0);
	addEdge(2, 3);
	addEdge(3, 3);	
	addEdge(1, 2);	
	printList();
	bfs(2);
}

