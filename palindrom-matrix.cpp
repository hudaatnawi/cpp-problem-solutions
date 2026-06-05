// palindrom-matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
void printMatrixElements(int matrix[3][3]) {
	cout << "Matrix 1 \n";
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			cout << setw(3) << matrix[i][j] << ' ';
		}
		cout << endl;
	}
}
bool isMatrixPalindrom(int matrix[3][3]) {
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			if (matrix[i][j] != matrix[i][3-1- j])
				return false;
		}
	}
	return true;
}
int main()
{
	int matrix[3][3] = { {1,2,1},{5,5,5},{7,3,8} };
	printMatrixElements(matrix);
	if (isMatrixPalindrom(matrix)) {
		cout << "Matrix is Palindrom \n";
	}
	else cout << "Matrix is not Palindrom \n";
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
