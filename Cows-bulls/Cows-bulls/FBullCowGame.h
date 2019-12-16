#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();
	void reset();
	int32 getmaxtries() const;
	void playgame();
	int32 getremainingtries() const;
	int32 getcurrenttry() const;
	bool isgamewon() const;
	FBullCowCount submitguess(FString);

private:
	FString wordtoguess;
	bool isguessedword(FString) const;
	int32 mycurrenttry;
	int32 mymaxtries;
	FString myhiddenword;
};