#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;
const string ClientsFileName = "Clients.txt";
struct sClient
{
	string AccountNumber;
	string PinCode;
	string Name;
	string Phone;
	double AccountBalance;
	bool MarkForDelete = false;
};
vector<string> splitString(string line, string separator = "#//#") {
	short pos = 0;
	string word;
	vector<string> vString;

	while ((pos = line.find(separator)) != std::string::npos) {
		word = line.substr(0, pos);
		if (word != " ")
		{
			vString.push_back(word);

		}
		line.erase(0, pos + separator.length());

	}
	if (line!=" ")
	{
		vString.push_back(line);
	}
	return vString;
}
sClient turnLineToRecord(string line) {
	sClient client;
	vector<string> vString;
	vString = splitString(line);
	client.AccountNumber = vString[0];
	client.PinCode = vString[1];
	client.Name = vString[2];
	client.Phone = vString[3];
	client.AccountBalance = stod(vString[4]);
	return client;


	
}
vector <sClient> laodClientDataFromFile(string fileName) {
	fstream clientFile;
	vector <sClient> vClients;
	clientFile.open(fileName, ios::in);
	if (clientFile.is_open())
	{
		string line;
		sClient client;
		while (getline(clientFile, line))
		{
			client = turnLineToRecord(line);
			vClients.push_back(client);

		}
		clientFile.close();

	}
	return vClients;

}
string readAcountNumber() {
	string acountNumber;
	do
	{
		cout << "Please Enter acount Number: ";
		cin >> acountNumber;

	} while (acountNumber ==" ");
	return acountNumber;

}
void printClientRecord(sClient client) {
	cout << "The following are the client details: \n";
	cout << "Acount Number: " << client.AccountNumber << endl;
	cout << "Pin Code: " << client.PinCode << endl;
	cout << " Name: " << client.Name << endl;
	cout << "Phone: " << client.Phone << endl;
	cout << "Acount Balance: " << to_string(client.AccountBalance) << endl;

}
bool findClientByAcountNumber(vector <sClient>& vClients, string acountNumber, sClient& nClient) {
	for (sClient client : vClients) {
		if (client.AccountNumber == acountNumber)
		{
			nClient = client;
			return true;


		}
	}
	return false;
}
bool markClientForDeleteByAccountNumber(string AccountNumber,
	vector <sClient>& vClients)
{
	for (sClient& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}
	}
	return false;
}
string convertRecordToLine(sClient client) {
	string line;
	line = client.AccountNumber + "#//#";
	line+=client.PinCode + "#//#";
	line += client.Name + "#//#";
	line += client.Phone + "#//#";
	line += to_string(client.AccountBalance) ;

	return line;
}

vector< sClient> saveClientDataToFile(string fileName , sClient client, vector< sClient> vClient){
	fstream myFile;
	myFile.open(fileName,ios::out);
	if (myFile.is_open())
	{
		string dataLine;
		for (sClient& client:vClient) {
			if (client.MarkForDelete==false)
			{
				dataLine = convertRecordToLine(client);
				myFile << dataLine << endl;
			}
		}
		myFile.close();
	}
	return vClient;
	}

bool deleteClientByAcountNumber(vector <sClient>& vClients, string acountNumber) {
	sClient client;
	char deleteClient='y';
	if (findClientByAcountNumber(vClients, acountNumber, client))
	{
		printClientRecord(client);
		cout << "Are you sure you want to delete this client info? ";
		cin >> deleteClient;
		if (deleteClient == 'y' || deleteClient == 'Y')
		{
			markClientForDeleteByAccountNumber(acountNumber,vClients);
			saveClientDataToFile(ClientsFileName, client, vClients);
			vClients = laodClientDataFromFile(ClientsFileName);
			cout << "\n\nClient Deleted Successfully.";
			return true;

		}


	}
	else
	{
		cout << "\nClient with Account Number (" << acountNumber
			<< ") is Not Found!";
		return false;
	}
}
int main()
{
	vector <sClient> vClients = laodClientDataFromFile(ClientsFileName);
	string acountNumber = readAcountNumber();
	deleteClientByAcountNumber(vClients, acountNumber);
	
	return 0;
}