// your_age_in_days.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	return (date.day == numberOfDaysInAMonth(date.month, date.year));
}
bool isLastMonthInYear(short month) {
	return (month == 12);
}
stDate increaseDateByOneDay(stDate date) {
	if (isLastDayInMonth(date))
	{
		if (isLastMonthInYear(date.month))
		{
			date.year++;
			date.month = 1;
			date.day = 1;

		}
		else {
			date.month++;
			date.day = 1;
		}

	}
	else {
		date.day++;
	}
	return date;
}
bool isDate1BeforeDate2(stDate date1, stDate date2) {
	return (date1.year < date2.year) ? true : ((date1.year == date2.year) ? (date1.month < date2.month ? true : (date1.month == date2.month ? date1.day < date2.day : false)) : false);
}
short calculateDiffInDays(stDate date1, stDate date2, bool
	includeEndDay = false) {
	int days = 0;
	while (isDate1BeforeDate2(date1, date2)) {
		days++;
		date1 = increaseDateByOneDay(date1);
	}
	return includeEndDay ? ++days : days;
}
stDate getSystemDate() {
	stDate date;
	time_t t = time(0);
	tm* now = localtime(&t);
	date.year = now->tm_year + 1900;
	date.month = now->tm_mon + 1;
	date.day = now->tm_mday;
	return date;
}
int main()
{
	cout << "Please enter your date of birth? \n";
	stDate date1 = readFullDate();
	stDate date2 = getSystemDate();

	cout << "Your age is: " << calculateDiffInDays(date1,date2);

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
