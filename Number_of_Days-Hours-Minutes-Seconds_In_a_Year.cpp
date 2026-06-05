// Number_of_Days-Hours-Minutes-Seconds_In_a_Year.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int readAYear() {
    int year;
    cout << "Enter a year: ";
    cin >> year;
    return year;
}
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

short numberOfDaysInAYear(short year) {
    return isLeapYear(year) ? 366 : 365;
}

int numberOfHoursInAYear(short year) {
    return numberOfDaysInAYear(year) * 24;
}

int numberOfMinutesInAYear(short year) {
    return numberOfHoursInAYear(year) * 60;
}


int numberOfSecondsInAYear(short year) {
    return numberOfMinutesInAYear(year) * 60;
}

int main()
{
    int year = readAYear();
    cout << "\nNumber of Days in Year [" << year << "] is "
        << numberOfDaysInAYear(year);

    cout << "\nNumber of Hours in Year [" << year << "] is "
        << numberOfHoursInAYear(year);

    cout << "\nNumber of Minutes in Year [" << year << "] is "
        << numberOfMinutesInAYear(year);

    cout << "\nNumber of Seconds in Year [" << year << "] is "
        << numberOfSecondsInAYear(year);
    
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
