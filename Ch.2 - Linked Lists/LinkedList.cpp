#include <iostream>
#include <set>
#include <cstdlib>

template <class T>
class LinkedListNode {

public:

	LinkedListNode *next;
	T data;

	LinkedListNode(T data) {
		this->data = data;
		this->next = 0;
	}

	LinkedListNode *add(T data) {
		if (this->next) {
			this->next->add(data);
		} else {
			this->next = new LinkedListNode(data);
			return this->next;
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
	Implement a method that partitions a linked list around a value x, all nodes that have value less than x
	come before x and all nodes that have value greater than or equal to x come after

	Note: it doesn't need to sort the linked list, but simply seperate the two sides
	
	ex) input: 1 -> 3 -> 4 -> 2 -> 7 -> 3 -> 1 , 3
		output: 1 -> 1 -> 2 -> 3 -> 3 -> 4 -> 7
*/
void partitionList(LinkedListNode<int> *list, int x) {
	LinkedListNode<int> *node = list, *runner = list;
	while (node) {
		if (node->data >= x) {
			while (runner && runner->data >= x) {
				runner = runner->next;
			}
			if (runner) {
				int tmp = runner->data;
				runner->data = node->data;
				node->data = tmp;
				//debug
				list->printList();
			}
		}
		node = node->next;
		runner = node;
	}
}

/*
	Problem 5:
	A number is given as a series of nodes consitsting of 1 digit of a number.
	The nodes containing these numbers are ordered such that the first node is the one's digit and
	then the digits ascend from there till the end of the number is reached.

	Given two numbers formed as such, add them.
*/
LinkedListNode<int> *add(LinkedListNode<int> *num1, LinkedListNode<int> *num2) {
	if (!num1 || !num2) {
		return 0;
	}
	LinkedListNode<int> *sumList = 0, *node;
	int sum, carry = 0;
	while (num1 && num2) {
		sum = num1->data + num2->data + carry;
		carry = sum / 10;
		sum %= 10;
		if (!sumList) {
			sumList = new LinkedListNode<int>(sum);
			node = sumList;
		} else {
			node->next = new LinkedListNode<int>(sum);
			node = node->next;
		}
		num1 = num1->next;
		num2 = num2->next;
	}
	num1 = num1 ? num1 : num2;
	while (num1) {
		sum = num1->data + carry;
		carry = 0;
		node->next = new LinkedListNode<int>(sum);
		node = node->next;
		num1 = num1->next;
	}
	return sumList;
}

/*
	Helper method:  Converts number input to Linked List
	Note: One's digit comes first
*/
LinkedListNode<int> *numToList(std::string num) {
	int length = num.size(), digit;
	LinkedListNode<int> *list = 0, *node;
	for (int i = 0; i < length; i++) {
		digit = atoi(num.substr(length - i - 1, 1).data());
		if (i == 0) {
			list = new LinkedListNode<int>(digit);
			node = list;
		} else {
			node->next = new LinkedListNode<int>(digit);
			node = node->next;
		}
	}
	return list;
}

/*
	Problem 6:
	Find the beginning of the loop in a corrupt linked list, a linked list that has a circular portion

	Note: null is returned if list does not have a loop within it
*/
LinkedListNode<int> *findLoopStart(LinkedListNode<int> *list) {
	if (!list) {
		return 0;
	}
	LinkedListNode<int> *slow = list, *fast = list;
	while (fast) {
		slow = slow->next;
		fast = fast->next;
		if (fast) {
			fast = fast->next;
		}
		if (slow == fast) {
			break;
		}
	}
	if (!fast) {
		return 0;
	}
	slow = list;
	while (slow != fast) {
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}

/*
	Problem 7:
	Implement a method to find out if a linked list is a palindrome

	My algorithm:
	-find midpoint of linked list
	-compare data from two pointers until middle pointer reaches the end of the linked list

	Uses helper method which finds the middle node of the linked list

	Space complexity: O(1)
	Time complexity: O(n)
*/
LinkedListNode<int> *findMiddle(LinkedListNode<int> *list) {
	if (!list) {
		return 0;
	}
	LinkedListNode<int> *fast = list, *slow = list;
	while (fast) {
		fast = fast->next;
		if (fast) {
			fast = fast->next;
			slow = slow->next;
		}
	}
	return slow;
}

bool isPalindrome(LinkedListNode<int> *list) {
	if (!list) {
		return false;
	}
	LinkedListNode<int> *left = list, *right = findMiddle(list);
	right = right->next;
	while (right) {
		if (left->data != right->data) {
			return false;
		}
		left = left->next;
		right = right->next;
	}
	return true;
}


/* Debugging/Testing */
int main(int argc, char *argv[]) {
	// LinkedListNode<int> *list = new LinkedListNode<int>(3);
	// list->add(5);
	// list->add(2);
	// list->add(10);
	// list->add(5);
	// list->add(2);
	// list->add(3);
	// list->add(5);
	// list->add(9);
	//list->printList();
	//std::cout << std::endl;
	//removeDups2(list);
	//list->printList();
	//partitionList(list, 3);
	//list->printList();
	// std::string num;
	// LinkedListNode<int> *num1, *num2;
	// std::cout << "Enter a number: ";
	// std::cin >> num;
	// num1 = numToList(num);
	// std::cout << "Enter a number: ";
	// std::cin >> num;
	// num2 = numToList(num);
	// num1->printList();
	// num2->printList();
	// add(num1, num2)->printList();

	/*
	LinkedListNode<int> *circle = new LinkedListNode<int>(1), *loopStart, *loopEnd;
	circle->next = new LinkedListNode<int>(2);
	circle->next->next = new LinkedListNode<int>(3);
	loopStart = circle->next->next;
	loopStart->next = new LinkedListNode<int>(4);
	loopStart->next->next = new LinkedListNode<int>(5);
	loopStart->next->next->next = new LinkedListNode<int>(6);
	loopEnd = loopStart->next->next->next;
	loopEnd->next = loopStart;
	LinkedListNode<int> *start = findLoopStart(circle);
	std::cout << start->data << std::endl;
	*/

	LinkedListNode<int> *list = new LinkedListNode<int>(1);
	list->next = new LinkedListNode<int>(2);
	list->next->next = new LinkedListNode<int>(1);
	list->printList();
	std::cout << isPalindrome(list) << std::endl;
	list->next->next->next = new LinkedListNode<int>(4);
	list->printList();
	std::cout << isPalindrome(list) << std::endl;
	return 0;
}