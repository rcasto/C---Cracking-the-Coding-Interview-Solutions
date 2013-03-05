#include <iostream>
#include <string>
#include <cctype>

/*
	Given two strings determine whether one is a permutation of another

	need to have same character makeup and same frequency of characters (same character count)
*/
bool permutation(std::string s1, std::string s2) {
	int length1 = s1.size(), length2 = s2.size();
	if (length1 != length2) {
		return false;
	}
	int alphabet[26] = { 0 }, character;
	for (int i = 0; i < length1; i++) {
		character = tolower(s1[i]) - 97;
		alphabet[character]++;
	}
	for (int i = 0; i < length2; i++) {
		character = tolower(s2[i]) - 97;
		if (alphabet[character] == 0) {
			return false;
		} else {
			alphabet[character]--;
		}
	}
	return true;
}

int main(int argc, char *argv[]) {
	std::string input1, input2;
	std::cout << "Enter a string 1: ";
	std::cin >> input1;
	std::cout << "Enter a string 2: ";
	std::cin >> input2;
	if (permutation(input1, input2)) {
		std::cout << "String 2 is a permutation of String 1" << std::endl;
	} else {
		std::cout << "String 2 is not a permutation of String 1" << std::endl;
	}
	return 0;
}