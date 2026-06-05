// join-string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string joinString(vector <string> &name,string separator =" ") {
	string s1;
	for (string& join : name) {
		s1 += join + separator;
	}
	return s1.substr(0, s1.length() - separator.length());
	
	
}
void printString(string join) {
	for (short i = 0; i < join.length(); i++)
	{
		cout << join[i];

	}
}
int main()
{
	vector <string> name = {"Huda", "Noon", "Hajar"};
	cout << "vectro after join: ";
	cout<<joinString(name, ",");
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
