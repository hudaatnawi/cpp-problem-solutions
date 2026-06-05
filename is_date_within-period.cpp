// is_date_within-period.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct stDate
{
    short day;
    short month;
    short year;
};
struct stPeriod
{
    stDate startDate, endDate;
};
enum enDateCompare { Before = -1, Equal = 0, After = 1 };
stDate readFullDate() {
    stDate date;
    cout << "Please enter a day? ";
    cin >> date.day;
    cout << "Please etner a month? ";
    cin >> date.month;
    cout << "Please enter a year? ";
    cin >> date.year;
    cout << endl << endl;
    return date;
}
stPeriod readPeriod() {
    stPeriod period;
    cout << "Enter Start Date: \n\n";
    period.startDate = readFullDate();
    cout << "Enter End Date: \n\n";
    period.endDate = readFullDate();
    cout << endl << endl;
    return period;
}
bool isDate1BeforeDate2(stDate date1, stDate date2)
{
    return (date1.year < date2.year) ? true : ((date1.year ==
        date2.year) ? (date1.month < date2.month ? true : (date1.month ==
            date2.month ? date1.day < date2.day : false)) : false);
}
bool isDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.year == Date2.year) ? ((Date1.month ==
        Date2.month) ? ((Date1.day == Date2.day) ? true : false) : false)
        : false;
}
bool isDate1AfterDate2(stDate date1, stDate date2)
{
    return (!isDate1BeforeDate2(date1, date2) &&
        !isDate1EqualDate2(date1, date2));
}
enDateCompare compareDates(stDate date1 ,stDate date2) {
    if (isDate1BeforeDate2(date1, date2))
        return Before;
    if (isDate1AfterDate2(date1, date2))
        return After;
    return Equal;
}
bool isDateWithinPeriod(stPeriod period, stDate date) {
    if (!(compareDates(date, period.startDate) == Before || compareDates(date, period.endDate) == After))
        return true;
    return false;
}
int main()
{
    cout << "Enter Period: \n";
    stPeriod period = readPeriod();
    stDate date = readFullDate();
    if (isDateWithinPeriod(period,date))
    {
        cout << "Yes , Date within period\n";
    }
    else
    {
        cout << "No , Date is not within period\n";

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
