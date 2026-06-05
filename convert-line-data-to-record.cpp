// convert-line-data-to-record.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct stClientData
{
    string acountNumber = "";
    string pinCode = "";
    string clientName = "";
    string phone = "";
    short acountBalance = 0;

};
vector<string> splitString(string lineData, string separator) {
    short pos = 0;
    string newWords;
    vector<string> vString;
    while ((pos = lineData.find(separator))!=std::string::npos) {
        newWords = lineData.substr(0, pos);
        if (newWords!=separator)
        {
            vString.push_back(newWords);

        }
        lineData.erase(0, pos + separator.length());
    }
    if (lineData!=separator)
    {
        vString.push_back(lineData);
    }
    return vString;
}
stClientData turnToStructure(vector<string> vString) {
    stClientData data;
    data.acountNumber = vString[0];
   data.pinCode = vString[1];
    data.clientName = vString[2];
    data.phone = vString[3];
   to_string (data.acountBalance) = vString[4];
   return data;
}
void printFinalResult(stClientData data) {
    cout << "The following is the extracted client record: \n";
    cout << data.acountNumber << endl;
    cout << data.pinCode << endl;
    cout << data.clientName << endl;
    cout << data.phone << endl;
    cout << data.acountBalance << endl;
}
int main()
{
    printFinalResult(turnToStructure(splitString("A150#//#1234#//#huda#//#7999#//#54", "#//#")));
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
