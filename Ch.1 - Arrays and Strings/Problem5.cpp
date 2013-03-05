#include <iostream>
#include <sstream>

/*
	Implement a string compression method
	example:
		input: "aaccbbbb"
		output: "a2c2b4"
	Note: if the compressed string is longer than the original string return the original string
*/
std::string compression(std::string str) {
	int length = str.length();
	if (length < 1) {
		return "";
	}
	std::ostringstream ss;
	char currentChar = str[0];
	int freq = 1;
	for (int i = 1; i < length; i++) {
		if (str[i] == currentChar) {
			freq++;
		} else {
			ss << currentChar;
			ss << freq;
			currentChar = str[i];
			freq = 1;
		}
	}
	ss << currentChar;
	ss << freq;
	if (ss.str().length() > length) {
		return str;
	}
	return ss.str();
}

int main(int argc, char *argv[]) {
	std::string input;
	std::cout << "Enter a string: ";
	std::cin >> input;
	std::cout << "Compressed: " << compression(input) << std::endl;
	return 0;
}