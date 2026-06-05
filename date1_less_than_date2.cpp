// date1_less_than_date2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct stDate
{
    short year;
    short month;
    short day;

};
stDate readFullDate() {
    stDate date;
    cout << "Please enter a day? ";
    cin >> date.day;
    cout << "Please enter a month? ";
    cin >> date.month;
    cout << "Please enter a year? ";
    cin >> date.year;
    cout << endl;
    return date;
}
bool isDate1BeforeDate2(stDate date1, stDate date2) {
    return (date1.year < date2.year) ? true : ((date1.year ==
        date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}
int main()
{
    stDate date1 = readFullDate();
    stDate date2 = readFullDate();
    if (isDate1BeforeDate2(date1,date2))
    {
        cout << "Yes, Date1 is less that Date2\n";

    }
    else
    {
        cout << "No, Date1 is not less that Date2\n";


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
