// convert record to line.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
struct stBankInfo
{
    string acountNumber ;
    string pinCode ;
    string name = "";
    string phone ;
    short acountBalance = 0;

};
stBankInfo enterBandInfo(stBankInfo bankInfo) {
    cout << "Enter your acount number: \n";
    cin >> bankInfo.acountNumber;
    cout << "Enter your pincode: \n";
    cin >> bankInfo.pinCode;
    cout << "Enter your name: \n";
    cin >> bankInfo.name;
    cout << "Enter your phone number: \n";
    cin >> bankInfo.phone;
    cout << "Enter your acount balance: \n";
    cin >> bankInfo.acountBalance;
    return bankInfo;

}
string turningStructInfoToOneLine(stBankInfo bankInfo,string delim) {
    string s = "";
    s += to_string(bankInfo.acountBalance) + delim;
    s += bankInfo.pinCode + delim;
    s += bankInfo.name + delim;
    s += bankInfo.phone + delim;
    s += bankInfo.acountNumber;
    return s;
}
int main()
{
    stBankInfo bank;
   cout<< turningStructInfoToOneLine(enterBandInfo(bank),"#//#");
   
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
