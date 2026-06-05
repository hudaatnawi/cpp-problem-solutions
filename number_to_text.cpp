// number_to_text.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

int readNumber() {
    int number;
    cout << "Enter a number? ";
    cin >> number;
    return number;
}
string numberToText(int number) {
    if (number ==0)
    {
        return "";
    }
    if (number>=1&&number<=19)
    {
        string arr[] = { "",
   "One","Two","Three","Four","Five","Six","Seven",
   "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
   "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };
        return arr[number];
    }
    if (number >= 20 && number <= 99)
    {
        string arr[] = {
  "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty"
  ,"Ninety" };
        return arr[number / 10] + " " + numberToText(number % 10);;
    }
    if (number >= 100 && number <= 199)
    {
        return "One Hundred " + numberToText(number%100);

    }
    if (number >= 200 && number <= 999)
    {
        return numberToText(number / 100) + " Hundreds " + numberToText(number % 100);

    }
    if (number >= 1000 && number <= 1999)
    {
        return "One Thousand " + numberToText(number % 1000);

    }
    if (number >= 2000 && number <= 999999)
    {

        return numberToText(number / 1000) + " Thousands " + numberToText(number % 1000);

    }
}
int main()
{
    int number = readNumber();
    cout << numberToText(number);
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
