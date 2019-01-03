#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
#define mod(a,b) ((a)-((a)/(b))*(b))	// returns a%b = a - (a/b)*b 
const int MAX_Queue_Size = (int)2e5 + 5;

typedef struct queue {
	int q[MAX_Queue_Size + 1];
	int first;
	int last;
	int count;
	struct queue()
	{
		first = 0;
		last = MAX_Queue_Size - 1;
		count = 0;
	}
	void push_back(int n) {
		if (count >= MAX_Queue_Size) {
			cout << "Warning! Queue Overflow.\n";
			return;
		}
		//last = (last + 1) % MAX_Queue_Size;
		last = mod((last + 1), MAX_Queue_Size);
		q[last] = n;
		count++;
	}

	void pop_front() {
		if (count <= 0) {
			cout << "Warning! Queue Underflow!\n";
			return;
		}
		//first = (first + 1) % MAX_Queue_Size;
		first = mod((first + 1), MAX_Queue_Size);
		count--;
	}

	int front() {
		if (count <= 0) {
			cout << "Warning! Queue Underflow!\n";
			return NULL;
		}
		return q[first];
	}

	int back() {
		if (count <= 0) {
			cout << "Warning! Queue Underflow!";
			return NULL;
		}
		return q[last];
	}

	bool empty() {
		return count <= 0;
	}
	int size() {
		return count;
	}
};

void display()
{
	printf("Choice:\n0\texit\n");
	printf("1\tempty\n");
	printf("2\tsize\n");
	printf("3\tfront\n");
	printf("4\tback\n");
	printf("5\tpush_back\n");
	printf("6\tpop_front\n");
}
int main()
{
	queue newQueue;
	int n, value;
	display();
	while (~scanf("%d", &n) && n)
	{
		switch (n)
		{
		case 1:
			printf("Empty: %d\n", newQueue.empty());
			break;
		case 2:
			printf("Size: %d\n", newQueue.size());
			break;
		case 3:
			printf("Front: %d\n", newQueue.front());
			//printf("input v: ");
			//scanf("%d",&value);
			break;
		case 4:
			printf("Back: %d\n", newQueue.back());
			break;
		case 5:
			printf("Value: ");
			scanf("%d", &value);
			newQueue.push_back( value);
			break;
		case 6:
			newQueue.pop_front();
		default:
			break;
		}
		display();
	}
	return 0;
}
