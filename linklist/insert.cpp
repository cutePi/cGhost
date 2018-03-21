#include <iostream>
#include <cstdlib>

using namespace std;

struct list {
	int d;
	struct list *next;
};

struct list* insertAtbegin(struct list *node, int d) {
	struct list *temp = (struct list*)malloc(sizeof(struct list));
	temp->d = d;
	temp->next = node;
	node = temp;
	return node;
}

void printNode(struct list * root) {
	cout << "printing list" << endl;
	while(root != NULL) {
		cout << root->d  << " ";
		root = root->next;
	}
	cout << endl;
}

int main() {
	struct list *root = NULL;
	int i, x;
	cin >> i;
	for (int j = 0; j < i; j++) {
		cout << "enter a new value" << endl;
		cin >> x;
		root = insertAtbegin(root, x);
		printNode(root);
	}
}
