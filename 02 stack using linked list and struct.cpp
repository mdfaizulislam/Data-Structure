#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;
/*
empty()     Test whether container is empty (public member function )
size()      Return size (public member function )
top()       Access next element (public member function )
push()      Insert element (public member function )
pop()       Remove top element (public member function )
*/

typedef struct Node {
	int data;
	struct Node *nextNode;
	struct Node *prevNode;
};

typedef struct stack {
	Node *topNode;
	unsigned int totalSize;
	struct stack()			// constructor
	{
		topNode = NULL;
		totalSize = 0;
	}

	bool empty() {
		return totalSize == 0;
	}

	int size() {
		return totalSize;
	}

	int top() {
		if (totalSize == 0) {
			cout << "Warning! Stack Underflow.\n";
			return NULL;
		}
		return topNode->data;
	}

	void push(int value) {
		Node *temp;
		temp = (Node *)malloc(sizeof(Node));
		temp->data = value;
		temp->nextNode = NULL;
		temp->prevNode = NULL;
		if (totalSize == 0) {
			topNode = temp;
		}
		else {
			Node *prev;
			prev = topNode;
			topNode->nextNode = temp;
			topNode = temp;
			topNode->prevNode = prev;
		}
		totalSize++;
	}

	void pop() {
		if (totalSize == 0) {
			cout << "Warning! Stack Underflow.\n";
			return;
		}
		Node *temp;
		temp = topNode;
		topNode = topNode->prevNode;
		free(temp);
		totalSize--;
	}
};

void display()
{
	printf("Choice:\n0\texit\n");
	printf("1\tempty\n");
	printf("2\tsize\n");
	printf("3\ttop\n");
	printf("4\tpush\n");
	printf("5\tpop\n");
}
int main()
{
	stack newStack;
	int n, value;
	display();
	while (~scanf("%d", &n) && n)
	{
		switch (n)
		{
		case 1:
			printf("Empty: %d\n", newStack.empty());
			break;
		case 2:
			printf("Size: %d\n", newStack.size());
			break;
		case 3:
			printf("Top: %d\n", newStack.top());
			//printf("input v: ");
			//scanf("%d",&value);
			break;
		case 4:
			printf("Value: ");
			scanf("%d", &value);
			newStack.push(value);
			break;
		case 5:
			newStack.pop();
			break;
		default:
			break;
		}
		display();
	}
	return 0;
}
