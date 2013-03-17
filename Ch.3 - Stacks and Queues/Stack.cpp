#include <iostream>

/*
	Implementation of a stack using a singly linked list
*/
template <class T>
class Stack {

	struct Node {
		T data;
		struct Node *next;
	};

	Node *createNode(T data) {
		Node *node = new Node;
		node->data = data;
		node->next = 0;
		return node;
	}

	Node *head;
	int numItems;

public:
	Stack() {
		this->numItems = 0;
		this->head = 0;
	}

	bool push(T data) {
		this->numItems++;
		if (!this->head) {
			this->head = createNode(data);
			return true;
		}
		Node *next = this->head;
		this->head = createNode(data);
		this->head->next = next;
		return true;
	}

	T pop() {
		if (!this->head) {
			throw "Cannot pop from an empty stack";
		}
		T data = this->head->data;
		Node *tmp = this->head->next;
		delete this->head;
		this->head = tmp;
		this->numItems--;
		return data;
	}

	int size() {
		return this->numItems;
	}

	std::string toString() {
		std::string result = "";
		Node *node = this->head;
		while (node) {
			result += node->data;
			if (node->next) {
				result += " -> ";
			}
			node = node->next;
		}
		return result;
	}

};

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	Stack<std::string> stack;
	stack.push("test1");
	stack.push("test2");
	stack.push("test3");
	std::cout << stack.size() << std::endl;
	std::cout << stack.toString() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.toString() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.toString() << std::endl;
	std::cout << stack.pop() << std::endl;
	std::cout << stack.toString() << std::endl;
	std::cout << stack.size() << std::endl;
	stack.push("blah");
	std::cout << stack.size() << std::endl;
	return 0;
}