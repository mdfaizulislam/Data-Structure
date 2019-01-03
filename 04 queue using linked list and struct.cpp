#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
using namespace std;

typedef struct node {
	int data;
	struct node *nextNode;
};

typedef struct queue {
	node *frontNode;
	node *backNode;
	unsigned int count;
	struct queue()
	{
		frontNode = NULL;
		backNode = NULL;
		count = 0;
	}

	void push_back(int value) {
		node *temp;
		temp = (node *)malloc(sizeof(node));
		temp->data = value;
		temp->nextNode = NULL;
		if (frontNode == NULL)
		{
			frontNode = temp;
			backNode = temp;
		}
		else
		{
			backNode->nextNode = temp;
			backNode = temp;
		}
		count++;
	}

	void pop_front() {
		if (count == 0) {
			cout << "Warning! Queue underflow.\n";
			return;
		}
		node *temp;
		temp = frontNode;
		frontNode = frontNode->nextNode;
		free(temp);
		count--;
	}

	int front() {
		if (count == 0) {
			cout << "Warning! Queue underflow.\n";
			return NULL;
		}
		return frontNode->data;
	}
	
	int back() {
		if (count == 0) {
			cout << "Warning! Queue underflow.\n";
			return NULL;
		}
		return backNode->data;
	}

	bool empty() {
		return count == 0;
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
			newQueue.push_back(value);
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
