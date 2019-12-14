#include <iostream>

void printintro() {
	constexpr int WORD_LENGTH = 7;
	std::cout << "Welcome to bulls and cows" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	return;
}