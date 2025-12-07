// problem#36.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int addNumber() {
    int number;
    cout << "Plese Enter A Number? ";
    cin >> number;
    return number;
}
void addArrayElement(int number,int arr[100], int& arrLength) {
    arrLength++;
    arr[arrLength - 1] = number;

}
void inputUserNumbersInArray(int number, int arr[100], int& arrLength) {
    bool addMore = 1;
    do
    {
        addArrayElement(addNumber(), arr, arrLength);
        cout << "Do You Want to Add more numbers? Yes[1],NO[0]?";
        cin >> addMore;

    } while (addMore);
}
void printArray(int arr[100], int arrLength) {
    for (int i = 0; i < arrLength; i++)
    {
        cout << arr[i] << ' ';

    }
}
int main()
{
    int arr[100], arrLength = 0,number=0;
    inputUserNumbersInArray(number, arr, arrLength);
    cout << "Array Length " << arrLength << endl;
    cout << "Array Elements ";
    printArray(arr, arrLength);
   

    
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
