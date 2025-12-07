// problem#22.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
void enterElementsOfArray(int& arrayLength,int array[100])
{
    cout << "Enter the elements of an array: \n";
    for (int i = 1; i <= arrayLength;i++) {
        cout << "Element " << '[' << i << ']' << ':';
        cin >> array[i];
} }
void printElementsOfArray(int arrayLength,int array[100]) {
    cout << "The elements in the array are \n";
    for (int i = 1; i <= arrayLength; i++)
    {
        cout << array[i] << ' ';

    }
    cout << endl;
}
int  printNumberToCheck(int number, int array[100], int arrayLength)
{
    int counter = 0;
    for (int i = 1; i <= arrayLength; i++)
    {
        if (number == array[i])
            counter++;
    }
    return counter;
}
int main()
{
    int arrayLength = readPositiveNumber("Enter the length of an array:");
    int array[100];
    enterElementsOfArray(arrayLength, array);
    printElementsOfArray(arrayLength, array);
   cout<< printNumberToCheck(readPositiveNumber("Enter number to check:"), array, arrayLength);
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
