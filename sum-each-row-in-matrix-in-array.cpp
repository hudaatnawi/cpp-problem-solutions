// sum-each-row-in-matrix-in-array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
int randomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
void fillMatrixWithRandomNumbers(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			arr[i][j] = randomNumber(1, 100);
	}

	}
}
void printMatrixWithRandomNumbers(int arr[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			cout<<setw(3)<<arr[i][j]<<'|';
		}
		cout << '\n';
	}
}
int sumOfRows(int arr[3][3], short numberOfRow, short cols) {
	int sum = 0;
	for (short j = 0; j < cols; j++)
	{
		sum += arr[numberOfRow][j];
	}
	return sum;
}
void storeTheSumValueInArray(int arr1[3], short rows , short cols , int arr[3][3]) {
	for (short i = 0; i < rows; i++)
	{
		arr1[i] = sumOfRows(arr,i,cols);

	}
}
void printSumOfRows(int arr[3][3], short rows, short cols, int arr1[3]) {
	cout << "The following are the sum of each row in the matrix\n";
	for (short i = 0; i < rows; i++)
	{
		cout << "Row " << i + 1 << " Sum = " << arr1[i] << endl;
	}
}
using namespace std;
int main()
{
	srand((unsigned)time(NULL));
	int arr[3][3],arr1[3];
	fillMatrixWithRandomNumbers(arr, 3, 3);
	cout << "The following is a 3x3 random matrix\n";
	printMatrixWithRandomNumbers(arr, 3, 3);
	storeTheSumValueInArray( arr1,3, 3,  arr);
	printSumOfRows(arr, 3, 3,arr1);
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
