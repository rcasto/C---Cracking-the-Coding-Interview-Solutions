#include <iostream>
#include <vector>


std::vector<std::string> stringToWordArray(std::string str) {
	std::vector<std::string> words;
	std::string word = "";
	int length = str.size();
	for (int i = 0; i < length; i++) {
		if (str[i] == ' ') {
			words.push_back(word);
			word = "";
		} else {
			word += str[i];
		}
	}
	words.push_back(word);
	return words;
}

std::vector<std::string> reverseWordArray(std::vector<std::string> words) {
	std::vector<std::string> reverseWords;
	int size = words.size();
	for (int i = size - 1; i >= 0; i--) {
		reverseWords.push_back(words[i]);
	}
	return reverseWords;
}

std::string wordArrayToString(std::vector<std::string> words) {
	std::string str = "";
	int numWords = words.size();
	for (int i = 0; i < numWords; i++) {
		str += words[i];
		if (i != numWords - 1) {
			str += " ";
		}
	}
	return str;
}

int main(int argc, char *argv[]) {
	char input[256];
	std::cout << "Enter a string: ";
	std::cin.getline(input, 256);
	std::cout << wordArrayToString(stringToWordArray(input)) << std::endl;
	std::cout << wordArrayToString(reverseWordArray(stringToWordArray(input))) << std::endl;
	return 0;
}