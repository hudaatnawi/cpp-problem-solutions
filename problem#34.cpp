// problem#34.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	int randNumber = rand() % (from - to + 1) + from;
	return randNumber;
}
void fillArrayWithRandomNumbers(int arr[100] , int& arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = randomNumber(1, 100);

	}

}
void printArrayElements(int arr[100], int arrLength) {
	cout << "Array 1 elements: \n";
	for (int i = 0; i < arrLength; i++)
	{
		cout<<arr[i]<<' ';

	}
}
int enterANumberToSearchForInArray(int& number) {
	number = readPositiveNumber("\nPlease Enter a Positive Number to search for in array: ");
	return number;
}
bool findTheNumberInsideTheArray(int arr[100], int arrLength, int number, int& i){
	for ( i = 0; i < arrLength; i++)
	{
		if (arr[i] == number)
		{
			return true;
		}
		

	}
	return false;

}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100] , number,i;
	int arrLength = readPositiveNumber("Please enter array length: ");
	fillArrayWithRandomNumbers(arr, arrLength);
	printArrayElements(arr, arrLength);
	cout<<"\nThe number you are looking for is " << enterANumberToSearchForInArray(number);
	if (findTheNumberInsideTheArray(arr, arrLength, number,i)) {
		cout << "\nthe number is found at position" << i << endl;
		cout << "\nthe number found it's order " << i + 1 << endl;
	}
	else { cout << "The number is not found"; }

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
