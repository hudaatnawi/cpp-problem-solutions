// leap_year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int readYear() {
    int year;
    cout << "Enter the year: ";
    cin >> year;
    return year;
}
bool isLeapYear(int number) {
    return(number % 4 == 0 && number % 100 != 0) || (number % 400 == 0);
}
int main()
{
    int Year = readYear();
    if (isLeapYear(Year)) {
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    }
    else
        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";
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
