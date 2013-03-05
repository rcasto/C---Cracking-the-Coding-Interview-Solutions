#include <iostream>
#include <set>

template <class T>
class LinkedListNode {

	LinkedListNode *next;
	T data;

public:
	LinkedListNode(T data) {
		this->data = data;
		this->next = 0;
	}

	void add(T data) {
		if (this->next) {
			this->next->add(data);
		} else {
			this->next = new LinkedListNode(data);
		}
	}

	void printList() {
		std::cout << data;
		if (this->next) {
			std::cout << " -> ";
			this->next->printList();
		} else {
			std::cout << std::endl;
		}
	}

	T getData() {
		return this->data;
	}

	LinkedListNode *getNext() {
		return this->next;
	}

};

/* Cracking the Coding Interview Problems */

/* 
	Problem 1
	Implement a method to remove duplicates from an unsorted linked list
	How would you solve this problem if a temporary buffer were not allowed? Use two pointers O(n^2)
*/
void removeDups(LinkedListNode<int> list) {
	std::set<int> nums;
	std::pair<std::set<int>::iterator, bool> ret;
	nums.insert(list.getData());
	LinkedListNode *next = list.getNext();
	while (next) {
		ret = nums.insert(next->getData());
		next = next->getNext();
		if (next && !ret.second) {
			next = next->getNext();
		}
	}
}


/* Debugging/Testing */
int main(int argc, char *argv[]) {
	LinkedListNode<int> list(3);
	list.add(5);
	list.add(2);
	list.add(10);
	list.printList();
	removeDups(list);
	list.printList();
	return 0;
}