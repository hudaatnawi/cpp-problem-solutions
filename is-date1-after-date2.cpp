// is-date1-after-date2.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    cout << "Please enter a day? ";
    cin >> date.day;
    cout << "Please enter a month? ";
    cin >> date.month;
    cout << "Please enter a year? ";
    cin >> date.year;
    cout << endl << endl;
    return date;
}
bool isDate1BeforeDate2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true : ((date1.year ==
        date2.year) ? (date1.month < date2.month ? true : (date1.month ==
            date2.month ? date1.day < date2.day : false)) : false);
}
bool isDate1EqualToDate2(stDate date1, stDate date2)
{
    return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) :false;
}
bool isDate1AfterDate2(stDate date1, stDate date2) {
    return (!isDate1BeforeDate2(date1,date2)&& !isDate1EqualToDate2(date1, date2));
}
int main()
{
    cout << "Enter Date1: \n";
    stDate date1 = readFullDate();
    cout << "Enter Date2: \n";
    stDate date2 = readFullDate();
    if (isDate1AfterDate2(date1,date2))
    {
        cout << "Yes , Date1 After Date2 \n";
    }
    else
    {
        cout << "No , Date1 is Not After Date2 \n";

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
