// year_calender.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
bool isLeapYear(short year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
short dayOfWeekOrder(int year, int month, int day) {
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	return ((day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7);
}
short numberOfDaysInAMonth(short month, short year) {
	if (month < 1 || month > 12)
	{
		return 0;

	}
	short days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	return (month == 2 ? (isLeapYear(year) ? 29 : 28) : days[month - 1]);
}
string monthShortName(short month) {
	string months[12] = { "Jan", "Feb", "Mar",
		"Apr", "May", "Jun",
		"Jul", "Aug", "Sep",
		"Oct", "Nov", "Dec"
	};
	return (months[month - 1]);

}
void printMonthCalender(short year , short month) {
	short numberOfDays = numberOfDaysInAMonth(month, year);
	short current = dayOfWeekOrder(year, month, 1);
	cout << "------------" << monthShortName(month) << "------------\n";
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");
	int i;
	for ( i = 0; i < current ; i++)
	{
		printf("    ");
	}
	for (short j = 1; j <= numberOfDays; j++)
	{
		printf("%4d", j);
		if (++i == 7)
		{
			i = 0;
			printf("\n");
			

		}

	}
	
}
void printYearCalender(short year) {
	cout << "---------------------------------------\n";
	cout << "------------" <<"Calender = " << year << "------------\n";
	cout << "---------------------------------------\n";

	for (short i = 1; i <= 12; i++)
	{
		printMonthCalender(year, i);
		cout << endl;

	}
}
int main()
{
	short year = readAYear();
	
	printYearCalender(year);
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
