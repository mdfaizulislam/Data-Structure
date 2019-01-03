/*Given an array of 10^5 elements and 10^5 queries. in each query, update the element of index i
and find the sum between [l,r] 
lightoj: 1082, 1112
*/
#include<iostream>
using namespace std;
#define MAX 100001
int n, q;
int arr[MAX];
int tree[3 * MAX];

void segmentTree(int root, int startIndex, int lastIndex) {
	if (startIndex == lastIndex) {
		tree[root] = arr[startIndex];
		return;
	}

	int mid = startIndex + ((lastIndex - startIndex) >> 1);
	int left = 2 * root;
	int right = 2 * root + 1;
	segmentTree(left, startIndex, mid);
	segmentTree(right, mid + 1, lastIndex);

	tree[root] = tree[left] + tree[right];
}

int query(int root, int start, int last, int lowerBound, int upperBound) {
	if (lowerBound > last || upperBound < start)	// if out of bound
		return 0;
	if (start >= lowerBound && last <= upperBound)	// if in bound
		return tree[root];
	// else on part of the bound

	int left = 2 * root;
	int right = 2 * root + 1;
	int mid = start + ((last - start) >> 1);
	int s1 = query(left, start, mid, lowerBound, upperBound);
	int s2 = query(right, mid + 1, last, lowerBound, upperBound);

	return s1 + s2;
}

void update(int root, int start, int last, int index, int newValue) {
	if (index > last || index < start)	// if out of bound
		return;
	if (start >= index && last <= index) {	// if in bound
		tree[root] = newValue;
		return;
	}
	// else on part of the bound
	int left = 2 * root;
	int right = 2 * root + 1;
	int mid = start + ((last - start) >> 1);
	update(left, start, mid, index, newValue);
	update(right, mid + 1, last, index, newValue);
	tree[root] = tree[left] + tree[right];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	segmentTree(1, 1, n);

	int lower, upper, index, newValue;
	for (int i = 0; i < q; i++) {
		cout << "index newValue: ";
		cin >> index >> newValue;
		update(1, 1, n, index, newValue);
		cout << "lower upper: ";
		cin >> lower >> upper;
		cout << query(1, 1, n, lower, upper) << "\n";
	}
	return 0;
}