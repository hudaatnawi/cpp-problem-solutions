// problem#41.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void fillArray(int arr[100], int& arrLength) {
	arrLength = 6;
	cout << "Fill The Array: ";
	for (int i = 0; i < arrLength; i++)
	{
		cin >> arr[i];
	}
	
}
void printArrayElements(int arr[100], int arrLength) {
	cout << "Array Elements \n";
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";

	}
	cout << endl;
}

bool isPalindrom(int arr[100], int arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] != arr[arrLength - i - 1]) {
			return false;
		}
	}
	return true;
}
int main()
{
	int arr[100], arrLength;
	fillArray(arr, arrLength);
	printArrayElements(arr, arrLength);
	if (isPalindrom(arr, arrLength)) {
		cout << "Yes array is palindrom \n";
	}
	else {
		cout << "NO array is not palindrom \n";
	}
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
