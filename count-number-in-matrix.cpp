// count-number-in-matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
void printMatrixElements(int matrix[3][3]) {
	cout << "Matrix1 \n";
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++) {
			cout << setw(3) << matrix[i][j] << ' ';
	}
		cout << endl;
	}
}
short countNumberInMatrix(int matrix[3][3], int& number) {
	 short counter = 0;
	cout << "Enter number to count in matrix: ";
	cin >> number;
	for (short i = 0; i < 3; i++)
	{
		for (short j = 0; j < 3; j++) {
			if (number == matrix[i][j])
				counter++;
		}
	}
	return counter;
}
int main()
{
	int matrix[3][3] = { {1,1,1},{3,3,3},{4,4,4} } , number;
	printMatrixElements(matrix);
	cout << "Number " << number << " count in matrix is " << countNumberInMatrix(matrix, number);
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
