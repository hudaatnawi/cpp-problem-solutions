// day_name.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
short dayOfWeekOrder(int year, int month, int day) {
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    return ((day + y + (y / 4) - (y / 100) + (y / 400) + (31 * m / 12)) % 7);
}
string dayName(short number) {
    string nameOfDay[] = { "Sunday","Monday","Tuesday" ,"Wednesday" ,"Thursday" ,"Friday" ,"Saturday" };
   
  return  nameOfDay[number];
}
int readAYear() {
    int year;
    cout << "Please enter a year? ";
    cin >> year;
    return year;

}
int readAMonth() {
    int month;
    cout << "Please enter a month? ";
    cin >> month;
    return month;

}
int readADay() {
    int day;
    cout << "Please enter a day? ";
    cin >> day;
    return day;

}
int main()
{
    int year = readAYear();
    int month = readAMonth();
    int day = readADay();
    cout << "Date:\t\t\t" << day << '/' << month << '/' << year << endl;
    cout << "Day of week order:\t" << dayOfWeekOrder(year, month, day) << endl;
    cout << "Day Name:\t\t" << dayName(dayOfWeekOrder(year, month, day)) << endl;
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
