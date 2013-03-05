#include <iostream>
#include <set>

template <class T>
class LinkedListNode {

public:

	LinkedListNode *next;
	T data;

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

};

/* Cracking the Coding Interview Problems */

/* 
	Problem 1
	Implement a method to remove duplicates from an unsorted linked list
	How would you solve this problem if a temporary buffer were not allowed? Use two pointers O(n^2) time, O(1) space

	The method directly below has O(n) time and O(n) space complexity
*/
void removeDups(LinkedListNode<int> *list) {
	if (!list) {
		return;
	}
	LinkedListNode<int> *prev = list, *next = list->next;
	std::set<int> nums;
	std::pair<std::set<int>::iterator, bool> ret;
	//Make initial insert
	nums.insert(list->data);
	//Check next data to make sure not already in list
	while (next) {
		ret = nums.insert(next->data);
		if (!ret.second) {
			prev->next = next->next;
			delete next;
			next = prev->next;
		} else {
			prev = next;
			next = next->next;
		}
	}
}

/* 
	Implementation of remove dups that does not require any extra space or temporary buffer
*/
void removeDups2(LinkedListNode<int> *list) {
	LinkedListNode<int> *current = list, *prev = list, *next = list->next;
	while (current) {
		while (next) {
			if (next->data == current->data) {
				prev->next = next->next;
				delete next;
				next = prev->next;
			} else {
				prev = next;
				next = next->next;
			}
		}
		current = current->next;
		prev = current;
		if (current) {
			next = current->next;
		}
	}
}


/* Debugging/Testing */
int main(int argc, char *argv[]) {
	LinkedListNode<int> *list = new LinkedListNode<int>(3);
	list->add(5);
	list->add(2);
	list->add(10);
	list->add(5);
	list->add(2);
	list->add(3);
	list->add(5);
	list->add(9);
	list->printList();
	removeDups2(list);
	list->printList();
	return 0;
}