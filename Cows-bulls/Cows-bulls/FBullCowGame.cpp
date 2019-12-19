#pragma once
#include "FBullCowGame.h"
#include <iostream>
#include <string>
#include "GetGuess.h"
#include <map>
#define Tmap std::map

using int32 = int;
using FString = std::string;

FBullCowGame::FBullCowGame()
{
	reset();
}

void FBullCowGame::reset()
{
	const FString HIDDEN_WORD = "planet";
	myhiddenword = HIDDEN_WORD;
	
	mycurrenttry = 1;

	Bisgamewon = false;
}

int32 FBullCowGame::getmaxtries() const
{
	Tmap<int32, int32> wordlengthtomaxtries{ { 3,5 }, { 4,6 }, { 5,7 }, { 6,8 }, {7,9} };
	return wordlengthtomaxtries[myhiddenword.length()];
}

void FBullCowGame::playgame()
{
	reset();
	int32 WORD_LENGTH = myhiddenword.length();
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;

	while ( ! isgamewon() && getcurrenttry() <= getmaxtries())
	{
		std::cout << "Try " << getcurrenttry() << " of " << getmaxtries();
		std::cout << ". Enter your guess : ";
		FString userguess = getvalidguess();
		FBullCowCount BullCowCount = submitvalidguess(userguess);
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl << std::endl;
	}
	
	gamesummary();

	return;
}

int32 FBullCowGame::getremainingtries() const
{
	return (getmaxtries() - mycurrenttry);
}

int32 FBullCowGame::getcurrenttry() const
{
	return mycurrenttry;
}

bool FBullCowGame::isgamewon() const
{
	return Bisgamewon;
}

FBullCowCount FBullCowGame::submitvalidguess(FString guess)
{
	mycurrenttry = mycurrenttry + 1;
	FBullCowCount BullCowCount;
	
	int32 guesslength = guess.length();
	int32 wordlength = myhiddenword.length();
	for (int32 i = 0; i < guesslength; i++)
	{
		bool isinguess = 0;
		for (int32 j = 0; j < wordlength; j++) 
		{
			if (guess[i] == myhiddenword[j] && i == j)
			{
				isinguess = 1;
			
			break;
			}
		}
		if (isinguess == 1)
		{
			BullCowCount.Cows++;
		}
		else
		{
		BullCowCount.Bulls++;
		}
	}
	if (BullCowCount.Cows == wordlength)
	{
		Bisgamewon = true;
	}
	else
	{
		Bisgamewon = false;
	}

	
	return BullCowCount;
}

Eguessstatus FBullCowGame::checkguessvalidity(FString guess) const
{
	if (isisogram(guess) == 0)
	{
		return Eguessstatus::Not_isogram;
	}
	else if (islowercase(guess) == 0)
	{
		return Eguessstatus::Not_lowercase;
	}
	else if (myhiddenword.length() != guess.length())
	{
		return Eguessstatus::Wrong_length;
	}
	else
	{
		return Eguessstatus::OK;
	}
}

bool FBullCowGame::isguessedword(FString userword) const
{
	return false;
}

void FBullCowGame::gamesummary()
{
	if (isgamewon() == 1)
	{
		std::cout << "Congratulations! You won!\n";
	}
	else
	{
		std::cout << "You lost, better luck next time!\n";
	}
}

bool FBullCowGame::isisogram(FString guessedword) const
{
	if (guessedword.length() <= 1)
	{
		return true;
	}
	Tmap<char, bool> letterseen;
	for (auto letter : guessedword)
	{
		letter = tolower(letter);

		if (letterseen[letter])
		{
			return false;
		}
		else
		{
			letterseen[letter] = true;
		}
	}

	return true;
}

bool FBullCowGame::islowercase(FString guessedword) const
{
	for (auto letter : guessedword)
	{
		if (islower(letter) == 0)
		{
			return false;
		}
	}
	return true;
}

FString FBullCowGame::getvalidguess()
{
	Eguessstatus status = Eguessstatus::Invalid_status;
	FString userguess = "";
	do
	{
	std::getline(std::cin, userguess);
		
	status = checkguessvalidity(userguess);
	switch (status)
		{
		case Eguessstatus::Wrong_length:
			std::cout << "Please enter a " << myhiddenword.length() << " letter word.\n";
			break;
		case Eguessstatus::Not_isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case Eguessstatus::Not_lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			return userguess;
		}
	std::cout << std::endl;
	} while (status != Eguessstatus::OK);
	return userguess;
}