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
	Problem 1:
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

/*
	Problem 2:
	Implement a method to find the kth to last element in the linked list
*/
LinkedListNode<int> *kthToLast(LinkedListNode<int> *list, int k) {
	if (!list) {
		return 0;
	}
	LinkedListNode<int> *kth = list, *node = list;
	while (k > 0 && node) {
		node = node->next;
		k--;
	}
	if (!node) {
		return 0;
	}
	while (node->next) {
		kth = kth->next;
		node = node->next;
	}
	return kth;
}

/*
	Problem 3:
	Implement a method to delete a node from the middle of a Linked List given only access to that
	node

	What I have done below is not entirely necessary, you only need to switch the current node with the next node
	you do not need to traverse the entire linked list copying over data from next node

	Algorithm:
	-copy data from next node to current node
	-save next next node
	-delete next node
	-adjust next node to point to next next node that was saved
*/
void deleteNode(LinkedListNode<int> *node) {
	if (!node) {
		return;
	}
	LinkedListNode<int> *prev = 0;
	while (node->next) {
		node->data = node->next->data;
		prev = node;
		node = node->next;
	}
	delete node;
	if (prev) {
		prev->next = 0;
	}
}

/*
	Problem 4:
*/


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
	LinkedListNode<int> *kth = kthToLast(list, 3);
	deleteNode(kth);
	list->printList();
	return 0;
}