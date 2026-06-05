// replace words custom.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;
string lowerAllLetters(string letter) {
	string lowerLetter;
	for (short i = 0; i < letter.length(); i++)
	{
		lowerLetter += tolower(letter[i]);
	}
	return lowerLetter;
}
vector<string> splitWordsInString(string words) {
	short pos = 0;
	string sWords;
	string delim = " ";
	vector<string> vWords;
	while ((pos = words.find(delim)) != std::string::npos) {
		sWords = words.substr(0, pos);
		if (sWords!="")
		{
			vWords.push_back(sWords);
		}
		words.erase(0, pos + delim.length());
	}
	if (words!="")
	{
		vWords.push_back(sWords);

	}
	return vWords;
}
string joinString(vector<string> s) {
	string words;
	for (short i = 0; i < s.size(); i++)
	{
		words += s[i]+' ';

	}
	return words.substr(0, words.length() - 1);
}
string replaceWordUsingSplitFunction(string words,string toReplace, string toReplaceWith, bool match = true) {
	vector<string> vString = splitWordsInString(words);
	for (string& s : vString) {
		if (match)
		{

			if (s == toReplace)
			{
				s = toReplaceWith;
			}
		}

		else
		{

			if (lowerAllLetters(s) == lowerAllLetters(toReplace))
			{
				s = toReplaceWith;
			}


		}
		
	}
	return joinString(vString);
}
int main()
{
	string word = "Hello my name is huda , huda from syr ";
	cout << word << endl;
	cout<<"Repalce words in string with matchcase \n"<<replaceWordUsingSplitFunction(word, "Huda", "hajar")<<endl;
	cout << "Repalce words in string with no matchcase \n" << replaceWordUsingSplitFunction(word, "Huda", "hajar",false) << endl;


}

