#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame();
	void reset();
	int getmaxtries() const;
	void playgame();
	int getremainingtries() const;
	int getcurrenttry() const;
	bool isgamewon() const;

private:
	std::string wordtoguess;
	bool isguessedword(std::string) const;
	int mycurrenttry;
	int mymaxtries;
};