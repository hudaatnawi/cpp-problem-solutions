// increase_date_problems.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
short numberOfDaysInAMonth(short month ,short year) {
    if (month<1 || month > 12)
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

stDate increaseDateByXDays( stDate date, int xDays) {
   
    for (short i = 1; i <= xDays; i++)
    {
   date= increaseDateByOneDay(date);
        
    }
    return date;
}
stDate increaseDateByOneWeek(stDate date) {

    for (short i = 1; i <= 7; i++)
    {
        date = increaseDateByOneDay(date);

    }
    return date;
}
stDate increaseDateByXWeeks(stDate date, short weeks) {

    for (short i = 1; i <= weeks; i++)
    {
        date = increaseDateByOneWeek(date);

    }
    return date;
}
stDate increaseDateByOneMonth(stDate date) {

    if (date.month==12)
    {
        date.month = 1;
        date.year++;

    }
    else
    {
        date.month++;
    }
    short numberOfDaysInCurrentMonth = numberOfDaysInAMonth(date.month, date.year);
    if (date.day>numberOfDaysInCurrentMonth)
    {
        date.day = numberOfDaysInCurrentMonth;
    }
    return date;
}
stDate increaseDateByXMonths(stDate date, int xMonths) {

    for (short i = 1; i <= xMonths; i++)
    {
        date = increaseDateByOneMonth(date);

    }
    return date;
}
stDate increaseDateByOneYear(stDate date) {
    date.year++;
    return date;
}
stDate increaseDateByXYears(stDate date,short xYears) {
    for (short i = 1; i <= xYears; i++)
    {
        date = increaseDateByOneYear(date);

    }
    return date;
}
stDate increaseDateByXYearsFaster(stDate date, short xYears) {
    date.year += xYears;
    return date;
}
stDate increaseDateByOneDecade(stDate date) {
    date.year += 10;
    return date;
}

stDate increaseDateByXDecades(stDate date, short xDecades) {
    for (short i = 1; i <= xDecades*10; i++)
    {
        date = increaseDateByOneYear(date);

    }
    return date;
}
stDate increaseDateByXDecadesFaster(stDate date, short xDecades) {
    date.year += xDecades*10;
    return date;
}
stDate increaseDateByOneCentury(stDate date) {
    date.year += 100;
    return date;
}
stDate increaseDateByOneMellinum(stDate date) {
    date.year += 1000;
    return date;
}
int main()
{
    stDate date = readFullDate();
    short xDays = 10,xWeeks = 10, xMonths = 5,xYears = 10, xDecades = 10;
    cout << "Date after: \n\n\n";
    date = increaseDateByOneDay(date);
    cout << "Adding one day is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByXDays(date,xDays);
    cout << "Adding "<< xDays <<" days is : " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByOneWeek(date);
    cout << "Adding one week is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByXWeeks(date, 7*xWeeks);
    cout << "Adding " << xWeeks << " weeks is : " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByOneMonth(date);
    cout << "Adding one month is: " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByXMonths(date, xMonths);
    cout << "Adding "<<xMonths<<" month is : " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByOneYear(date);
    cout << "Adding one year is : " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByXYears(date, xYears);
    cout << "Adding " << xYears << " years is : " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByXYearsFaster(date, xYears);
    cout << "Adding " << xYears << " years faster is : " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByOneDecade(date);
    cout << "Adding one Decade is : " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByXDecades(date, xDecades);
    cout << "Adding " << xDecades << " Decade is : " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByXDecadesFaster(date, xDecades);
    cout << "Adding " << xDecades << " Decade Faster is : " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByOneCentury(date);
    cout << "Adding one Century is : " << date.day << '/' << date.month << '/' << date.year << endl;
    date = increaseDateByOneMellinum(date);
    cout << "Adding one Mellinum is : " << date.day << '/' << date.month << '/' << date.year << endl;
   

    
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
