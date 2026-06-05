// period-length-in-days.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
    stDate startDate , endDate;
};
stDate readFullDate() {
    stDate date; 
    cout << "Please Enter a Day? ";
    cin >> date.day;
    cout << "Please Enter a Month? ";
    cin >> date.month;
    cout << "Please Enter a Year? ";
    cin >> date.year;
    cout << endl << endl;
    return date;
}
stPeriod readPeriod() {
    stPeriod period;
    cout << "Enter Start Date:\n\n ";
   period.startDate= readFullDate();
   cout << endl << endl;
   cout << "Enter End Date:\n\n ";
   period.endDate = readFullDate();
   cout << endl << endl;
   return period;


}
bool isLeapYear(short year) {
    return (year % 4 == 0 && year % 100 !=0) || (year % 400 == 0);
}
short numberOfDaysInMonth(short month, short year) {
    if (month<1 || month>12)
    {
        return 0;
    }
    short arrDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    return (month == 2 ? (isLeapYear(year) ? 29 : 28) : arrDays[month - 1]);
}
bool isLastMonthInYear(short month) {
    return month == 12;
}
bool isLastDayInMonth(stDate date) {
    return (date.day == numberOfDaysInMonth(date.month, date.year));
}
stDate increaseDateByOneDay(stDate date) {
    if (isLastDayInMonth(date))
    {
        if (isLastMonthInYear(date.month)) {
            date.day = 1;
            date.month = 1;
            date.year++;
        }
        else
        {
            date.day = 1;
            date.month++;
           
        }
    }
    else
    {
        date.day++;
    }
    return date;
}
bool isDate1BeforeDate2(stDate date1, stDate date2) {
    return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}
short compareBetweenTwoDates(stPeriod period1, bool currentDay ) {
    short days = 0;
    while (isDate1BeforeDate2(period1.startDate, period1.endDate)) {
        days++;
        period1.startDate= increaseDateByOneDay(period1.startDate);
    }
    return (currentDay == true ? ++days : days);
}
short periodLength(stPeriod period1, bool currentDay = false) {
    return compareBetweenTwoDates( period1,  currentDay );
}
int main()
{
    stPeriod period1 = readPeriod();
    cout << "Period length is: " << periodLength(period1)<<endl;
    cout<< "Period length (Including End Date): "<< periodLength(period1,true);
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
