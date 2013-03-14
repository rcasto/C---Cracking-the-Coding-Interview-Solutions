#include <iostream>

template <class T>
class DoublyLinkedList {

	struct Node {
		T data;
		struct Node *next, *prev;
	};

	Node *createNode(T data, Node *prev = 0) {
		Node *node = new Node;
		node->data = data;
		node->prev = prev;
		node->next = 0;
		return node;
	}

	Node *head, *tail;

public:
	DoublyLinkedList() {
		this->head = 0;
		this->tail = 0;
	}

	bool add(T data) {
		if (!this->head) {
			this->head = createNode(data);
			this->tail = this->head;
			return true;
		}
		this->tail->next = createNode(data, this->tail);
		this->tail = this->tail->next;
		return true;
	}

	bool add(T *data) {
		while (*data) {
			add(*data);
			data++;
		}
		return true;
	}

	bool remove(T data) {
		if (!this->head) {
			return false;
		}
		//Traverse until element found or end of list reached
		Node *node = this->head;
		while (node && node->data != data) {
			node = node->next;
		}
		//Element not in list
		if (!node) {
			return false;
		}
		//Removing head
		if (!node->prev) {
			Node *tmp = this->head;
			this->head = this->head->next;
			if (this->head) {
				this->head->prev = 0;
			}
			delete tmp;
			return true;
		}
		//Removing tail
		if (!node->next) {
			Node *tmp = this->tail;
			this->tail = this->tail->prev;
			this->tail->next = 0;
			delete tmp;
			return true;
		}
		//Removing middle node
		node->prev->next = node->next;
		if (node->next) {
			node->next->prev = node->prev;
		}
		delete node;
		return true;
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

	std::string reverseToString() {
		std::string result = "";
		Node *node = this->tail;
		while (node) {
			result += node->data;
			if (node->prev) {
				result += " -> ";
			}
			node = node->prev;
		}
		return result;
	}

};

template <class T>
struct Level {
	DoublyLinkedList<T> list;
	Level *nextLevel;
};

template <class T>
Level<T> *createLevel(DoublyLinkedList<T> list) {
	Level<T> *level = new Level<T>;
	level->list = list;
	level->nextLevel = 0;
	return level;
}

template <class T>
Level<T> *flattenLevels(Level<T> *levels) {
	Level<T> flatLevel = new Level<T>;
	while (levels) {
		
		levels = levels->nextLevel;
	}
}

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	DoublyLinkedList<std::string> list1, list2, list3, list4;
	//populate list 1
	list1.add("testing");
	list1.add("microsoft");
	list1.add("shit");
	//populate list 2
	list2.add("stuff");
	list2.add("math");
	list2.add("computer");
	//populate list 3
	list3.add("weed");
	list3.add("iphone");
	list3.add("google");
	//populate list 4
	std::string data[3] = {"hi", "bye", "stuff"};
	list4.add(data);
	std::cout << list4.toString() << std::endl;
	//create level lists
	Level<std::string> *level = createLevel(list1);
	level->nextLevel = createLevel(list2);
	level->nextLevel->nextLevel = createLevel(list3);
	//flattenLevels(level);
	return 0;
}