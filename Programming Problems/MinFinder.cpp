#include <iostream>
#include <math.h>

/*
	Recursive Solution
*/
int findMin(int *nums, int length, int min = INFINITY) {
	int middle = length / 2;
	if (nums[middle] < min) {
		min = nums[middle];
	}
	if (length <= 1) {
		return min;
	}
	return findMin(nums, middle - 1, min);
}

/*
	Iterative Solution
*/
int findMinI(int *nums, int length) {

}

int length(int *arr) {
	int length = 0;
	while (*arr) {
		length++;
		arr++;
	}
	return length;
}

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	int nums[] = {4, 5, 1, 2, 3}, size = length(nums);
	std::cout << "Min: " << findMin(nums, size) << std::endl;
	return 0;
}