// count-small-capital-letters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
string readString() {
	string words;
	cout << "Please enter your string\n";
	getline(cin, words);
	return words;
}
int countCapitalSmallLetters(string words) {
	int countUpper = 0;
	for (int i = 0; i < words.length(); i++)
	{
		words[i] = isupper(words[i]) ? countUpper++ : 0;
	}
	return countUpper;
}
int main()
{
	string word = readString();
	int upperNumber = countCapitalSmallLetters(word);
	cout << "String length = " << word.length() << endl;
	cout << "Capital letters count = " << upperNumber << endl;
	cout << "Small letters count = " << word.length() - upperNumber << endl;
   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
