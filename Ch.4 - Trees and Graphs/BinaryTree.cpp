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

/*
	Chapter 4 - Problem 1
*/
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
	Chapter 4 - Problem 3
*/
Node *createMinBST(int *data, Node *tree = 0) {
	if (!*data) {
		return ;
	}
	if (!tree) {
		tree = createNode(*data);
		return createMinBST(++data, tree);
	}
	if (*data >= tree->data) {
		tree->right = createNode(*data);
		return createMinBST(++data, tree->right);
	} else {
		tree->left = createNode(*data);
		return createMinBST(++data, tree->left);
	}
}

void printTree(Node *tree) {
	if (!tree) {
		return;
	}
	std::cout << tree->data << std::endl;
	printTree(tree->left);
	printTree(tree->right);
}

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	//Testing problem 1
	Node *tree = createNode(4);
	tree->left = createNode(2);
	tree->left->left = createNode(3);
	std::cout << isBalanced(tree) << std::endl;
	tree->right = createNode(1);
	std::cout << isBalanced(tree) << std::endl;
	std::cout << std::endl;
	//Testing problem 3
	int data[7] = {1, 3, 5, 6, 7, 8};
	Node *bst = createMinBST(data);
	printTree(bst);
	return 0;
}