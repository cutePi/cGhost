#include <iostream>
#include <cstdlib>

using namespace std;

struct tNode {
	int v;
	struct tNode *l;
	struct tNode *r;
};

struct tNode* newNode(int n) {
	struct tNode* t = (struct tNode*)malloc(sizeof(struct tNode));
	t->v = n;
	t->l = t->r = NULL;
	return t;
}
void printPreorder(struct tNode* n) {
	if (n == NULL) {
		return;
	}
	cout << n->v;
	printPreorder(n->l);
	printPreorder(n->r);
}
int main() {
	struct tNode* t = newNode(1);
	printPreorder(t);
	cout << endl;
}
