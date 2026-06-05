// count-each-word-in-string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
string readString() {
    string words;
    cout << "Please enter your string: \n";
    getline( cin,words);
    return words;
}
int countEachNumberInString(string words) {
    string delim = " ";
    string sWord;
    short pos = 0;
    short counter = 0;
    while ((pos = words.find(delim))!=std::string::npos) {
        sWord = words.substr(0, pos);
        if (sWord !="")
        {
            counter++;

        }
        words.erase(0, pos + delim.length());
    }
    if (words != "")
    {
        counter++;

    }
        return counter;
}
int main()
{
   cout<<"The number of words in your string: "<< countEachNumberInString(readString());
    
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
