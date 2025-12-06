// problem#17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
string readPassword(string message) {
	string password;
	
		cout << message << endl;
		cin >> password;

	
	return password;
}
bool gussPassword(string password) {
	string word = "";
	int trail = 0;
	for (int i = 65; i <= 90; i++)
	{
		for (int j = 65; j <= 90; j++)
		{
			for (int k = 65; k <= 90; k++)
			{
				word = word + char(i);
				word = word + char(j);
				word = word + char(k);
				trail++;
				if (word == password) {
					cout << "Password is " << password << endl;
					cout << "After " << trail << " Trails " << endl;
					return true;
				}
				word = "";

			}
			cout << endl;
		}

	}
	return false;
}
int main()
{
	gussPassword(readPassword("Enter capital letters:"));
		
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
