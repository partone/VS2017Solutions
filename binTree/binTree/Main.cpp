#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct node {
	int value;
	node *left;
	node *right;
} node;

class BinaryTree {
public:
	node * head = NULL;

	void insert(int n) {
		if (head == NULL) {
			node * newNode;
			newNode->value = n;
			newNode->left = NULL;
			newNode->right = NULL;
			head = newNode;
		}
	}

	void printTreeDFS() {
		printTreeRec(head);
	}

private:
	void printTreeRec(node * currentNode) {
		if (currentNode->left != NULL) {
			printTreeRec(currentNode->left);
		}
		else if (currentNode->right != NULL) {
			printTreeRec(currentNode->right);
		}
		else {
			cout << currentNode->value << " ";
		}
	}
};

int main() {
	int x;
	BinaryTree Eric;
	Eric.insert(4);
	Eric.printTreeDFS();

	cin >> x;
	return 0;
}