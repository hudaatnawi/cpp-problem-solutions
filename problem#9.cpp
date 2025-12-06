// problem#9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int readPositiveNumber(string message) {
	int number;
	do
	{
		cout << message << endl;
		cin >> number;

	} while (number<0);
	return number;
}
int countDigitFrequency(int numberToCheck,int number) {
	int reminder = 0, frequant = 0;
	while (number>0)
	{
		reminder = number % 10;
		number = number / 10;
		if (numberToCheck == reminder)
		{
			frequant++;

		}

	}
	return frequant;

}
void printAllDigitsFrequencey(int number) {
	
	
	for (int i = 0; i <= 9; i++)
	{
		short digitFrequancy = countDigitFrequency(i, number);
		if (digitFrequancy > 0) {
			cout << "Frequatn of " << i << " is " << digitFrequancy << endl;

}
	}


	
}
int main()
{
	printAllDigitsFrequencey(readPositiveNumber("Enter positive number:"));
	
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
