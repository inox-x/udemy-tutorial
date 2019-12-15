#include <iostream>
#include <string>

std::string getguess() {
	std::string userguess = "";
	std::getline(std::cin, userguess);
	return userguess;
}