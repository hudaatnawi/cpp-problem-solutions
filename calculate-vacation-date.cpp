// calculate-vacation-date.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
short dayOfWeekOrder(int year, int month, int day) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return ((day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7);
}
short dayOfWeekOrder(stDate date) {

    return dayOfWeekOrder(date.year, date.month, date.day);
}
string dayName(short number) {
    string nameOfDay[] = { "Sunday","Monday","Tuesday" ,"Wednesday" ,"Thursday" ,"Friday" ,"Saturday" };

    return  nameOfDay[number];
}
bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysInAMonth(short month, short year) {
    if (month < 1 || month > 12)
    {
        return 0;
    }
    short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return month == 2 ? (isLeapYear(year) ? 29 : 28) : arrDays[month - 1];
}
bool isLastDayInMonth(stDate date) {
    return  (date.day == numberOfDaysInAMonth(date.month, date.year));
}
bool isLastMonthInYear(short month) {
    return month == 12;
}
bool date1BeforeDate2(stDate date, stDate endOfMonth) {
    return date.year < endOfMonth.year ? true : ((date.year == endOfMonth.year) ? (date.month < endOfMonth.month ? true : (date.month == endOfMonth.month) ? date.day < endOfMonth.day : false) : false);
}
stDate increaseDateByOneDay(stDate date) {
    if (isLastDayInMonth(date))
    {
        if (isLastMonthInYear(date.month)) {
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
bool isWeedEnd(stDate date) {
    short currentDay = dayOfWeekOrder(date);
    return (currentDay == 5 || currentDay == 6);
}
bool isBusinessDay(stDate date) {
    
    return !isWeedEnd(date);
}

short calculateActucalVacationDays(stDate from, stDate to) {
    short diff = 0;
    while (date1BeforeDate2(from, to)) {
        if (isBusinessDay(from))
            diff++;
        from = increaseDateByOneDay(from);

        
    }
    return diff;
}
int main()
{
    stDate from = readFullDate();
    stDate to = readFullDate();
    cout << "\n\nVacation from: " << dayName(dayOfWeekOrder(from)) << " , " << from.day << '/' << from.month << '/' << from.year << endl;
    cout << "\n\nVacation to: " << dayName(dayOfWeekOrder(to)) << " , " << to.day << '/' << to.month << '/' << to.year << endl<<endl;
    cout << "Actucal Vacation Days is: " << calculateActucalVacationDays(from, to);

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
