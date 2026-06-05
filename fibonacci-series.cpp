// fibonacci-series.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int readPositiveNumber(string message) {
    int number;
	do
	{
		cout << message << endl;
		cin >> number;

	} while (number<=0);
	return number;
}
void printFibonacciSeries(int number) {
	int prev1 = 1 , prev2 = 1, fib = 0;
	cout << prev1 << ' ' << prev2<<' ';
	for (int i = 0; i < number - 2; i++)
	{
		fib = prev1 + prev2;
		cout << fib << ' ';
		prev2 = prev1;
		prev1 = fib;
	}
}
int main()
{
	
	printFibonacciSeries(readPositiveNumber("Please enter positive number:"));

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
