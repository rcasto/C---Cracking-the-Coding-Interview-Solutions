#include <iostream>

/*
	Implement a method to reverse a null terminated string
*/

void reverse(char *str) {
	int length = 0;
	char *temp = str, save;
	while (*temp) {
		length++;
		temp++;
	}
	for (int i = 0; i < length / 2; i++) {
		save = str[i];
		str[i] = str[length - i - 1];
		str[length - i - 1] = save;
	}
}

char *stringToCharArray(std::string str) {
	int length = str.size();
	char *charArray = new char[length + 1];
	for (int i = 0; i < length; i++) {
		charArray[i] = str[i];
	}
	charArray[length + 1] = '\0';
	return charArray;
}

int main(int argc, char *argv[]) {
	std::string input;
	std::cout << "Enter a string: ";
	std::cin >> input;
	char *charArray = stringToCharArray(input);
	reverse(charArray);
	std::cout << "Reversed: " << charArray << std::endl;
	return 0;
}