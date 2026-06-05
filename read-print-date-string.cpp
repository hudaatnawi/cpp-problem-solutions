// read-print-date-string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct stDate
{
    short day = 0;
    short month = 0;
    short year = 0;

};
string readDateString() {
    string date; 
    cout << "Please Enter Date dd/mm/yyyy? ";
    cin >> date;
    return date;
}
vector<string> splitString(string sDate) {
    string delim = "/";
    short pos = 0;
    string wDate;
    vector<string> vString;
    while ((pos = sDate.find(delim)) != std::string::npos) {
        wDate = sDate.substr(0,pos);
        if (wDate!="")
        {
            vString.push_back(wDate);


        }
        sDate.erase(0, pos + delim.length());
    }
    if (sDate!="")
    {
        vString.push_back(sDate);

    }
    return vString;
}
stDate stringToDate(string sDate) {
    stDate date;
    vector<string> vString = splitString(sDate);
    date.day = stoi(vString[0]);
    date.month = stoi(vString[1]);
    date.year = stoi(vString[2]);
    return date;
}
string dateToString(stDate date) {
    string sDate = to_string(date.day) + "/";
    sDate += to_string(date.month) + "/";
    sDate += to_string(date.year) ;
    return sDate;


}
int main()
{
    string sDate = readDateString();
    stDate date = stringToDate(sDate);
    cout << "Day: " << date.day << endl;
    cout << "Month: " << date.month << endl;
    cout << "Year: " << date.year << endl<<endl;
    cout << "You Entered: " << dateToString(date);

    
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
