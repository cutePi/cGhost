// Inseart a node in a given position 

#include <iostream>
#include <cstdlib>

using namespace std;

struct node {
	int data;
	struct node *next;
};

struct node *root = NULL; // initially root is NULL

void insertNode(int data, int position) {
	node *temp1 = new node();
	temp1->data = data;
	temp1->next = NULL;
	if (position == 1) {
		temp1->next = root;
		root = temp1;
		return;
	}
	node *temp2 = root;
	for (int i = 0; i < position - 2; i++) {
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;	
}
void print() {
	node *temp = new node();
	temp = root;
	while(temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main() {
	insertNode(5, 1);
	insertNode(6, 1);
	insertNode(7, 1);
	insertNode(8, 1);
	insertNode(9, 2);
	print();
}
