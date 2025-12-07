// problem#37.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int generateRandomNumber(int from, int to) {
    int randNumber = rand() % (to - from + 1) + from;
    return randNumber;
}
int readPositiveNumber(string message) {
    int number;
    do
    {
        cout << message << endl;
        cin >> number;

    } while (number<1);
    return number;
}
void fillArrayWithRandomNumber(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = generateRandomNumber(1, 100);

    }
}
void printArrayElements(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << ' ';

    }
}
void addArrayElements(int number,int arr[100], int& arr2Length) {
    
    arr2Length++;
    arr[arr2Length - 1]=number ;
}
void copyArrayUsingAddArrayElement(int arr[100],int arr2[100],int arrLength, int& arr2Length) {
    for (int i = 0; i < arrLength; i++)
    {
        addArrayElements(arr[i],arr2, arr2Length);

    }
}
int main()
{
    srand((unsigned)time(NULL));
    int arr[100],arrLength= readPositiveNumber("Please Enter A number greater than 0"), arr2[100];
    int arr2Length=0;
    fillArrayWithRandomNumber(arr, arrLength);
    cout << "Array 1 elements: ";
    printArrayElements(arr, arrLength);
    cout << endl;
    copyArrayUsingAddArrayElement(arr, arr2, arrLength, arr2Length);
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
