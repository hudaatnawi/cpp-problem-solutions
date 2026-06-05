

#include <iostream>
using namespace std;
short readAYear() {
	short year;
	cout << "Please enter a year? ";
	cin >> year;
	return year;
}
short readAMonth() {
	short month;
	cout << "Please enter a month? ";
	cin >> month;
	return month;
}
short readADay() {
	short day;
	cout << "Please enter a day? ";
	cin >> day;
	return day;
}
bool isLeapYear(short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short numberOfDaysInAMonth(short month, short year) {
	if (month < 1 || month > 12)
	{
		return 0;

	}
	short days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2 ? (isLeapYear(year) ? 29 : 28) : days[month - 1]);
}


int calculateNumberOfDaysFromTheBegginingOfTheYear(short day, short month, short year) {
	int totalDays = 0;
	for (short i = 1; i < month; i++)
	{
		totalDays +=numberOfDaysInAMonth(i, year);
		
	}
	totalDays += day;
	return totalDays;
}
int main()
{
	int day = readADay();
	int month = readAMonth();
	int year = readAYear();
cout<<"Number of days from the beggining of the year is "<< calculateNumberOfDaysFromTheBegginingOfTheYear(day, month, year);

	
}

