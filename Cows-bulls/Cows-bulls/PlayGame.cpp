#include <iostream>
#include <string>
#include "PlayGame.h"
#include "GetGuess.h"

void playgame()
{
	constexpr int WORD_LENGTH = 7;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		std::cout << "your guess: " << getguess() << std::endl;
	}
	return;
}
