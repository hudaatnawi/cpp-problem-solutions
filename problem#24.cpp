// problem#24.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int randomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
int readPositiveNumber(string message) {
	int number;
	do
	{
		cout << message << endl;
		cin >> number;

	} while (number<0);
	return number;
}
void fillArrayWithRandomElements(int array[100], int& arrayLength)
{
	
	arrayLength = readPositiveNumber("Enter length Of Array:");
	for (int i = 1; i <= arrayLength ; i++)
	{
		array[i] = randomNumber(1, 100);

	}

}
void printArrayElements(int array[100], int& arrayLength) {
	cout << "Elements of array are : ";
	for (int i = 1; i <= arrayLength ; i++)
	{
		cout << array[i] << ' ';

	}
	cout << endl;
}
int checkTheMaxNumberInArray(int array[100], int& arrayLength)
{
	int maxNumber = 0;
	for (int i = 1; i <= arrayLength; i++)
	{
		if (array[i] > maxNumber)
			maxNumber = array[i];
	}
	return maxNumber;

}
int main()
{
	int array[100],arrayLength;
	fillArrayWithRandomElements(array, arrayLength);
	printArrayElements(array, arrayLength);
	cout << "The max number is " << checkTheMaxNumberInArray(array, arrayLength);
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
