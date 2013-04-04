#include <iostream>
#include <cstdlib>
#include <ctime>

int **zeroOut(int **nums, int rows, int cols) {
	if (!nums) {
		return 0;
	}
	bool *rowToggle = new bool[rows]();
	bool *colToggle = new bool[cols]();
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (nums[i][j] == 0) {
				rowToggle[i] = true;
				colToggle[j] = true;
			}
		}
	}
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (rowToggle[i] || colToggle[j]) {
				nums[i][j] = 0;
			}
		}
	}
	delete rowToggle;
	delete colToggle;
	return nums;
}

int numRows(int **nums) {
	if (!nums) {
		return 0;
	}
	int rows = 0;
	while (*nums) {
		rows++;
		nums++;
	}
	return rows;
}

int numCols(int **nums) {
	if (!nums) {
		return 0;
	}
	int *tmp = nums[0];
	int cols = 0;
	while (*tmp) {
		tmp++;
		cols++;
	}
	return cols;
}

int **genRandom(int rows, int cols) {
	int **nums = new int *[rows];
	srand(time(0));
	for (int i = 0; i < rows; i++) {
		nums[i] = new int[cols];
		for (int j = 0; j < cols; j++) {
			if (rand() % 2 == 0) {
				nums[i][j] = 0;
			} else {
				nums[i][j] = 1;
			}
		}
	}
	return nums;
}

void printArray(int **nums, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			std::cout << nums[i][j];
			if (j != cols - 1) {
				std::cout << ", ";
			}
		}
		std::cout << std::endl;
	}
}

/*
	Debugging/Testing
*/
int main(int argc, char *argv[]) {
	int rows, cols;
	std::cout << "Number of Rows: ";
	std::cin >> rows;
	std::cout << "Number of Columns: ";
	std::cin >> cols;
	int **nums = genRandom(rows, cols);
	printArray(nums, rows, cols);
	std::cout << std::endl;
	nums = zeroOut(nums, rows, cols);
	printArray(nums, rows, cols);
 	return 0;
}