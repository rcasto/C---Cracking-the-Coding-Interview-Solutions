#include <iostream>
#include <string>
#include <cctype>

/*
	Implement an algorithm to determine if a string has all unique characters
	-followup: what if you cannot use additional data structures
*/
bool hasUniqueChars(std::string str) {
	char alphabet[26] = { 0 };
	int length = str.size();
	for (int i = 0; i < length; i++) {
		int character = tolower(str[i]) - 97;
		if (alphabet[character]) {
			return false;
		}
		alphabet[character] = 1;
	}
	return true;
}

/*
	This implementation of the same method as above does not need any additional data structures

	Since an integer is 4 bytes therefore made up of 32 bits, 26 of these bits can be used to represent
	the letters of the alphabet, if the bit is set to 1 then the string already contains the letter
*/
bool hasUnique(std::string str) {
	int alphabet = 0, length = str.size();
	for (int i = 0; i < length; i++) {
		int character = tolower(str[i]) - 97;
		if (alphabet >> character & 1) {
			return false;
		}
		alphabet = alphabet | (1 << character);
	}
	return true;
}

int main(int argc, char *argv[]) {
	std::string input;
	std::cout << "Enter a string: ";
	std::cin >> input;
	if (hasUnique(input)) {
		std::cout << input << " - has all unique characters" << std::endl;
	} else {
		std::cout << input << " - does not have all unique characters" << std::endl;
	}
}