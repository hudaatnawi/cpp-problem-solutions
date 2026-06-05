// traspose-matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void fillMatrixWithOrderedNumber(int mat[3][3], short rows, short cols) {
	short counter = 0;
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			counter++;
			mat[i][j] = counter;
	}

	}
}
void printMatrixWithOrderedNumber(int mat[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++) {
		cout<<	mat[i][j] <<' ';
		}
		cout << endl;
	}
}
void transposeMatrix(int mat[3][3], int mat2[3][3], short rows, short cols) {
	for (short i = 0; i < rows; i++)
	{
		for (short j = 0; j < cols; j++) {
			mat2[i][j] = mat[j][i];
		}
	}
}
int main()
{
	int mat[3][3] , mat2[3][3];
	fillMatrixWithOrderedNumber(mat, 3, 3);
	cout << "The following is 3x3 ordered matrix \n";
	printMatrixWithOrderedNumber(mat, 3, 3);
	transposeMatrix(mat, mat2, 3, 3);
	cout << "The following is 3x3 transpose matrix \n";
	printMatrixWithOrderedNumber(mat2, 3, 3);

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
