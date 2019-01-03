#include<iostream>
#include<cstdio>
#include<climits>
using namespace std;

typedef struct node {
	int value;
	struct node *leftChild;
	struct node *rightChild;
};

typedef struct tree
{
	node *root;

	struct tree() {
		root = NULL;
	}

	void insert(int n) {
		node *tempNode = (node *)malloc(sizeof(node));
		tempNode->value = n;
		tempNode->leftChild = NULL;
		tempNode->rightChild = NULL;

		if (root == NULL) {
			root = tempNode;
		}
		else {
			node *currentNode = root;
			node *parentNode = NULL;

			while (true)
			{
				parentNode = currentNode;
				if (n <= parentNode->value) {
					currentNode = currentNode->leftChild;
					if (currentNode == NULL) {
						parentNode->leftChild = tempNode;
						return;
					}
				}
				else {
					currentNode = currentNode->rightChild;
					if (currentNode == NULL) {
						parentNode->rightChild = tempNode;
						return;
					}
				}
			}
		}
	}

	bool search(int n) {
		node *currentNode = root;
		bool found = false;

		while (true)
		{
			if (n == currentNode->value) {
				found = true;
				break;
			}
			else if (n <= currentNode->value)
				currentNode = currentNode->leftChild;
			else
				currentNode = currentNode->rightChild;

			if (currentNode == NULL)
				break;
		}

		if (found)
			cout << n << " is found\n";
		else
			cout << n << " is not found\n";
		
		return found;
	}
};

void preOrder(node *rootNode) {
	if (rootNode == NULL)
		return;

	cout << rootNode->value << " ";
	preOrder(rootNode->leftChild);
	preOrder(rootNode->rightChild);
}

void inOrder(node *rootNode) {
	if (rootNode == NULL)
		return;
	
	inOrder(rootNode->leftChild);
	cout << rootNode->value << " ";
	inOrder(rootNode->rightChild);
}

void postOrder(node *rootNode) {
	if (rootNode == NULL)
		return;

	postOrder(rootNode->leftChild);
	postOrder(rootNode->rightChild);
	cout << rootNode->value << " ";
}

node * findMin(node *currentNode) {
	if (currentNode == NULL) {
		cout << "tree is empty!";
		return currentNode;
	}
	while (currentNode->leftChild != NULL)
	{
		currentNode = currentNode->leftChild;
	}
	//cout << "min " << currentNode->value << "\n";
	return currentNode;
}

node * findMax(node *currentNode) {
	if (currentNode == NULL) {
		cout << "tree is empty!";
		return currentNode;
	}
	while (currentNode->rightChild != NULL)
	{
		currentNode = currentNode->rightChild;
	}
	//cout << "max " <<  currentNode->value << "\n";
	return currentNode;
}

node * deleteNode(node *currentNode, int n) {
	if (currentNode == NULL) 		// empty tree
		return NULL;
	else if (n < currentNode->value)
		currentNode->leftChild = deleteNode(currentNode->leftChild, n);
	else if (n > currentNode->value)
		currentNode->rightChild = deleteNode(currentNode->rightChild, n);
	else {	// node found, let's delete it

		// node has no child
		if (currentNode->leftChild == NULL && currentNode->rightChild == NULL)
			currentNode = NULL;
		else if (currentNode->leftChild == NULL) {	// has only rightchild
			currentNode = currentNode->rightChild;
		}
		else if (currentNode->rightChild == NULL) {	// has only leftchild
			currentNode = currentNode->leftChild;
		}
		else {	// has two child
			node *tempNode = findMin(currentNode->rightChild);
			currentNode->value = tempNode->value;
			currentNode->rightChild = deleteNode(currentNode->rightChild, tempNode->value);
		}
	}

	return currentNode;
}

bool isBST(node *currentNode, int minimum, int maximum) {
	if (currentNode == NULL)
		return true;
	if (currentNode->value >= minimum && currentNode->value <= maximum
		&& isBST(currentNode->leftChild, minimum, currentNode->value)
		&& isBST(currentNode->rightChild, currentNode->value, maximum))
		return true;

	return false;
}

bool isBSTbyInOrderTraversal(node *currentNode, int previous) {
	if (currentNode == NULL)
		return true;
	if (!isBSTbyInOrderTraversal(currentNode->leftChild, previous))
		return false;
	if (currentNode->value < previous)
		return false;
	previous = currentNode->value;
	return isBSTbyInOrderTraversal(currentNode->rightChild, previous);
}

int main() {
	ios_base::sync_with_stdio(0);

	tree t;
	t.insert(45);
	t.insert(30);
	t.insert(60);
	t.insert(1);
	t.insert(5);
	t.insert(100);
	t.insert(88);
	t.search(15);
	t.search(30);
	preOrder(t.root); cout << "\n";
	inOrder(t.root); cout << "\n";
	postOrder(t.root);
	cout << "\n";

	cout << "min " << findMin(t.root)->value << "\n";
	cout << "max " << findMax(t.root)->value << "\n";
	isBST(t.root, INT_MIN, INT_MAX) ? cout << "BST!\n" : cout << "Not BST!\n";
	isBSTbyInOrderTraversal(t.root, INT_MIN) ? cout << "BST!\n" : cout << "Not BST!\n";

	tree s;
	s.insert(0);
	s.insert(1);
	s.search(30);
	s.search(1);
	s.search(60);

	tree a;
	cout << " min " << findMin(a.root) << "\n";
	return 0;
}
