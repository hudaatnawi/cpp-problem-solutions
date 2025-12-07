// problem#25.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int randomNumber(int from, int to) {
    int randNumber = rand()% ( to - from + 1 ) + from;
    return randNumber;
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
void enterArrayElements(int array[100], int& arrayLength) {
    for (int i = 1; i <= arrayLength; i++)
    {
        array[i] = randomNumber(1, 100);

    }

}
void printArrayElements(int array[100],int& arrayLength) {
    cout << "Array Elements: ";
    for (int i = 1; i <= arrayLength ; i++)
    {
        cout<<array[i]<<" ";

    }
    cout << endl;

}
int checkMinNumberInArray(int array[100], int& arrayLength) {
    int minNumber = array[1];
    
    for (int i = 1; i <= arrayLength; i++)
    {
        if (array[i] < minNumber)
            minNumber = array[i];


    }
    return minNumber;

}
int main()
{
    int array[100];
    int arrayLength = readPositiveNumber("Enter array length:");
    srand((unsigned)time(NULL));
    enterArrayElements(array, arrayLength);
    printArrayElements(array, arrayLength);
    cout << "Min Number is: " <<checkMinNumberInArray(array, arrayLength);

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
