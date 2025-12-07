// problem#38.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int randomNumber(int from, int to)
{
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;
}
void fillArrayWithRandomNumber(int arr1[100],int& arr1Length) {
    cout << "Enter the length of the array: ";
    cin >> arr1Length;
    for (int i = 0; i < arr1Length; i++)
    {
        arr1[i] = randomNumber(1, 100);

    }

}
void printArrayElements(int arr1[100], int arr1Length)
{
    for (int i = 0; i < arr1Length; i++)
    {
        cout << arr1[i] << ' ';

    }
    cout << endl;
}
void addArrayElement(int number, int arr[100], int& arr2Length)
{
    arr2Length++;
    arr[arr2Length - 1] = number;

}
void copyOddNumbersToArray2(int arr1[100],int arr2[100],int arr1Length,int& arr2Length) {
    for (int i = 0; i < arr1Length; i++)
    {
       if(arr1[i]%2!=0)
       {
           addArrayElement(arr1[i], arr2, arr2Length);
       }

    }
}

int main()
{
    srand((unsigned)time(NULL));
    int arr1[100], arr1Length,arr2[100],arr2Length=0;
    fillArrayWithRandomNumber(arr1, arr1Length);
    cout << "Array 1 elements: ";
    printArrayElements(arr1, arr1Length);
    copyOddNumbersToArray2(arr1, arr2, arr1Length, arr2Length);
    cout << "Array 2 elements: ";
    printArrayElements(arr2, arr2Length);
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
