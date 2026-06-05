// count-overlap-days.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enDateCompare { Before = -1, Equal = 0, After = 1 };
struct stDate
{
	short day;
	short month;
	short year;

};
struct stPeriod
{
	stDate startDate;
	stDate endDate;

};
stDate readFullDate() {
	stDate date;
	cout << "Please Enter A Day? ";
	cin >> date.day;
	cout << "Please Enter A Month? ";
	cin >> date.month;
	cout << "Please Enter A Year? ";
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
bool isDate1BeforeDate2(stDate date1 ,stDate date2) {
	return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month?date1.day<date2.day:false)) : false);
}
bool isDate1EqualToDate2(stDate date1, stDate date2) {
	return (date1.year == date2.year) ? ((date1.month == date2.month) ? ((date1.day == date2.day) ? true : false) : false) : false;
}
bool isDate1AfterDate2(stDate date1, stDate date2) {
	return (!isDate1BeforeDate2(date1, date2) && !isDate1EqualToDate2(date1, date2));
		
}
bool isLeapYear(short Year)
{
	return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}
short numberOfDaysInAMonth(short month, short year)
{
	if (month < 1 || month>12)
		return 0;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2) ? (isLeapYear(year) ? 29 : 28) :
		days[month - 1];
}
bool isLastDayInMonth(stDate date)
{
	return (date.day == numberOfDaysInAMonth(date.month,
		date.year));
}
bool isLastMonthInYear(short month)
{
	return (month == 12);
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
			date.month ++;
			date.day = 1;
		}

	}
	else
	{

		date.day++;

	}
	return date;
}
int GetDifferenceInDays(stDate Date1, stDate Date2, bool
	IncludeEndDay = false)
{
	int Days = 0;
	while (isDate1BeforeDate2(Date1, Date2))
	{
		Days++;
		Date1 = increaseDateByOneDay(Date1);
	}
	return IncludeEndDay ? ++Days : Days;
}
enDateCompare compareDates(stDate Date1, stDate Date2)
{
	if (isDate1BeforeDate2(Date1, Date2))
		return enDateCompare::Before;
	if (isDate1EqualToDate2(Date1, Date2))
		return enDateCompare::Equal;
	/* if (IsDate1AfterDate2(Date1,Date2))
	return enDateCompare::After;*/
	//this is faster
	return enDateCompare::After;
}
int periodLengthInDays(stPeriod Period, bool IncludeEndDate =
	false)
{
	return GetDifferenceInDays(Period.startDate, Period.endDate,
		IncludeEndDate);
}

bool isOverlapPeriods(stPeriod period1, stPeriod period2) {
	if (compareDates(period2.endDate,period1.startDate)==Before||compareDates(period2.startDate,period1.endDate)==After)
		return false;
	return true;
}
bool isDateInPeriod(stDate date , stPeriod period) {
	return !(compareDates(date, period.startDate) == Before || compareDates(date, period.endDate) == After);
}
int countOverLapDays(stPeriod period1, stPeriod period2) {
	int period1Length = periodLengthInDays(period1,true);
	int period2Length = periodLengthInDays(period2,true);
	int overlapDays = 0;
	if (!isOverlapPeriods(period1, period2))
		return 0;
	if (period1Length<period2Length)
	{
		while (isDate1BeforeDate2(period1.startDate,period1.endDate)) {
			if (isDateInPeriod(period1.startDate,period2))
			
				overlapDays++;
				period1.startDate = increaseDateByOneDay(period1.startDate);
			
	}

	}
	else
	{
		while (isDate1BeforeDate2(period2.startDate, period2.endDate)) {
			if (isDateInPeriod(period2.startDate, period1))
			{
				overlapDays++;
				period2.startDate = increaseDateByOneDay(period2.startDate);
			}
		}

	}
	return overlapDays;

}
int main()
{
	cout << "Enter Period1 : \n";
	stPeriod period1 = readPeriod();
	cout << "Enter Period2 : \n";
	stPeriod period2 = readPeriod();
	
	cout<<"OverLap Days Count Is: "<< countOverLapDays(period1, period2);
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
