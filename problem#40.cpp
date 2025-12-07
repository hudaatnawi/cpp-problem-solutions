// problem#40.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
void fillArray(int arr[100], int& arrLength) {
    arrLength = 10;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 50;
    arr[4] = 50;
    arr[5] = 70;
    arr[6] = 70;
    arr[7] = 70;
    arr[8] = 70;
    arr[9] = 90;
}
void printArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";

    }
    cout << endl;
}
void addArrayElements(int arr[100], int& arrLength, int number) {
    arrLength++;
    arr[arrLength - 1] = number;
}
short findNumberPosition(int number, int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == number)
            return i;
    }
    return -1;

}
bool isNumberInArray(int number, int arr[100], int arrLength) {
    return findNumberPosition(number, arr, arrLength)!=-1;
}
void copyDistinctNumbersToArray(int arr[100], int arrLength, int& arr2Length,int arr2[100]) {
    for (int i = 0; i < arrLength; i++)
    {
        if (!isNumberInArray(arr[i],arr2,arr2Length)) {
            addArrayElements(arr2, arr2Length, arr[i]);
        }
    }
}

int main()
{
    int arr[100], arrLength;
    fillArray(arr, arrLength);
    cout << "Array 1 elements: ";
    printArray(arr, arrLength);
    int arr2[100], arr2Length=0;
    copyDistinctNumbersToArray(arr, arrLength, arr2Length, arr2);
    cout << "Array 2 elements: ";
    printArray(arr2, arr2Length);
   
    
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
