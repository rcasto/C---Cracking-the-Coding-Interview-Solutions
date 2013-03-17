#include <iostream>

class MinStack {

	struct Node {
		int data;
		//Stack links
		struct Node *next;
		//Min links
		struct Node *min;
	};

	Node *createNode(int data) {
		Node *node = new Node;
		node->data = data;
		node->next = 0;
		node->min = 0;
		return node;
	}

	Node *head, *min;

public:
	MinStack() {
		this->head = 0;
		this->min = 0;
	}

	bool push(int data) {
		if (!head) {
			head = createNode(data);
			min = head;	
			return true;
		}
		//update stack list
		Node *node = createNode(data);
		node->next = head;
		head = node;
		//update min list
		if (node->data < min->data) {
			node->next = min;
			min = node;
		}
		return true;
	}

	int pop() {
		if (!head) {
			throw "Cannot pop from an empty stack";
		}
		int data = head->data;
		Node *node = head;
		head = head->next;
		if (node == min) {
			min = min->next;
		}
		delete node;
		return data;
	}

	int minNum() {
		if (!min) {
			return -1;
		}
		return min->data;
	}

	void printStack() {
		Node *node = head;
		while (node) {
			std::cout << node->data;
			if (node->next) {
				std::cout << " -> ";
			}
			node = node->next;
		}
		std::cout << std::endl;
	}

};

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	MinStack stack;
	stack.push(3);
	std::cout << "Min: " << stack.minNum() << std::endl;
	stack.push(2);
	std::cout << "Min: " << stack.minNum() << std::endl;
	stack.push(5);
	std::cout << "Min: " << stack.minNum() << std::endl;
	stack.push(4);
	std::cout << "Min: " << stack.minNum() << std::endl;
	stack.printStack();
	stack.pop();
	std::cout << "Min: " << stack.minNum() << std::endl;
	stack.printStack();
	stack.pop();
	std::cout << "Min: " << stack.minNum() << std::endl;
	stack.printStack();
	stack.pop();
	std::cout << "Min: " << stack.minNum() << std::endl;
	stack.printStack();
	stack.pop();
	std::cout << "Min: " << stack.minNum() << std::endl;
	stack.printStack();
	return 0;
}