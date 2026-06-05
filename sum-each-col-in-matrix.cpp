// sum-each-col-in-matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;
int randomNumbers(int from, int to) {
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;
}
void fillMatrixWithRandomNumbers(int mat[3][3], short rows, short cols) {
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            mat[i][j] = randomNumbers(1, 100);
    }
    }
}
void printMatrix(int mat[3][3], short rows, short cols) {
    cout << "The following is a 3x3 random matrix\n";
    for (short i = 0; i < rows; i++)
    {
        for (short j = 0; j < cols; j++)
        {
            cout << setw(3) << mat[i][j] << ' ';
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
void printEachColSumInTheMatrix(int mat[3][3], short rows, short cols) {
    
    cout << "The following are the sum of each col in the matrix\n";

        for (short j = 0; j < cols; j++)
        {
            cout << "Col " << j + 1 << " Sum = " << colSum(mat, rows, j) << endl;
        }
       
}

int main()
{
    srand((unsigned)time(NULL));
    int mat[3][3];
    fillMatrixWithRandomNumbers(mat, 3, 3);
    printMatrix(mat, 3, 3);
    printEachColSumInTheMatrix(mat, 3, 3);
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
