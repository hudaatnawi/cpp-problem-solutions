// number-exist-in-matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
void printMatrixElements(int matrix[3][3]) {
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			cout << setw(3) << matrix[i][j] << ' ';
		}
		cout << endl;

	}
}
void findNumberInMatrix(int matrix1[3][3], int matrix2[3][3]) {
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++)
		{
			if (matrix2[i][j] == matrix1[i][j])
			{
				cout << matrix1[i][j] << ' ';
			}
		}

	}
	
}

int main()
{
	int matrix1[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int matrix2[3][3] = { {10,2,30},{40,5,60},{70,8,90} };
	cout << "Matrix 1: \n";
	printMatrixElements(matrix1);
	cout << "Matrix 2: \n";
	printMatrixElements(matrix2);
	cout << "Intersected numbers are: \n";
	findNumberInMatrix(matrix1, matrix2);

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
