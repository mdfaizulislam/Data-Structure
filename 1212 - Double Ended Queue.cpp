#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

typedef struct node {
	int v;
	struct node *left;
	struct node *right;
};

typedef struct queue {
	int qsize;
	node *front;
	node *back;
};

void init(queue *q) {
	q->qsize = 0;
	q->front = NULL;
	q->back = NULL;
}

void push_left(queue *q, int value) {
	node *tmp = (node *)malloc(sizeof(node));
	tmp->v = value;
	tmp->left = NULL;
	tmp->right = NULL;
	if (q->qsize == 0) {
		q->back = tmp;
		q->front = tmp;
	}
	else {
		node *prev = q->back;
		q->back->left = tmp;
		q->back = tmp;
		q->back->right = prev;
	}
	q->qsize++;
}

int pop_left(queue *q) {
	node *tmp = q->back;
	q->back = q->back->right;
	int v = tmp->v;
	free(tmp);
	q->qsize--;
	return v;
}

void push_right(queue *q, int value) {
	node *tmp = (node *)malloc(sizeof(node));
	tmp->v = value;
	tmp->left = NULL;
	tmp->right = NULL;
	if (q->qsize == 0) {
		q->back = tmp;
		q->front = tmp;
	}
	else {
		node *prev = q->front;
		q->front->right = tmp;
		q->front = tmp;
		q->front->left = prev;
	}
	q->qsize++;
}

int pop_right(queue *q) {
	node *tmp = q->front;
	q->front = q->front->left;
	int v = tmp->v;
	free(tmp);
	q->qsize--;
	return v;
}

int Size(queue *q) {
	return q->qsize;
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int T, n, m, choice;
	char str[20];
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		
		cin >> n >> m;

		cout << "Case " << tc << ":\n";
		
		queue q;
		init(&q);
		
		while (m--)
		{
			cin >> str;
			if (strcmp(str, "pushLeft") == 0) {
				cin >> choice;
				if (Size(&q) < n) {
					push_left(&q, choice);
					cout << "Pushed in left: " << choice << "\n";
				}
				else
				{
					cout << "The queue is full\n";
				}
			}
			else if (strcmp(str, "pushRight") == 0) {
				cin >> choice;
				if (Size(&q) < n) {
					push_right(&q, choice);
					cout << "Pushed in right: " << choice << "\n";
				}
				else
				{
					cout << "The queue is full\n";
				}
			}
			else if (strcmp(str, "popLeft") == 0) {
				if (Size(&q) > 0) {
					cout << "Popped from left: " << pop_left(&q) << "\n";
				}
				else {
					cout << "The queue is empty\n";
				}
			}
			else if (strcmp(str, "popRight") == 0) {
				if (Size(&q) > 0) {
					cout << "Popped from right: " << pop_right(&q) << "\n";
				}
				else {
					cout << "The queue is empty\n";
				}
			}
		}
	}
	return 0;
}