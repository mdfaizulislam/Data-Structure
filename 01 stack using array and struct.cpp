#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
const int MAX = 2e5 + 5;
typedef struct stack {
	int tp;			// top, if top == -1, stack is empty
	int arr[MAX];	// stack size = top+1
	struct stack()	// constructor
	{
		tp = -1;
	}
	void push(int n)	// push memeber func, push element on top 
	{
		if (tp + 1 == MAX) {
			cout << "Warning! Stack Overflow.\n";
			return;
		}
		tp++;
		arr[tp] = n;
	}
	void pop() {		// pop member func, pops top element
		if (tp + 1 == 0) {
			cout << "Warning! Stack Underflow.\n";
		}
		tp--;
	}
	int top() {			// top member func, returns top element
		return arr[tp];
	}
	bool empty() {		// member func, returns true if stack is empty, else false
		return tp == -1;
	}
	int size() {		// member func, returns size of stack
		return tp + 1;
	}
};


int main() {
	stack s;
	cout << "to quit: -1\n";
 	while (true)
	{
		int n;
		cin >> n;
		if (n == -1)
			break;
		s.push(n);
	}
	cout << "stack size: " << s.size() << "\n";
	while (!s.empty())
	{
		int n = s.top();
		cout << n << " ";
		s.pop();
	}
	return 0;
}
