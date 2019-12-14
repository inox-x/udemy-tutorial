#include <iostream>
#include <string>

std::string getguess() {
	std::string userguess = "";
	std::cout << "type it: ";
	std::getline(std::cin, userguess);
	return userguess;
}