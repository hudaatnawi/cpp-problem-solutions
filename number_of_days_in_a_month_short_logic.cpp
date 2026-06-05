// number_of_days_in_a_month_short_logic.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
short calculateNumberOfDaysInAMonth(short year , short month) {
    if (month < 1 || month > 12)
    {
        return 0;
    }
    short days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2) ? (isLeapYear(year) ? 29 : 28) : (days[month - 1]);


}
int main()
{
    short year = readAYear();
    short month = readAMonth();
  cout<<"Number of days in month "<<month <<" is "<<  calculateNumberOfDaysInAMonth(year, month);
    
    
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
