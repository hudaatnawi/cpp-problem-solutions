// Number_of_Days-Hours-Minutes-Seconds_In_a_Month.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

short readAYear() {
    short year;
    cout << "Please enter a year to check? ";
    cin >> year;
    return year;
}

short readAMonth() {
    short month;
    cout << "Please enter a month to check? ";
    cin >> month;
    return month;
}
bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}


int numberOfDaysInAMonth(short year , short month) {
    if (month<1||month>12)
    {
        return 0;
    }
    if (month == 2)
    {
        return isLeapYear ? 29 : 28;

    }
    int arr31Days[7] = { 1,3,5,7,8,10,12 };
    for (int  i = 1; i <=7 ; i++)
    {
        if (arr31Days[i-1] == month) {
            return 31;
    }

    }
    return 30;
}

int numberOfHoursInAMonth(short year, short month) {
    return numberOfDaysInAMonth(year, month)*24;

}

int numberOfMinutesInAMonth(short year, short month) {
    return numberOfHoursInAMonth(year, month) * 60;

}

int numberOfSecondsInAMonth(short year, short month) {
    return numberOfMinutesInAMonth(year, month) * 60;

}
int main()
{
    short year = readAYear();
    short month = readAMonth();
   cout<<"Number of Days in Month ["<<month<<"] is "<< numberOfDaysInAMonth(year, month)<<endl;
   cout << "Number of Hours in Month [" << month << "] is " << numberOfHoursInAMonth(year, month) << endl;
   cout << "Number of Minutes in Month [" << month << "] is " << numberOfMinutesInAMonth(year, month) << endl;
   cout << "Number of Seconds in Month [" << month << "] is " << numberOfSecondsInAMonth(year, month) << endl;


     
    
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
