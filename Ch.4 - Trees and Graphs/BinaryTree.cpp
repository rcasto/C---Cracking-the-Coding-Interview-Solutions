#include <iostream>

struct Node {
	int data;
	struct Node *left, *right;
};

Node *createNode(int data) {
	Node *node = new Node;
	node->data = data;
	node->left = 0;
	node->right = 0;
	return node;
}

int height(Node *tree, int accum = 0) {
	if (!tree) {
		return accum;
	}
	int left = height(tree->left, accum + 1);
	int right = height(tree->right, accum + 1);
	return left > right ? left : right;
}

bool isBalanced(Node *tree) {
	if (!tree) {
		return false;
	}
	int left = height(tree->left);
	int right = height(tree->right);
	int diff = left - right;
	return (diff >= -1) && (diff <= 1);
}

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	Node *tree = createNode(4);
	tree->left = createNode(2);
	tree->left->left = createNode(3);
	std::cout << isBalanced(tree) << std::endl;
	tree->right = createNode(1);
	std::cout << isBalanced(tree) << std::endl;
	return 0;
}