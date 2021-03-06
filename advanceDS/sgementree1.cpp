#include <iostream>
#include <cmath>
using namespace std;

void fillST(int arr[], int s, int e, int *st, int index) {
	cout << s << " "  << e  << " "<< index << endl;
	if (s == e) {
		st[index] = arr[s];
	}else {
		int mid = (s+e)/2;

		fillST(arr, s, mid, st, 2 * index + 1);
	       	fillST(arr, mid+1, e, st, 2 * index + 2);
		st[index] = st[2 * index + 1] + st[2 * index + 2];
	}
	cout << st<<"[" << index << "] = " << st[index] << endl;
}

void update(int arr[], int node, int l, int r, int idx, int val) {
	if (l == r)  {
		arr[node] += val;
	}else {
		int mid = (l + r)/ 2;
		if (l <= idx && mid >= idx) update(arr, node * 2 +1 , l,  mid, idx, val);
		else update(arr, node * 2+ 2, mid + 1, r, idx, val);
		arr[node] = arr[node *2 +1 ] + arr[node *2 + 2];
	}
}

int query(int arr[], int node, int l, int r, int sts, int ste) {
	//cout << node << " " << l << " " << r << " " << sts << " " << ste << endl;
	if (l <= sts && r >= ste) {
		return arr[node];
	}else if (l > ste || r < sts) {
		return 0;
	}else {
		int mid = (sts + ste) / 2;
		int templ = query(arr, 2 * node + 1, l, r,sts, mid);
		int tempr = query(arr, 2 * node + 2, l, r, mid+1, ste);
		return templ + tempr;
	}
}

int *constructST(int arr[], int len) {
	// height of segment tree
	int x = (int)ceil(log2(len));
	cout << x << endl;
	// segement tree array size
	int seglenght  = 2 * (int)pow(2, x) - 1;
	int *stptr =  new int[seglenght];
	fillST(arr, 0, len-1,stptr, 0);
	//PrintST(arr);
	cout << "\n";
	return stptr;
}

int main() {
	int arr[] = {1, 3, 5, 7, 9, 11};
	//cout << PrintST(arr) << endl;
	int len = sizeof(arr)/ sizeof(arr[0]);
	int *st = constructST(arr, len);
	cout << query(st, 0, 1, 2, 0, len-1) << endl;
	//update()
	return 0;
}
