// count-letters-match-case.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

string readString() {
    string words;
    cout << "Please enter your string:\n";
    getline(cin, words);
    return words;
}
char readCharacter() {
    char alphabet;
    cout << "Please enter a character:\n";
    cin >> alphabet;
    return alphabet;
}
char invertLetterCase(char letter) {
    return (isupper(letter) ? tolower(letter) : toupper(letter));
}

int countLetters(char letter, string word,bool matchCase = true) {
    short counter = 0;
    for (short i = 0; i < word.length(); i++)
    {

        if (matchCase) {
            if (word[i] == letter)
                counter++;
        }
        else
        {
            if (tolower(word[i]) == tolower(letter)) {
                counter++;
            }
        }
    }
    return counter;
}
int main()
{
    string word = readString();
    char letter= readCharacter();
    cout << "Letter " << letter << " count = " << countLetters(letter,word) << endl;
    cout << "Letter " << letter << " or ";
    cout << invertLetterCase(letter) << " count = " << countLetters(letter,word,false);
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
