#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isStringPalindrome(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start <= end)
    {
        if (!isalnum(s.at(start)))
        {
            start++;
            continue;
        }
        if (!isalnum(s.at(end)))
        {
            end--;
            continue;
        }
        if (s.at(start) != s.at(end))
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}

int main()
{
    // string s = "Am1 ,0A0, 1mA";
    string s = "rac  a car";
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    cout << isStringPalindrome(s) << endl;
}