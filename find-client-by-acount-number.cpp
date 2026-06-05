// show-all-clients.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const string fileName = "Clients.txt";
struct stClientInfo {
    string acountNumber = "";
    string pinCode = "";
    string name = "";
    string phone = "";
    short balance = 0;
};
vector<string> splitString(string line, string separator) {
    short pos = 0;
    string newWord = "";
    vector<string> vString;
    while ((pos = line.find(separator)) != std::string::npos) {
        newWord = line.substr(0, pos);
        if (newWord != separator)
        {
            vString.push_back(newWord);

        }
        line.erase(0, pos + separator.length());
    }
    if (line != separator)
    {
        vString.push_back(line);

    }
    return vString;
}
string readClientAcountNumber(stClientInfo acountNumber) {
    cout << "Please enter acount number: ";
    cin >> acountNumber.acountNumber;
    return acountNumber.acountNumber;
}
stClientInfo convertLineToRecord(string line, stClientInfo clientInfo) {
    
    vector<string> vString = splitString(line,"#//#");
    clientInfo.acountNumber = vString[0];
    clientInfo.pinCode = vString[1];
    clientInfo.name = vString[2];
    clientInfo.phone = vString[3];
    to_string(clientInfo.balance) = vString[4];
    return clientInfo;

}
vector<stClientInfo> loadClientsInfoFromFile(string myFile, vector<stClientInfo> vClients) {
    fstream clients;
    
    stClientInfo clientInfo;
    clients.open(myFile, ios::in);
 
    if(clients.is_open()){
        string line;
        stClientInfo info;
        while (getline(clients,line)) {
            info = convertLineToRecord(line,clientInfo);
            vClients.push_back(info);
        }
    }clients.close();
    return vClients;
}
bool isClientAcountNumber(stClientInfo& info, string acountNumber) {
    vector<stClientInfo> vClients;
    vector<stClientInfo> clientsInfo = loadClientsInfoFromFile(fileName, vClients);
    for (stClientInfo& client : clientsInfo) {
        if (client.acountNumber==acountNumber)
        {
            info = client;
            return true;

        }
    }
    return false;
}
void printClientCard(stClientInfo info) {
    cout << "The following are the client details: \n\n";
    cout << "Acount number : " << info.acountNumber << endl;
    cout << "Pin code : " << info.pinCode << endl;
    cout << "Name : " << info.name << endl;
    cout << "Phone number : " << info.phone << endl;
    cout << "Acount Balance : " << info.balance << endl;
}
int main()
{
    stClientInfo info;
    string acountNumber = readClientAcountNumber(info);
    if (isClientAcountNumber(info,acountNumber))
    {
        printClientCard(info);

    }
    else { cout << "Client with acount number " << acountNumber << " not found\n"; }
   

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
