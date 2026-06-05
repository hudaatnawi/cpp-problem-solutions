// split-string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string readString() {
    string words;
    cout << "Please enter your string: \n";
    getline(cin, words);
    return words;
}
vector<string> split(string words, string delim = " ") {
    string sWord;
    short pos = 0;
    vector<string> vWrod;
    while ((pos = words.find(delim)) != std::string::npos) {
        sWord = words.substr(0, pos);
        if (sWord!="")
        {
            vWrod.push_back(sWord);
        }
        words.erase(0, pos + delim.length());
    }
    if (words!="")
    {
        vWrod.push_back(words);

    }
    return vWrod;
}
void printEachWordInString(vector<string> vSingleWord) {
    for (string& phrase : vSingleWord) {
        cout << phrase << endl;
    }
}
int main()
{
    vector <string> tokens = split(readString());
    cout << "Number of tokens " << tokens.size() << endl;
    printEachWordInString(tokens);
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
