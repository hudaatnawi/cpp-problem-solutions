// problem32.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
int randomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
void fillArrayWithRandomNumbers(int array[100], int& arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		array[i] = randomNumber(1, 100);

	}
}
void printArrayElements(int array[100], int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}
void reversArrayElements(int array[100], int arrLength , int array2[100]) {
	for (int i = 0; i < arrLength; i++)
	{
		array2[i] = array[arrLength-1-i];
		cout << array2[i] << " ";

	}
}
int main()
{
	int array1[100], array2[100];
	int arrLength = readPositiveNumber("Please enter positive number: ");
	fillArrayWithRandomNumbers(array1, arrLength);
	cout << "Array 1 elements: \n";
	printArrayElements(array1, arrLength);
	cout << "Array 2 elements: \n";
	 reversArrayElements(array1, arrLength, array2);







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
