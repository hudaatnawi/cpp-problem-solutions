// last-day-last-month.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	return date;
}
bool isLeapYear(short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short daysInAMonth(short month, short year) {
	if (month < 1 || month > 12)
	{
		return 0;
	}
	short arrDaysInMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return month == 2 ? (isLeapYear(year) ? 29 : 28) : arrDaysInMonth[month - 1];
}
bool isLastDay(stDate date) {
	return (date.day == daysInAMonth(date.month, date.year));
}
bool isLastMonth(short month) {
	return month == 12;
}
stDate increaseDateByOneDay(stDate date) {
	if (isLastDay(date))
	{
		if (isLastMonth(date.month)) {
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
int main()
{
	stDate date = readFullDate();
	date =increaseDateByOneDay(date);
cout << "Date after adding one day is:" << date.day << '/' << date.month << '/' << date.year;


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
