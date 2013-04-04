#include <iostream>
#include <stack>

struct Node {
	int data;
	struct Node *left, *right;
};

Node *createNode(int data, Node *parent = 0, bool left = false) {
	Node *node = new Node;
	node->data = data;
	node->left = 0;
	node->right = 0;
	if (parent) {
		if (left) {
			parent->left = node;
		} else {
			parent->right = node;
		}
	}
	return node;
}

/*
	Recursive Inorder Tree Traversal
*/
void inorderR(Node *tree) {
	if (!tree) {
		return;
	}
	inorderR(tree->left);
	std::cout << tree->data << std::endl;
	inorderR(tree->right);
}

/*
	Iterative Inorder Tree Traversal

	Doesn't require excess memory on function stack
*/
void inorder(Node *tree) {
	if (!tree) {
		return;
	}
	std::stack<Node *> stack;
	Node *current, *prev = 0;
	stack.push(tree);
	while (!stack.empty()) {
		current = stack.top();
		if ((!prev || prev->left == current) && current->left) {
			stack.push(current->left);
		} else {
			std::cout << current->data << std::endl;
			stack.pop();
			if (current->right) {
				stack.push(current->right);
			}
		}
		prev = current;
	}
}

/*
	Recusrive Preorder Tree Traversal
*/
void preorderR(Node *tree) {
	if (!tree) {
		return;
	}
	std::cout << tree->data << std::endl;
	preorderR(tree->left);
	preorderR(tree->right);
}

/*
	Iterative Preorder Tree Traversal
*/
void preorder(Node *tree) {
	if (!tree) {
		return;
	}
	std::stack<Node *> stack;
	Node *current;
	stack.push(tree);
	while (!stack.empty()) {
		current = stack.top();
		std::cout << current->data << std::endl;
		stack.pop();
		if (current->right) {
			stack.push(current->right);
		}
		if (current->left) {
			stack.push(current->left);
		}
	}
}

/*
	Recursive PostOrder Tree Traversal
*/
void postorderR(Node *tree) {
	if (!tree) {
		return;
	}
	postorderR(tree->left);
	postorderR(tree->right);
	std::cout << tree->data << std::endl;
}

/*
	Iterative PostOrder Tree Traversal
*/
void postorder(Node *tree) {
	if (!tree) {
		return;
	}
	std::stack<Node *> stack;
	Node *current, *prev = 0;
	stack.push(tree);
	while (!stack.empty()) {
		current = stack.top();
		if (!prev || prev->left == current || prev->right == current) {
			if (current->left) {
				stack.push(current->left);
			} else if (current->right) {
				stack.push(current->right);
			}
		} else if (current->left == prev) {
			if (current->right) {
				stack.push(current->right);
			}
		} else {
			std::cout << current->data << std::endl;
			stack.pop();
		}
		prev = current;
	}
}

/*
	Recursive maximum height of tree
*/
int maxHeightR(Node *tree, int accum = 0) {
	if (!tree) {
		return accum;
	}
	int left = maxHeightR(tree->left, accum + 1);
	int right = maxHeightR(tree->right, accum + 1);
	return left > right ? left : right;
}

/*
	Iterative maximum height of tree

	Uses a PostOrder traversal of the tree
*/
int maxHeight(Node *tree) {
	if (!tree) {
		return 0;
	}
	std::stack<Node *> stack;
	Node *current, *prev = 0;
	int maxDepth = 0;
	stack.push(tree);
	while (!stack.empty()) {
		current = stack.top();
		if (!prev || prev->left == current || prev->right == current) {
			if (current->left) {
				stack.push(current->left);
			} else if (current->right) {
				stack.push(current->right);
			}
		} else if (current->left == prev) {
			if (current->right) {
				stack.push(current->right);
			}
		} else {
			if (stack.size() > maxDepth) {
				maxDepth = stack.size();
			}
			stack.pop();
		}
		prev = current;
	}
	return maxDepth;
}

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	Node *tree = createNode(3);
	Node *tmp = createNode(2, tree, true);
	createNode(1, tmp, true);
	createNode(5, tree, false);
	// Inorder
	inorderR(tree);
	std::cout << std::endl;
	inorder(tree);
	std::cout << std::endl;
	// Preorder
	preorderR(tree);
	std::cout << std::endl;
	preorder(tree);
	std::cout << std::endl;
	// Postorder
	postorderR(tree);
	std::cout << std::endl;
	postorder(tree);
	std::cout << std::endl;
	// Max Height
	std::cout << "Max Height R: " << maxHeightR(tree) << std::endl;
	std::cout << "Max Height I: " << maxHeight(tree) << std::endl;
	return 0;
}