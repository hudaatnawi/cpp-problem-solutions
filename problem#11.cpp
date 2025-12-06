// problem#11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
int readPositiveNumber(string message)
{
    int number;
	do
	{
		cout << message << endl;
		cin >> number;

	} while (number<0);
	return number;
}
int reversedNumber(int number) {
	int reminder = 0, number2 = 0;
	while (number>0)
	{
		reminder = number % 10;
		number = number / 10;
		number2 = number2 * 10 + reminder;

	}
	return number2;
}
bool isPalindromeNumber(int number) {
	return number == reversedNumber(number);
}
int main()
{
	if (isPalindromeNumber(readPositiveNumber("Please enter a positive number?")))
		cout << "\nYes , it is a Palindrome number.\n";  // If true, print affirmative message.
	else
		cout << "\nNo , it is NOT a Palindrome number.\n"; // Otherwise, print negative message.
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
