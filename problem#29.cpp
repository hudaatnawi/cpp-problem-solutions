// problem#29.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enPrimeNotPrime
{
	Prime = 1, NotPrime = 2

};

int readPositiveNumber(string message)
{
	int number=0;
	do
	{
		cout << message << endl;
		cin >> number;
	} while (number < 0);
	return number;
}

enPrimeNotPrime checkIfPrimeNumber(int number) {
	for (int i = 2; i <= number / 2; i++)
	{
		if (number % i == 0)
		{
			return NotPrime;
		}
	}
	return Prime;
}


int randomNumber(int from , int to)
{
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}

void fillArrayWithRandomNumbers(int arr[100],int& arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = randomNumber(1, 100);
	}
}

void printArrayElements(int arr[100], int arrLength) {
	cout << "Array 1 elements: \n";
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i]<<' ';
	}
	cout << endl;
}
void isTheElementPrime(int arr[100], int arrLength) {
	cout << "Prime number in array2 \n";
	for (int i = 0; i < arrLength; i++)
	{
		if (checkIfPrimeNumber(arr[i]) == Prime)
			cout << arr[i] << ' ';

	}
	cout << endl;
}

int main()
{
	int arr[100], arrLength= readPositiveNumber("Please Enter Positvie Number:");
	fillArrayWithRandomNumbers(arr, arrLength);
	printArrayElements(arr, arrLength);
	isTheElementPrime(arr, arrLength);


   
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
