#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class Eguessstatus
{
	Invalid_status,
	OK,
	Not_isogram,
	Wrong_length,
	Not_lowercase,
};

class FBullCowGame
{
public:
	FBullCowGame();
	void reset();
	int32 getmaxtries() const;
	void playgame();
	int32 getremainingtries() const;
	int32 getcurrenttry() const;
	bool isgamewon() const;
	FBullCowCount submitvalidguess(FString);
	Eguessstatus checkguessvalidity(FString) const;
	FString getvalidguess();

private:
	FString wordtoguess;
	bool isguessedword(FString) const;
	int32 mycurrenttry;
	int32 mymaxtries;
	FString myhiddenword;
	bool Bisgamewon;
};