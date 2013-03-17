#include <iostream>
#include <vector>

class BinarySearchTree {

	/*
		Internal Node Representation
	*/
	typedef struct BinaryTreeNode {
		int data;
		struct BinaryTreeNode *left, *right;
	} BinaryTreeNode;

	BinaryTreeNode *root;

	/*
		Private utility method to create a tree node
	*/
	static BinaryTreeNode *createTreeNode(int data) {
		BinaryTreeNode *node = new BinaryTreeNode;
		node->data = data;
		node->left = 0;
		node->right = 0;
		return node;
	}

	void _addNode(BinaryTreeNode *node, int data) {
		if (node->data > data) {
			if (node->left) {
				_addNode(node->left, data);
			} else {
				node->left = createTreeNode(data);
				return;
			}
		} else {
			if (node->right) {
				_addNode(node->right, data);
			} else {
				node->right = createTreeNode(data);
				return;
			}
		}
	}

	void _inorderTraversal(BinaryTreeNode *node) {
		if (!node) {
			return;
		}
		_inorderTraversal(node->left);
		std::cout << node->data << std::endl;
		_inorderTraversal(node->right);
	}

	void _preorderTraversal(BinaryTreeNode *node) {
		if (!node) {
			return;
		}
		std::cout << node->data << std::endl;
		_preorderTraversal(node->left);
		_preorderTraversal(node->right);
	}

	void _postorderTraversal(BinaryTreeNode *node) {
		if (!node) {
			return;
		}
		_postorderTraversal(node->left);
		_postorderTraversal(node->right);
		std::cout << node->data << std::endl;
	}

	bool _dfsFind(BinaryTreeNode *node, int data) {
		if (!node) {
			return false;
		}
		if (node->data == data) {
			return true;
		}
		return _dfsFind(node->left, data) || _dfsFind(node->right, data);
	}

	void destroyTree(BinaryTreeNode *node) {
		if (!node) {
			return;
		}
		destroyTree(node->left);
		destroyTree(node->right);
		delete node;
	}

	BinarySearchTree(BinaryTreeNode *root) {
		this->root = root;
	}

public:
	BinarySearchTree() {
		this->root = 0;
	}

	~BinarySearchTree() {
		std::cout << "Tree Being Nuked!!!" << std::endl;
		destroyTree(this->root);
	}

	void addNode(int data) {
		if (!this->root) {
			this->root = createTreeNode(data);
		} else {
			_addNode(this->root, data);
		}
	}

	void inorderTraversal() {
		_inorderTraversal(this->root);
	}

	void preorderTraversal() {
		_preorderTraversal(this->root);
	}

	void postorderTraversal() {
		_postorderTraversal(this->root);
	}

	bool dfsFind(int data) {
		return _dfsFind(this->root, data);
	}

	void destroyTree() {
		destroyTree(this->root);
		this->root = 0;
	}

	/*
		Creates a vector of H linked lists where H is the number of levels in the current tree
		Each link lists contains the data of the corresponding level of the tree
	*/
	std::vector<LinkedList<int>> createLevelLinkedLists() {
		if (!this->root) {
			return 0;
		}
		return createLevelLinkedLists(this->root, 0, 1);
	}

	std::vector<LinkedList<int>> createLevelLinkedLists(BinaryTreeNode *node, std::vector<LinkedList<int>> lists, int level) {

	}


	/*
		Creates a minimum height binary search tree from a sorted array
		-start = starting index into array
		-end = final index valid into array
	*/
	static BinaryTreeNode *_sortedArrayToMinTree(int nums[], int start, int end) {
		if (end < start) {
			return 0;
		}
		int mid = (start + end) / 2;
		BinaryTreeNode *node = createTreeNode(nums[mid]);
		node->left = _sortedArrayToMinTree(nums, start, mid - 1);
		node->right = _sortedArrayToMinTree(nums, mid + 1, end);
		return node;
	}

	static BinarySearchTree *sortedArrayToMinTree(int nums[], int start, int end) {
		BinaryTreeNode *node = _sortedArrayToMinTree(nums, start, end);
		return new BinarySearchTree(node);
	}

};

int main(int argc, char *argv[]) {
	BinarySearchTree tree;
	tree.addNode(3);
	tree.addNode(5);
	tree.addNode(2);
	tree.addNode(4);
	std::cout << "Inorder Traversal:" << std::endl;
	tree.inorderTraversal();
	std::cout << "Preorder Traversal:" << std::endl;
	tree.preorderTraversal();
	std::cout << "Postorder Traversal:" << std::endl;
	tree.postorderTraversal();
	std::cout << std::endl;
	std::cout << tree.dfsFind(30) << std::endl;
	std::cout << std::endl;
	//Testing Minimum Binary Search Tree Construction
	int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	BinarySearchTree *sorted = BinarySearchTree::sortedArrayToMinTree(nums, 0, 8);
	sorted->inorderTraversal();
	delete sorted;
	return 0;
}