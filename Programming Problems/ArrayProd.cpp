#include <iostream>

/*
	Given an array of integers, replace each number in the array 
	with the product of all of the integers except for the one being replaced.

	What if there is a zero in the array?
	-product is zero
	-cannot divide by zero
*/
void replaceProd(int *nums, int length) {
	int product = 1;
	for (int i = 0; i < length; i++) {
		product *= nums[i];
	}
	std::cout << "Product: " << product << std::endl;
	for (int i = 0; i < length; i++) {
		if (nums[i] != 0) {
			nums[i] = product / nums[i];
		}
	}
}

void printArray(int *nums, int length) {
	if (length < 0) {
		return;
	}
	std::cout << "{ ";
	for (int i = 0; i < length; i++) {
		std::cout << nums[i];
		if (i != length - 1) {
			std::cout << ", ";
		}
	}
	std::cout << " }" << std::endl;
}

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	int nums[5] = {-2, 2, 10, 25, -1};
	printArray(nums, 5);
	replaceProd(nums, 5);
	printArray(nums, 5);
	return 0;
}