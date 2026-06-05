// validate_date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct stDate
{
    short day;
    short month;
    short year;

};
stDate readFullDate() {
    stDate date; 
    cout << "Please enter a Day? ";
    cin >> date.day;
    cout << "Please enter a Month? ";
    cin >> date.month;
    cout << "Please enter a Year? ";
    cin >> date.year;
    return date;
}
bool isLeapYear(short year) {
    return (year % 4==0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysInMonth(short month , short year) {
    if (month < 1 || month>12)
        return 0;
    short arrDays[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    return (month == 2 ? (isLeapYear(year) ? 29 : 28) : arrDays[month - 1]);

}
bool isValidateDate(stDate date) {
   short day;
  day= numberOfDaysInMonth(date.month,date.year);
  return (date.day == day);
}
int main()
{
    stDate date = readFullDate();
    if (isValidateDate(date))
    {
        cout << "Yes , Date is validate date\n";
    }
    else
    {
        cout << "No , Date is not validate date\n";

    } 
    

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
