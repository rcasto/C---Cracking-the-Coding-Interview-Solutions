#include <iostream>
#include <string>

template <class T>
class BinaryTree {

public:

	typedef struct BinaryTreeNode {
		T data;
		struct BinaryTreeNode *left, *right;
	} BinaryTreeNode;

	static BinaryTreeNode *createBinaryTreeNode(T data) {
		BinaryTreeNode *node = new BinaryTreeNode;
		node->data = data;
		node->left = 0;
		node->right = 0;
		return node;
	}
	
	static std::string inorderTraversal(BinaryTreeNode *node) {
		if (!node) {
			return "";
		}
		std::cout << node->data << std::endl;
		std::string result = "";
		result += inorderTraversal(node->left);
		result += " " + node->data;
		result += " " + inorderTraversal(node->right);
		return result;
	}

	static BinaryTreeNode *sortedArrayToTree(int sorted[], int start, int end) {
		if (end < start) {
			return 0;
		}
		int mid = (end + start) / 2;
		BinaryTreeNode *node = BinaryTree<int>::createBinaryTreeNode(sorted[mid]);
		node->left = sortedArrayToTree(sorted, start, mid - 1);
		node->right = sortedArrayToTree(sorted, mid + 1, end);
		return node;
	}

};

int main(int argc, char *argv[]) {
	int sorted[10];
	for (int i = 0; i < 10; i++) {
		sorted[i] = i;
	}
	BinaryTree<int>::BinaryTreeNode *node = BinaryTree<int>::sortedArrayToTree(sorted, 0, 9);
	std::cout << BinaryTree<int>::inorderTraversal(node);
	return 0;
}