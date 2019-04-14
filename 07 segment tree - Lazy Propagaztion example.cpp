/*
	Given an array and m queries(two types).
	type A:
	in each query, you will be given [l,r] range and a value x;
	and you have change each value of the range to value x;
	
	type B:
	in each query, you will be given [l,r] range and print the sum of all element in 
	range [l,r]

	array size <= 1e5, m <= 1e5
*/

#include<iostream>
using namespace std;
#define ll long long
#define MAX 100005

typedef struct info {
	ll sum;
	ll prop;	// replace with x
};

info tree[3 * MAX];
int arr[MAX];
int n, m, l, r, type, x;

void segmentTree(int root, int start, int last) {
	if (start == last) {
		tree[root].sum = arr[start];
		tree[root].prop = 0;
		return;
	}

	int left = root << 1;
	int right = (root << 1) + 1;
	int mid = start + ((last - start) >> 1);
	segmentTree(left, start, mid);
	segmentTree(right, mid + 1, last);
	tree[root].sum = tree[left].sum + tree[right].sum;
}

void update(int root, int start, int last, int lower, int upper, int x) {
	if (last < lower || start > upper)
		return;
	if (start >= lower && last <= upper) {
		tree[root].sum = (last - start + 1)*x;
		tree[root].prop = x;
		return;
	}

	int left = 2 * root;
	int right = 2 * root + 1;
	int mid = start + ((last - start) >> 1);
	update(left, start, mid, lower, upper, x);
	update(right, mid + 1, last, lower, upper, x);
	tree[root].sum = tree[left].sum + tree[right].sum;
}

ll query(int root, int start, int last, int lower, int upper, int carry) {
	if (last < lower || start > upper)
		return 0;
	if (start >= lower && last <= upper) {
		if (carry)
			return (last - start + 1)*carry;
		else
			return tree[root].sum;
	}

	int left = 2 * root;
	int right = 2 * root + 1;
	int mid = start + ((last - start) >> 1);
	ll s1 = query(left, start, mid, lower, upper, tree[root].prop);
	ll s2 = query(right, mid + 1, last, lower, upper, tree[root].prop);
	return s1 + s2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	// build segment tree
	segmentTree(1, 1, n);
	
	cin >> m;
	while (m--)
	{
		cin >> type;
		switch (type)
		{
		case 0:
			cin >> l >> r >> x;
			update(1, 1, n, l, r, x);
			break;
		case 1:
			cin >> l >> r;
			ll ans = query(1, 1, n, l, r, 0);
			cout << "[" << l << "," << r << "] : " << ans << "\n";
			break;
		}
	}
}