#include <iostream>
#include <string>

using FString = std::string;

bool asktoplayagain()
{
	std::cout << "Do you want to play again? ";
	FString response = "";
	std::getline(std::cin, response);

	bool playagain = (response[0] == 'Y' || response[0] == 'y');
	std::cout << "First char: ";
	if (playagain) {
		std::cout << "True";
	}
	else {
		std::cout << "False";
	}
	std::cout << std::endl;

	return playagain;
}
