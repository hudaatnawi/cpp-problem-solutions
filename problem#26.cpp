// problem#26.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int randNumber(int from , int to) {
    int randomNumber = rand() % (to - from + 1) + from;
    return randomNumber;
}
int readPositiveNumber(string message) {
    int number;
    do
    {
        cout << message << endl;
        cin >> number;

    } while (number<0);
    return number;
}
void fillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength; 

    for (int i = 0; i < arrLength; i++)
        arr[i] = randNumber(1, 100);
}
void printArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";  
}
int printSumOfArrayNumber(int arr[100], int arrLength) {
    int sum = 0;
    for (int i = 0; i < arrLength; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int arr[100] , arrLength;
    fillArrayWithRandomNumbers(arr, arrLength);
    cout << "Array elements: ";
    printArray(arr, arrLength);
    cout << "Sum of all numbers are: " << printSumOfArrayNumber(arr, arrLength);
   
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
