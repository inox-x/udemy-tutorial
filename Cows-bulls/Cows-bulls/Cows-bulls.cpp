// Cows-bulls.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie
#include <iostream>
#include <string>
using namespace std;

char jedenZnak = 'a';
char wieleZnakwow[] = "abcd";
int jednaLiczba = 1;
int wieleLiczb[] = {1, 2, 3};
bool jedenBool = false;
bool wieleBoolow[] = { false,true,false };
string jedenString = "";
string wieleStringow[] = { "asdadas","a","asjdaskjdna" };

constexpr char answ[] = "Okay m8 i'll try my best";

//typ nazwaFunkcji(typ zmienna1,typ zmienna2) {
// kod..
//}

void printintro() {
	constexpr int WORD_LENGTH = 7;
	cout << "Welcome to bulls and cows" << endl;
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?" << endl;
	return;
}

string getguess() {
	string userguess = "";
	cout << "type it: ";
	getline(cin, userguess);
	return userguess;
}

int main() {
	printintro();
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		cout << "your guess: " << getguess() << endl;
	}
	return 0;
}