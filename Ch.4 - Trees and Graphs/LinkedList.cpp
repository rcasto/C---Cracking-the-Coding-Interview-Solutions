#include <iostream>

template <class T>
class LinkedList {

	/* 
		Internal Node Representation
	*/
	typedef struct Node {
		T data;
		struct Node *next;
	} Node;

	Node *createNode(T data) {
		Node *node = new Node;
		node->data = data;
		node->next = 0;
		return node;
	}

	Node *head;
	int size;

	void _add(Node *node, T data) {
		while (node->next) {
			node = node->next;
		}
		node->next = createNode(data);
	}

	bool _remove(Node *node, T data) {
		while (node->next) {
			if (node->next->data == data) {
				node->next = node->next->next;
				this->size--;
				return true;
			}
			node = node->next;
		}
		return false;
	}

public:
	LinkedList() {
		this->head = 0;
		this->size = 0;
	}

	void add(T data) {
		if (!this->head) {
			this->head = createNode(data); 
		} else {
			_add(this->head, data);
		}
		this->size++;
	}

	bool remove(T data) {
		if (this->head->data == data) {
			this->head = this->head->next;
			this->size--;
			return true;
		} else {
			return _remove(this->head, data);
		}
	}

	bool removeAll(T data) {
		bool removed = false;
		while (remove(data)) {
			removed = true;
		}
		return removed;
	}

	int getNumNodes() {
		return this->size;
	}

	void toString() {
		Node *node = this->head;
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
int main(int argc, char *argv[]) {
	LinkedList<int> list;
	list.add(3);
	list.add(5);
	list.add(35);
	list.add(3);
	list.toString();
	std::cout << "Size: " << list.getNumNodes() << std::endl;
	list.removeAll(3);
	list.toString();
	std::cout << "Size: " << list.getNumNodes() << std::endl;
	return 0;
}
*/