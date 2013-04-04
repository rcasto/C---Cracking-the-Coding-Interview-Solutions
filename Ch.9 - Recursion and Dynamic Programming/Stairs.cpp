#include <iostream>
#include <cstring>

/*
	Chapter 9 - Problem 1
	A child is running up a staircase that has n steps.  The child can run 1 step, 2 steps, or 3 steps at a time.
	How many ways can the child run up the stairs?
*/
int numStairClimbs(int n, int cache[]) {
	if (n < 0) {
		return 0;
	}
	if (n == 0) {
		return 1;
	}
	if (cache[n - 1] > -1) {
		return cache[n - 1];
	}
	cache[n - 1] = numStairClimbs(n - 1, cache) +
			   	   numStairClimbs(n - 2, cache) +
			       numStairClimbs(n - 3, cache);
	return cache[n - 1];
}

int numStairClimbs(int n) {
	int cache[n];
	memset(cache, -1, sizeof(cache));
	return numStairClimbs(n, cache);
}

int main(int argc, char *argv[]) {
	int n;
	std::cout << "Enter number of stairs: ";
	std::cin >> n;
	std::cout << "Number of ways to climb stairs: " << numStairClimbs(n) << std::endl;
	return 0;
}