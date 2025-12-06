// problem#20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>     
#include <cstdlib>    
#include <ctime>
using namespace std;
int randomNumber(int from, int to) {
	int random = rand() % (to - from + 1) + from;
	return random;
}
enum enRandom
{smallLetter = 1 , capitalLetter = 2 , specialCharachter = 3 , number = 4

};
char printRandomCharachter(enRandom rand) {
	switch (rand)
	{
	case smallLetter:
		return char(randomNumber(97, 122));
	case capitalLetter:
		return char(randomNumber(65, 90));
	case specialCharachter:
		return char(randomNumber(33, 47));
	case number:
		return char(randomNumber(48, 57));;
		return '\0';
	}
}


int main()
{
	srand((unsigned)time(NULL));
	cout << printRandomCharachter(smallLetter) << endl;
	cout << printRandomCharachter(capitalLetter)<<endl;
	cout << printRandomCharachter(specialCharachter) << endl;
	cout << printRandomCharachter(number) << endl;
	
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
