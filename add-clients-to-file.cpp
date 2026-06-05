// add-clients-to-file.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
struct stClientInof
{
	string acountNumber = "";
	string pinCode = "";
	string name = "";
	string phone = "";
	short acountBalance = 0;


};
stClientInof readClientInfo() {
	stClientInof info;
	cout << "Enter Acount Number : ";
	cin >> info.acountNumber;
	cout << "Enter PinCode : ";
	cin >> info.pinCode;
	cout << "Enter Name : ";
	cin >> info.name;
	cout << "Enter PhoneNumber : ";
	cin >> info.phone;
	cout << "Enter AcountBalance : ";
	cin >> info.acountBalance;
	return info;
}
string convertDataToString(string separator , stClientInof info) {
	string oneLineString = "";
	oneLineString += info.acountNumber + separator;
	oneLineString += info.pinCode + separator;
	oneLineString += info.name + separator;
	oneLineString += info.phone + separator;
	oneLineString += to_string(info.acountBalance) ;
	return oneLineString;


}
void printDataToFile(string data) {
	fstream myFile;
	myFile.open("My File.txt", ios::app);
	if (myFile.is_open())
	{
		myFile << data << endl;

	}myFile.close();
}
void addClient() {
	char addMoreClients = 'y';
	stClientInof info;
	do
	{
		cout << "Adding new client: \n";
	    printDataToFile(convertDataToString("#//#", readClientInfo())) ;
		cout << "Client added successfully, do you want to add more clients? ";
		cin >> addMoreClients;
		system("cls");

	} while (addMoreClients == 'y'||addMoreClients=='Y');
}
int main()
{
	addClient();
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
