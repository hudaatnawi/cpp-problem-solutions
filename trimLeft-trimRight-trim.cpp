// trimLeft-trimRight-trim.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
string readString() {
    string words;
    cout << "Please enter your string: \n";
    getline(cin, words);
    return words;
}
string trimLeft(string words) {
    for (short i = 0; i < words.length(); i++)
    {
        if (words[i] != ' ') {
            return words.substr(i, words.length() - 1);
        }
    }
    return "";
}
string trimRight(string words) {
    for (short i = words.length()-1; i >= 0; i--)
    {
        if (words[i]!=' ') {
            return words.substr(0,i+1);
    }

    }
    return "";
}
string trim(string words) {
    return trimLeft(trimRight(words));
}
int main()
{
    string words = "                 hi                  ";
    cout << words << endl;
    cout <<"trim left : " << trimLeft(words) << endl;
    cout << "trim right : " << trimRight(words) << endl;
    cout << "trim : " << trim(words);
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
