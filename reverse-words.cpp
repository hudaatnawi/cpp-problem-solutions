// reverse-words.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
string readString() {
    string words;
    cout << "Please enter your string\n";
    getline(cin, words);
    return words;
}
vector<string> splitString(string words) {
    short pos = 0;
    string delim = " ";
    string word;
    vector<string> vString;
    while ((pos = words.find(delim))!=std::string::npos) {
        word = words.substr(0, pos);
        if (word!="")
        {
            vString.push_back(word);

        }
        words.erase(0, pos + delim.length());
  }
    if (words!="")
    {
        vString.push_back(words);
    }
    return vString;
}
string reversWordsInString(string word) {
    vector<string> vString;
    vString = splitString(word);
    string s2;
    vector<string>::iterator itr = vString.end();
    while (itr != vString.begin()) {
        itr--;
        s2 += *itr + ' ';
        
    }
  s2= s2.substr(0, s2.length() - 1);
  return s2;
   
}
int main()
{
    string word = readString();
    cout << "string after reversed: \n";
  cout<<  reversWordsInString(word);
    
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
