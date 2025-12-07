// problem#21.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>   // Include iostream for input/output operations.
#include <string>     // Include string for using std::string.
#include <cstdlib>    // Include cstdlib for rand() and srand() functions.
#include <ctime>      // Include ctime for time() to seed the random generator.
using namespace std;
enum enRandoms
{SmallLetter=1,CapitalLetter=2,digits=3, SpecialCharachter =4

};
int readPositiveNumber(string message) {
	int number;
	do
	{
		cout << message << endl;
		cin >> number;

	} while (number<0);
	return number;
}
int randomNumbers(int from , int to)
{
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
char chooseTypeOfRandomWords(enRandoms rand)
{
	switch (rand)
	{
	case SmallLetter:
		return char(randomNumbers(97, 122));
	case CapitalLetter:
		return char(randomNumbers(65, 90));
	case SpecialCharachter:
		return char(randomNumbers(33, 47));
	case digits:
		return char(randomNumbers(48, 57));
	}
	return '0';
}
string generateRandomKeys(int lengthOfKey, int lengthOfWord) {
	string word;
	for (int i = 1; i <= lengthOfKey; i++)
	{
		for (int j = 1; j <= lengthOfWord; j++) {
			word += chooseTypeOfRandomWords(CapitalLetter);

	}
		 
		word += '-';
	}
	return word;
	
}
void printGeneratedKeys(int keys)
{
	for (int i = 1; i <= keys; i++)
	{
		cout << "Key[" << i << "]"<<" : " << generateRandomKeys(4, 10) << endl;

	}
}
int main()
{
	srand((unsigned)time(NULL));
	 printGeneratedKeys(readPositiveNumber("Enter Positive Number:"));
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
