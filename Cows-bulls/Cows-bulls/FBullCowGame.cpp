#include "FBullCowGame.h"
#include <iostream>
#include <string>
#include "GetGuess.h"


FBullCowGame::FBullCowGame()
{
	reset();
}

void FBullCowGame::reset()
{
	mycurrenttry = 1;
	mymaxtries = 8;
}

int FBullCowGame::getmaxtries() const
{
	return mymaxtries;
}

void FBullCowGame::playgame()
{
	reset();
	constexpr int WORD_LENGTH = 7;
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;


	for (mycurrenttry = 1; mycurrenttry <= getmaxtries(); mycurrenttry++)
	{
		std::cout << "Try " << getcurrenttry() << " . Enter your guess: ";
		std::string userguess = getguess();
		std::cout << "Your guess was " << userguess << std::endl;
	}
	return;
}

int FBullCowGame::getremainingtries() const
{
	return (mymaxtries - mycurrenttry);
}

int FBullCowGame::getcurrenttry() const
{
	return mycurrenttry;
}

bool FBullCowGame::isgamewon() const
{
	return false;
}

bool FBullCowGame::isguessedword(std::string userword) const
{
	return false;
}