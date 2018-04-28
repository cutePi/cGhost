#include <iostream>
#include <queue>

using namespace std;

int main() {
	queue<int>q;
	int sum = 0;
	for (int i = 0; i < 10; i++) { q.push(i);}
	cout << "size of queue " << q.size() << endl;
	for (int i = 0; i < 10; i++) { cout << q.back() << " ";}
	cout << endl;
	while(!q.empty()) {
		sum += q.front();
		q.pop();
	}
	cout << sum << endl;

	return 0;
}
