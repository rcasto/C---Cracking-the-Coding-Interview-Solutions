#include <iostream>

int size(int *arr) {
	int length = 0;
	while (*arr) {
		length++;
		arr++;
	}
	return length;
}

void printArray(int *arr) {
	int length = size(arr);
	for (int i = 0; i < length; i++) {
		std::cout << arr[i];
		if (i != length - 1) {
			std::cout << ", ";
		}
	}
	std::cout << std::endl;
}

int *merge(int *left, int *right) {
	int leftL = size(left), rightL = size(right);
	int *merged = new int[leftL + rightL];
	//Create index into merged
	int index = 0;
	//Merge both lists into merged area
	while (*left && *right) {
		if (*left < *right) {
			merged[index] = *left;
			left++;
		} else {
			merged[index] = *right;
			right++;
		}
		index++;
	}
	//Append rest of other list to merged
	left = *left ? left : right;
	while (*left) {
		merged[index] = *left;
		index++;
		left++;
	}
	return merged;
}

int *mergesort(int arr[]) {
	int length = size(arr);
	if (length <= 1) {
		return arr;
	}
	std::cout << "Length: " << length << std::endl;
	int mid = length / 2;
	int *left = new int[mid];
	int *right = new int[length - mid];
	//Fill up left half
	for (int i = 0; i < mid; i++) {
		left[i] = arr[i];
	}
	//Fill up right half
	for (int i = 0; i < (length - mid); i++) {
		right[i] = arr[i + mid];
	}

	std::cout << "Left:" << std::endl;
	printArray(left);
	std::cout << "Right:" << std::endl;
	printArray(right);

	//Recursively Merge Sort both halves
	left = mergesort(left);
	right = mergesort(right);
	//Merge both halves and return
	int *merged = merge(left, right);
	return merged;
}

int main(int argc, char *argv[]) {
	int nums[] = {5, 3, 5, 6, 5, 6, 6};
	printArray(nums);
	int *sorted = mergesort(nums);
	printArray(sorted);
	return 0;
}