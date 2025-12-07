// problem#33.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int readPositiveNumber(string message) {
	int number;
	do
	{
		cout << message << endl;
		cin >> number;

	} while (number<0);
	return number;
}
int RandomNumber(int from, int to) {
	int randNumber = rand() % (to - from + 1) + from;
	return randNumber;
}
string generateRandomWord(int from,int to ,int wordLength) {
	string word;
	for (int i = 0; i < wordLength; i++)
	{
		word += RandomNumber(from,to);

	}
	return word;
}
string generateRandomKey(int from, int to, int wordLength) {
	string key = generateRandomWord(from, to, wordLength) + '-';
	key = key+ generateRandomWord(from, to, wordLength) + '-';
	key = key + generateRandomWord(from, to, wordLength) + '-';
	key = key + generateRandomWord(from, to, wordLength) ;
	return key;
}
void fillArrayWithRandomKeys(string arr[100], int& arrLength) {
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = generateRandomKey(65, 90, 4);

	}
}
void printArrayWithRandomKeys(string arr[100], int& arrLength) {
	for (int i = 0; i < arrLength; i++)
	{cout<<"Array["<<i<<"]"<<':'<< arr[i];
	cout << endl;
		

	}
}


int main()
{
	srand((unsigned)time(NULL));
	string arr[100];
	int arrLength = readPositiveNumber("Enter the number of arrays:");
	fillArrayWithRandomKeys(arr, arrLength);
	printArrayWithRandomKeys(arr, arrLength);



}

