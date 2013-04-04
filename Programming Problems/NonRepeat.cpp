/*
	Given an array of numbers ranging from 1 to N
	-All numbers repeat twice except for 2, find which 2 don't repeat
*/

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>

/*
	This algorithm makes use of the knowledge of the range of numbers
	-scan through array filling up buckets
	-scan through buckets checking for one with 1 in them
	O(rangeMax) = space complexity
	O(rangeMax * length) = time complexity
*/
void findNonRepeat(int *nums, int length, int rangeMax) {
	int *buckets = new int[rangeMax](), num;
	// Fill up buckets
	for (int i = 0; i < length; i++) {
		buckets[nums[i] - 1]++;
	}
	// Check buckets
	for (int i = 0; i < rangeMax; i++) {
		if (buckets[i] == 1) {
			std::cout << i + 1 << std::endl;
		}
	}
}

int findNonRepeat(int *nums, int length) {
	int remaining = 0;
	for (int i = 0; i < length; i++) {
		remaining ^= nums[i];
	}
	return remaining;
}

int *genRandomArray(int numNums, int rangeMax) {
	int *nums = new int[numNums];
	// Seed generator
	srand(time(0));
	// Fill up array with random values
	for (int i = 0; i < numNums; i++) {
		nums[i] = rand() % rangeMax;
	}
	return nums;
}

int stringToNumber (const std::string &text) {
	std::istringstream ss(text);
	int result;
	return ss >> result ? result : 0;
}

void printArray(int *arr) {

}

int main(int argc, char *argv[]) {
	/*
	if (argc < 3) {
		std::cerr << "Not enough parameters provided - (N, X)" << std::endl;
		exit(1);
	}
	// Extract input parameters
	int N = stringToNumber(argv[1]);
	int X = stringToNumber(argv[2]);

	std::cout << "N: " << N << std::endl;
	std::cout << "X: " << X << std::endl;

	// Generate random array of size X with numbers ranging from 1 - N
	int *nums = genRandomArray(X, N);
	findNonRepeat(nums, X);

	delete nums;
	*/

	int nums[10] = {3, 4, 2, 9, 9, 15, 2, 4, 3};
	std::cout << findNonRepeat(nums, 10) << std::endl;

	return 0;
}