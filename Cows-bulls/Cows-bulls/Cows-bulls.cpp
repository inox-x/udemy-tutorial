// Cows-bulls.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie
#include <iostream>
using namespace std;

constexpr char answ[] = "Okay m8 i'll try my best";
int main(){
	constexpr int WORD_LENGTH = 666;
	cout << "Welcome to bulls and cows\n";
	cout << "Can you guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of?\n";
	cout << answ;
	return 0;
}