// joinString_vector_array.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string joinString(vector<string> vString, string delim) {
    string s1 = "";
	for (string& join : vString)
	{
		s1 += join + delim;

	}
	return s1.substr(0, s1.length() - delim.length());
}
string joinString(string arrString[], short Length, string Delim)
{
	string S1 = "";
	for (short i = 0; i < Length; i++)
	{
		S1 = S1 + arrString[i] + Delim;
	}
	return S1.substr(0, S1.length() - Delim.length());

}
int main()
{
	vector <string> vString = { "Huda","Noon","Hajar" };
	string arrString[] = { "Huda", "Noon","Hajar"};
	cout << "Vector after join: " << joinString(vString, ",") << endl;
	cout << "Array after join : " << joinString(arrString,3,"/") << endl;
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
