// problem#43.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int randomNumber(int from, int to) {
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;
}
void fillArrayWithRandomNumber(int arr[100],int& arrLength)
{
    cout << "Enter array Length: ";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = randomNumber(-100, 100);
    }
}
void printArray(int arr[100], int arrLength) {
    cout << "Array Elements : ";
    for (int i = 0; i < arrLength; i++)
    {
       cout<< arr[i]<<' ';
    }
    cout << endl;
}
short numberOfPositiveNumber(int arr[100], int arrLength) {
    int counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] >= 0)
            counter++;
    }
    return counter;
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100], arrLength;
    fillArrayWithRandomNumber(arr, arrLength);
    printArray(arr, arrLength);
   cout<<"Positive Number count is "<< numberOfPositiveNumber(arr, arrLength);
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
