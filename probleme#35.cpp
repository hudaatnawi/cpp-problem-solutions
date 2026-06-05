// probleme#35.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
int randomNumbers(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
void fillArrayWithRandomNumbers(int arr[100], int& arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = randomNumbers(1, 100);

	}
}
void printArrayElements(int arr[100], int arrLength) {
	cout << "Array 1 elements: \n";
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << ' ';

	}
	cout << endl;
}
int enterNumberToSearchFor(int& number) {
	number = readPositiveNumber("\n Please enter number to search for: ");
	return number;
}
short findTheNumberInArray(int arr[100], int arrLength, int number) {
	for (int i = 0; i < arrLength; i++)
	{if(arr[i]==number)
	{
		return i;
	}

	}
	return -1;
}
bool isNumberInArray(int arr[100], int arrLength, int number) {
	return findTheNumberInArray(arr, arrLength, number) != -1;
}
int main()
{
	// Seed the random number generator with the current time.
  // This ensures different random sequences on each run.
	srand((unsigned)time(NULL));

	int arr[100];   // Declare an array to hold up to 100 integers.
	int arrLength;  // Variable to store the number of elements in the array.
	arrLength = readPositiveNumber("Please enter the number of an array elements:");
	// Fill the array with random numbers.
	fillArrayWithRandomNumbers(arr, arrLength);

	// Print the array's elements.
	printArrayElements(arr, arrLength);
	int number;
	cout << "\nNumber you are looking for is: " << enterNumberToSearchFor(number) << endl;

	// Check if the number is in the array and output the result.
	if (!isNumberInArray( arr, arrLength, number))
		cout << "No, The number is not found :-(\n";
	else
		cout << "Yes it is found :-)\n";
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
