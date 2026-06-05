// check-typical-matrices.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int randomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
void fillMatrixWithRandomNumbers(int matrix[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			matrix[i][j] = randomNumber(1, 10);
		}

	}
}
void printMatrix(int matrix[3][3], short rows, short cols)
{
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			printf("%0*d ", 2, matrix[i][j]);
		}
		cout << endl;
	}
}
bool isMatricesTypical(int matrix1[3][3], int matrix2[3][3], short rows, short cols) {
	int sum = 0;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			if (matrix1[i][j] != matrix2[i][j])
				return false;
		}
	}
	return true;
}

int main()
{
	srand((unsigned)time(NULL));
	int matrix1[3][3], matrix2[3][3];
	fillMatrixWithRandomNumbers(matrix1, 3, 3);
	cout << "Matrix1" << endl;
	printMatrix(matrix1, 3, 3);
	fillMatrixWithRandomNumbers(matrix2, 3, 3);
	cout << "Matrix2" << endl;
	printMatrix(matrix2, 3, 3);
	if (isMatricesTypical(matrix1, matrix2, 3, 3))
		cout << "Matrices are typical\n";
	else 		cout << "Matrices are not typical\n";


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
