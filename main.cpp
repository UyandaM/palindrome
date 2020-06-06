#include <iostream>
#include <fstream>

using namespace std;

string removeSpacesAndPunctuation(string str);
string convertToLowerCase(string str);
bool isPalindrome(string str);

int main()
{
    ifstream inputfile("input.txt");
    string str;
    bool checkifpalindrome;

    while(getline(inputfile,str))
    {
        str = removeSpacesAndPunctuation(str);
        str = convertToLowerCase(str);
        cout << str << "\t";

        checkifpalindrome = isPalindrome(str);

        if (checkifpalindrome)
            cout << "is a palindrome" << endl;
        else
            cout << "is not a palindrome" << endl;

    }
    return 0;
}

string removeSpacesAndPunctuation(string str)
{
    string myString = "";

    for(int i = 0; i < str.size(); i++)
    {
        if (ispunct(str.at(i)) == false && isspace(str.at(i)) == false)
            myString = myString + str.at(i);
    }

    return myString;
}

string convertToLowerCase(string str)
{
    for(int i = 0; i < str.size(); i++)
    {
        str.at(i) = tolower(str.at(i));
    }
    return str;
}

bool isPalindrome(string str)
{

    for (int i = 0; i < str.size()/2; i++)
    {
        if (str.at(i) != str.at(str.size() - 1 - i))
            return false;
    }
    return true;
}

