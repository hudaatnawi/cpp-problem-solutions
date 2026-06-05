// calculate-vacation-return-date.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
bool isWeekEnd(stDate date) {
    short currentDate = dayOfWeekOrder(date);
    return (currentDate == 5 || currentDate == 6);
}
bool isBusinessDay(stDate date) {
    
    return !isWeekEnd(date);
}
stDate calculateVacationReturnDate(stDate startVacation, short vacationDays) {
    while (vacationDays!=0) {
        if (isBusinessDay(startVacation))
        {
            vacationDays--;
            startVacation = increaseDateByOneDay(startVacation);

        }
        else
        {
            startVacation = increaseDateByOneDay(startVacation);


        }
}
    return startVacation;
}
int main()
{
    cout << "Vacation Starts: \n";
    stDate startVacation = readFullDate();
    stDate endDate;
    short vacationDays;
    cout << "Please Enter Vacation Days? ";
    cin >> vacationDays;
    endDate = calculateVacationReturnDate(startVacation, vacationDays);
    cout << "Return Date: " << dayName(dayOfWeekOrder(endDate)) <<' ' << endDate.day << '/' << endDate.month << '/' << endDate.year << endl;
    
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
