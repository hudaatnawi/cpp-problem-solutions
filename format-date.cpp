// read-print-date-string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct stDate
{
    short day ;
    short month ;
    short year ;

};
string readDateString() {
    string date;
    cout << "Please Enter Date dd/mm/yyyy? ";
    cin >> date;
    cout << endl << endl;
    return date;
}
vector<string> splitString(string sDate) {
    string delim = "/";
    short pos = 0;
    string wDate;
    vector<string> vString;
    while ((pos = sDate.find(delim)) != std::string::npos) {
        wDate = sDate.substr(0, pos);
        if (wDate != "")
        {
            vString.push_back(wDate);


        }
        sDate.erase(0, pos + delim.length());
    }
    if (sDate != "")
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

string replaceWordInString(string theString , string wordToReplace ,string replaceTo) {
    short pos = theString.find(wordToReplace);
    while (pos!=std::string::npos) {
        theString = theString.replace(pos, wordToReplace.length(),replaceTo);
        pos = theString.find(wordToReplace);
    }
    return theString;
}
string formateDate(stDate Date, string DateFormat = "dd/mm/yyyy")
{
    string FormattedDateString = "";
    FormattedDateString = replaceWordInString(DateFormat, "dd",
        to_string(Date.day));
    FormattedDateString = replaceWordInString(FormattedDateString,
        "mm", to_string(Date.month));
    FormattedDateString = replaceWordInString(FormattedDateString,
        "yyyy", to_string(Date.year));
    return FormattedDateString;
}
int main()
{
    string sDate = readDateString();
    stDate Date = stringToDate(sDate);
    cout << "\n" << formateDate(Date) << "\n";
    cout << "\n" << formateDate(Date, "yyyy/dd/mm") << "\n";
    cout << "\n" << formateDate(Date, "mm/dd/yyyy") << "\n";
    cout << "\n" << formateDate(Date, "mm-dd-yyyy") << "\n";
    cout << "\n" << formateDate(Date, "dd-mm-yyyy") << "\n";
    cout << "\n" << formateDate(Date, "Day:dd, Month:mm,  Year:yyyy") << "\n";

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
