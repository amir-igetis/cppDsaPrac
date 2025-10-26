#include <bits/stdc++.h>
using namespace std;

bool hasSameDigits(string s)
{
    while (s.length() > 2)
    {
        string next;
        for (int i = 0; i < s.length() - 1; i++)
        {
            int a = s[i] - '0';
            int b = s[i + 1] - '0';
            int sum = (a + b) % 10;
            next.push_back(sum + '0');
        }
        s = next;
    }
    return s[0] == s[1];
}

int main()
{

    string s = "3902"; 
    cout << (hasSameDigits(s) ? "True" : "False") << endl;

    return 0;
}