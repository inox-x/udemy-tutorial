#include <iostream>
#include <string>

using FString = std::string;

FString getguess() {
	FString userguess = "";
	std::getline(std::cin, userguess);
	return userguess;
}