
#include <iostream>
#include <string>
#include "PrintIntro.h"
#include "GetGuess.h"
#include "PlayGame.h"
#include "AskToPlayAgain.h"
#include "FBullCowGame.h"

FBullCowGame BCGame;

int main() {
	printintro();
	do {
		BCGame.playgame();
	} while (asktoplayagain() == true);

	return 0;
}