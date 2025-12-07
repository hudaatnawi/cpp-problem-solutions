// problem#28.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int randNumber(int from, int to) {
    int randomNumber = rand() % (to - from + 1) + from;
    return randomNumber;
}
int readPositiveNumber(string message) {
    int number;
    do
    {
        cout << message << endl;
        cin >> number;

    } while (number < 0);
    return number;
}
void fillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;

    for (int i = 0; i < arrLength; i++)
        arr[i] = randNumber(1, 100);
}
void printElementsOfArrayOne(int arr[100], int arrLength)
{
    cout << "Array one elements  " << endl;
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void copyElementsOfArrayOneToAnotherArray(int arr[100], int arrLength, int array2[100])
{
   
    for (int i = 0; i < arrLength; i++)
    {
        array2[i] = arr[i];
    }

}

int main()
{
    int arr1[100], arr2[100], arrLength;
    fillArrayWithRandomNumbers(arr1, arrLength);
    printElementsOfArrayOne(arr1, arrLength);
    copyElementsOfArrayOneToAnotherArray(arr1, arrLength, arr2);
    printElementsOfArrayOne(arr2, arrLength);

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
