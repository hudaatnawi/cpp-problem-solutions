// decrease-date-problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct stDate {
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
    cout << endl << endl;
    return date;

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
stDate decreaseDateByOneDay(stDate date) {
    if (date.day==1)
    {
        if (date.month == 1)
        {
            date.year--;
            date.month = 12;
            date.day = numberOfDaysInAMonth(date.month, date.year);

        }
        else
        {
            date.month --;
            date.day = numberOfDaysInAMonth(date.month, date.year);

        }

    }
    else
    {
        date.day--;
    }
    return date;

}

stDate decreaseDateByXDays(stDate date, short days) {
    for (short i = 1; i <= days; i++)
    {
        date = decreaseDateByOneDay(date);

    }
    return date;
}
stDate decreaseDateByOneWeek(stDate date) {
    for (short i = 1; i <= 7; i++)
    {
        date = decreaseDateByOneDay(date);

    }
    return date;
}
stDate decreaseDateByXWeeks(stDate date,short xWeeks) {
    for (short i = 1; i <= xWeeks; i++)
    {
        date = decreaseDateByOneWeek(date);

    }
    return date;
}
stDate decreaseDateByOneMonth(stDate date) {
    if (date.month==1)
    {
        date.month = 12;
        date.year--;

    }
    else
    {
        date.month--;
    }
    short currentDayInMonth = numberOfDaysInAMonth(date.month, date.year);
    if (date.day>currentDayInMonth)
    {
        date.day = currentDayInMonth;

    }
    return date;
}
stDate decreaseDateByXMonths(stDate date, short xMonths) {
    for (short i = 1; i <= xMonths; i++)
    {
        date = decreaseDateByOneMonth(date);

    }
    return date;
}
stDate decreaseDateByOneYear(stDate date) {
   
    date.year--;

    
    return date;
}
stDate decreaseDateByXYears(stDate date, short xYears) {

    date.year-=xYears;


    return date;
}
stDate decreaseDateByOneDecade(stDate date) {

    date.year -= 10;


    return date;
}
stDate decreaseDateByXDecades(stDate date, short xDecades) {

    date.year -= xDecades*10;


    return date;
}
stDate decreaseDateByOneCentury(stDate date) {

    date.year -= 100;


    return date;
}
stDate decreaseDateByOneMillennium(stDate date) {

    date.year -= 1000;


    return date;
}
int main()
{
    stDate date = readFullDate();
    cout << "Date after: \n\n\n";
    date = decreaseDateByOneDay(date);
    cout << "Subtracting one day is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByXDays(date,10);
    cout << "Subtracting 10 days is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByOneWeek(date);
    cout << "Subtracting one week is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByXWeeks(date,10);
    cout << "Subtracting 10 weeks is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByOneMonth(date);
    cout << "Subtracting one month is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByXMonths(date,5);
    cout << "Subtracting 5 months is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByOneYear(date);
    cout << "Subtracting one year is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByXYears(date,10);
    cout << "Subtracting 10 years is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByOneDecade(date);
    cout << "Subtracting one decade is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByXDecades(date,10);
    cout << "Subtracting 10 decades is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByOneCentury(date);
    cout << "Subtracting century is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = decreaseDateByOneMillennium(date);
    cout << "Subtracting one millennium is: " << date.day << '/' << date.month << '/' << date.year << endl;
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
