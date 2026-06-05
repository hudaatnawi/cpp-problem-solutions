// add_days_to_date.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
struct stDate
{
	short day;
	short month;
	short year;


};
short readADay() {
	short day;
	cout << "Please enter a day? ";
	cin >> day;
	return day;
}
short readAMonth() {
	short month;
	cout << "Please enter a month? ";
	cin >> month;
	return month;
}
short readAYear() {
	short year;
	cout << "Please enter a year? ";
	cin >> year;
	return year;
}
stDate readFullDate() {
	stDate date;
	date.day = readADay();
	date.month = readAMonth();
	date.year = readAYear();
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
	short arrDaysOfMonth[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2 ? (isLeapYear(year) ? 29 : 28) : arrDaysOfMonth[month - 1]);
}
short numberOfDaysInAYear( short year) {
	return isLeapYear(year) ? 366 : 365;
	
}
int getNumberOfDaysFromTheBegginingOfTheYear(short day, short month, short year) {
	int totalDays = 0;
	
	for (short i = 1; i < month; i++)
	{
		totalDays += numberOfDaysInAMonth(i, year);

	}
	totalDays += day;
	return totalDays;
}
short addDaysToDate() {
	short daysAdded = 0;
	cout << "How many days to add? ";
	cin >> daysAdded;
	return daysAdded;
}
stDate getDateFromDayOrderInTheYear(short totalDays, short year) {
	stDate date;
	short remainingDays = totalDays;
	short monthDays = 0;
	date.year = year;
	date.month = 1;
	while (true) {
		monthDays = numberOfDaysInAMonth(date.month, year);
		if (totalDays>monthDays)
		{
			remainingDays -= monthDays;
			date.month++;

		}
		else
		{
			date.day = remainingDays;
			break;
		}
	}
	return date;

}
stDate getDateAfterAddingDays(stDate date, short daysAdded) {
	int remainingDays = daysAdded + getNumberOfDaysFromTheBegginingOfTheYear(date.day,date.month,date.year);
	short monthDays = 0;
	date.month = 1;
	while (true) {
		monthDays = numberOfDaysInAMonth(date.month,date.year);
		if (remainingDays>monthDays)
		{
			remainingDays -= monthDays;
			date.month++;
			if (date.month>12)
			{
				date.month = 1;
				date.year++;

			}


		}
		else
		{
			date.day = remainingDays;
			break;
		}
	}
	return date;

}
int main()
{
	
	stDate date = readFullDate();
	short daysAdded = addDaysToDate();
	date = getDateAfterAddingDays(date,daysAdded);
	cout << "\nDate after adding [" << daysAdded << "] days is: ";
	cout << date.day << "/" << date.month << "/" << date.year;
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
