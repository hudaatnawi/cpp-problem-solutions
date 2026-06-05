// sum-each-col-in-matrix-in-another-array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
int randomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
void fillMatrixWithRandomNumbers(int mat[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			mat[i][j] = randomNumber(1, 100);
		}
	}
}
void printMatrixWithRandomNumbers(int mat[3][3], short rows, short cols) {
	cout << "The following is matrix with random numbers \n";
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			cout << setw(3) << mat[i][j]<< ' ' ;
		}
		cout << endl;
	}
}
int colSum(int mat[3][3], short rows, short colNumber) {
	int sum = 0;
	for (short i = 0; i < rows; i++)
	{
		sum += mat[i][colNumber];

	}
	return sum;
}
void colSumInArray(int mat[3][3], short rows, short cols, int arr[3]) {
	for (short j = 0; j < cols; j++)
	{
		arr[j] = colSum(mat, rows, j);
	}
}
void printColSumInArray( short cols, int arr[3]) {
	cout << "The following are the col Sum matirx in array \n";
	for (short j = 0; j < cols; j++)
	{
		cout << "Col " << j + 1 << " Sum = " << arr[j] << endl;
	}
}
int main()
{
	int mat[3][3], arr[3];
	fillMatrixWithRandomNumbers(mat, 3, 3);
	printMatrixWithRandomNumbers(mat, 3, 3);
	colSumInArray(mat, 3, 3, arr);
	printColSumInArray(3, arr);
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
