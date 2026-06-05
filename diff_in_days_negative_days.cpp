// diff_in_days_negative_days.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    cout << endl;
    return date;
}
bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 !=0) || (year % 400 == 0);
}
short numberOfDaysInMonth(short month , short year) {
    if (month < 1 || month > 12)
    {
        return 0;

    }
    short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2 ? (isLeapYear(year) ? 29 : 28) : arrDays[month - 1]);
}
bool lastDayInMonth(stDate date) {
    return (date.day == numberOfDaysInMonth(date.month, date.year));
}
bool lastMonthInYear(short month) {
    return (month == 12);
}
stDate increaseDateByOneDay(stDate date) {
    if (lastDayInMonth(date))
    {
        if (lastMonthInYear(date.month))
        {
            date.year++;
            date.month = 1; 
            date.day = 1;

        }
        else
        {
            date.month++;
            date.day = 1;
        }
    }
    else
    {
        date.day++;
    }
    return date;
}
bool date1BeforeDate2(stDate date1, stDate date2) {
    return (date1.year < date2.year) ? true : ((date1.year == date2.year)?date1.month<date2.month?true:(date1.month==date2.month?date1.day<date2.day:false):false);
}
bool date2BeforeDate1(stDate date1, stDate date2) {
    return (date2.year < date1.year) ? true : ((date1.year == date2.year) ? date2.month < date1.month ? true : (date1.month == date2.month ? date2.day < date1.day : false) : false);
}
void swapDates(stDate& date1, stDate& date2) {
    stDate temp;
    temp.day = date1.day;
    temp.month = date1.month;
    temp.year = date1.year;

    date1.day = date2.day;
    date1.month = date2.month;
    date1.year = date2.year;

    date2.day = temp.day;
        date2.month = temp.month;
        date2.year = temp.year;


}
int getDiffInDays(stDate date1 , stDate date2, bool includingEndDay = false) {

    int days = 0;
    short swapFlagValue = 1;
    if (!date1BeforeDate2(date1, date2))
    {
       swapDates(date1, date2);
        swapFlagValue = -1;

    }
    while (date1BeforeDate2(date1, date2)) {
        days++;
        date1 = increaseDateByOneDay(date1);
    }
    return includingEndDay == true ? ++days * swapFlagValue : days * swapFlagValue;
}

int main()
{
    stDate date1 = readFullDate();
    stDate date2 = readFullDate();
   
        cout << "\nDiffrence is: "
            << getDiffInDays(date1, date2) << " Day(s).";
        cout << "\nDiffrence (Including End Day) is: "
            << getDiffInDays(date1, date2, true) << " Day(s).";

    
    
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
