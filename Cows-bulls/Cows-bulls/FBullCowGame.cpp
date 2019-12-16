#include "FBullCowGame.h"
#include <iostream>
#include <string>
#include "GetGuess.h"

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
	mymaxtries = 8;
}

int32 FBullCowGame::getmaxtries() const
{
	return mymaxtries;
}

void FBullCowGame::playgame()
{
	reset();
	int32 WORD_LENGTH = myhiddenword.length();
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of?" << std::endl;


	for (int32 i = 1; i <= getmaxtries(); i++)
	{
		std::cout << "Try " << getcurrenttry() << " . Enter your guess: ";
		FString userguess = getguess();
		FBullCowCount BullCowCount = submitguess(userguess);
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Cows << std::endl;
	}

	return;
}

int32 FBullCowGame::getremainingtries() const
{
	return (mymaxtries - mycurrenttry);
}

int32 FBullCowGame::getcurrenttry() const
{
	return mycurrenttry;
}

bool FBullCowGame::isgamewon() const
{
	return false;
}

FBullCowCount FBullCowGame::submitguess(FString guess)
{
	mycurrenttry = mycurrenttry + 1;
	FBullCowCount BullCowCount;
	
	int32 guesslength = guess.length();
	int32 hiddenwordlength = myhiddenword.length();
	for (int32 i = 0; i < guesslength; i++) {
		bool isinguess = 0;
		for (int32 j = 0; j < hiddenwordlength; j++) {
			if (guess[i] == myhiddenword[j]) {
				isinguess = 1;
			
			break;
			}
		}
		if (isinguess == 1) {
			BullCowCount.Cows++;
		}
		else {
		BullCowCount.Bulls++;
		}
	}
	
	
	return BullCowCount;
}

bool FBullCowGame::isguessedword(FString userword) const
{
	return false;
}