
#include <iostream>
using namespace std;
struct stDate
{
    short day;
    short month;
    short year;
};
struct stPeriod
{ stDate startDate , endDate;
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
    period.startDate=readFullDate();
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
enDateCompare compareDates(stDate date1, stDate date2) {
    if (isDate1BeforeDate2(date1,date2))
        return Before;
    else if (isDate1AfterDate2(date1, date2))
        return After;
    else
    return Equal;
}
bool isOverlapPeriods(stPeriod period1, stPeriod period2) {
    if ((compareDates(period2.endDate, period1.startDate) == Before) || (compareDates(period2.startDate, period1.endDate) == After))
        return false;
    else
    return true;
}
int main()
{
    stPeriod period1 , period2;
    cout << "Enter Period1: \n";
    period1 = readPeriod();
    cout << "Enter Period2: \n";
    period2 = readPeriod(); 
    if (isOverlapPeriods(period1, period2))
    {
        cout << "Yes , Periods  overLap\n";
    }
    else
    {
        cout << "No , Periods  not overLap\n";

    }
}

