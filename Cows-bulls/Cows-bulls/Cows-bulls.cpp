
#include <iostream>
#include <string>
#include "PrintIntro.h"
#include "GetGuess.h"

int main() {
	printintro();
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		std::cout << "your guess: " << getguess() << std::endl;
	}
	return 0;
}